//This file contains user related bussiness logic functions(Tier - 2).

#include<stdio.h>
#include<string.h>
#include"user_dal.h"
#include"user_service.h"

//validate user and return respective user data in *u.
int user_authenticate(char *email, char *password, user_t *u){
    int found = 0;
    
    //comapares given email and password in db.
    if(user_find_by_email(email, u) == 1){
        if(strcmp(u->password,password) == 0){
            found = 1;
        }
    }
    else{
        found = 0;
    }

    if(!found){
        return 0;
    }
    else{
        return 1;
    }
}

int owner_register(user_t *u){
    u->id = 1;
    u->role = owner;
    
    remove(USERS_FILE);
    if(user_save(u) == 1){
        return 1;
    }
    else{
        return 0;
    }

}


int member_register(user_t *u){
    user_t new_member;
    u->id = get_max_id() + 1;
    u->role = member;

    if(user_find_by_email(u->email, &new_member) == 1){
        return 2;   // if found cannot register with same email. 
    }
    else{
        if(user_save(u) == 1){
            return 1;   // member registered successfully.
        }
        else{
            return 0;   //failed to register member
        }
    }
}

int librarian_register(user_t *u){
    u->id = get_max_id() + 1;
    u->role = librarian;

    if(user_save(u) == 1){
        return 1;
    }
    else{
        return 0;
    }
 }

int update_password(int id, char *new_passwd){
    user_t u_temp;

    if(user_find_by_id(id, &u_temp) == 1){

        strcpy(u_temp.password, new_passwd);
        if(user_update(&u_temp) == 1){
            return 1;
        }
        else{
            return 0;
        }
    }   
}