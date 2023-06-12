//This files contains user related data handling functions(Tier - 1).

#include<stdio.h>
#include<string.h>
#include"user.h"

//saves structure u in USER_FILE
int user_save(user_t *u){
    FILE *fu;
    
    fu = fopen(USER_FILE, "ab");
    if(fu == NULL){
        return 0;
    }
    
    size_t recordwritten = fwrite(u, RECSIZE_USER, 1,fu);
    fclose(fu);
    
    // This check if record is written successfully or not in the USER_FILE 
    if(recordwritten != 1){
        return 0; //failure
    }
    else{
        return 1; //success
    }
}

// finds user by email in USER_FILE and saves record in *u
int user_find_by_email(char *email, user_t *u){
    int found = 0;  //flag
    FILE *fu;
    
    fu = fopen(USER_FILE, "rb");
    if(fu == NULL){
        return 0;
    }

    while ( fread(u, RECSIZE_USER, 1, fu) > 0){
        if(strcmp(u->email ,email) == 0){            
            found = 1;
            break;
        }
    }

    fclose(fu);

    if(!found){
        return 0;
    }
    else{
        return 1;
    }
}

// finds user by id in USER_FILE and saves record in *u
int user_find_by_id(int id, user_t *u){
    int found = 0;  //flag
    FILE *fu;
    
    fu = fopen(USER_FILE, "rb");
    if(fu == NULL){
        return 0;
    }

    while ( fread(u, RECSIZE_USER, 1, fu) > 0){
        if(u->id == id){            
            found = 1;
            break;
        }
    }

    fclose(fu);

    if(!found){
        return 0;
    }
    else{
        return 1;
    }
}

//updates users data in USER_FILE
int user_update(user_t *u){
    
    user_t user_buff;
    
    int updated = 0;    //flag

    FILE *fu;
    fu = fopen(USER_FILE, "rb+");
    if(fu == NULL){
        return 0;
    }

    while( fread(&user_buff, RECSIZE_USER , 1, fu) > 0 ) {
        
        // if id is matching or not
        if(u->id == user_buff.id){
            
            //copies date to the respective fields
            strcpy(user_buff.email, u->email);
            strcpy(user_buff.phone, u->phone);
            strcpy(user_buff.password, u->password);
          
            fseek(fu, -RECSIZE_USER, SEEK_CUR);  // move file fpos to one record back
            fwrite(&user_buff, RECSIZE_USER, 1, fu);    // update changes into the file
            
            updated = 1;
            break;
        }
    }
    fclose(fu);

    if(!updated){
        return 0;
    }
    else{
        return 1;
    }
}

int get_max_id(){
    user_t user_buff;
    FILE *fu;
    fu = fopen(USER_FILE,"rb");
    if(fu == NULL){
        return 0;
    }
    
    fseek(fu,-RECSIZE_USER,SEEK_END);
    fread(&user_buff, RECSIZE_USER, 1, fu);

    fclose(fu);
    
    return user_buff.id;
     
}