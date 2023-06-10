//This file contains user related bussiness logic functions(Tier - 2).

#include<stdio.h>
#include<string.h>
#include"user_dal.h"
#include"user_service.h"

//validate user and return respective user data in *u.
int user_authenticate(char *email, char *password, user_t *u){
    int found = 0;
        printf("email found");
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
    u->id = get_max_id() + 1;
    u->role = member;

    if(user_save(u) == 1){
        return 1;
    }
    else{
        return 0;
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

