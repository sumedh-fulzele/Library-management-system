//This files contains user related data handling functions(Tier - 1).

#include<stdio.h>
#include<string.h>
#include"user.h"

int user_save(user_t *u){
    FILE *fu;
    
    fu = fopen(USERS_FILE, "ab");
    if(fu == NULL){
        return 0;
    }
    
    size_t recordwritten = fwrite(u, sizeof(user_t), 1,fu);
    fclose(fu);
    
    if(recordwritten != 1)
    {
        return 0; //failure
    }
    else{
        return 1; //success
    }
}

int user_find_by_email(char *email, user_t *u){
    int found = 0;
    FILE *fu;
    
    fu = fopen(USERS_FILE, "rb");
    if(fu == NULL){
        return 0;
    }

    while ( fread(u, sizeof(user_t), 1, fu) > 0){
        if(strcmp(u->email ,email) == 0){            
            found = 1;
            break;
        }
    }

    fclose(fu);

    if(found == 1){
        return 1;
    }
    else {
        return 0 ;
    }
}

int user_find_by_id(int id, user_t *u){
    int found = 0;
    FILE *fu;
    
    fu = fopen(USERS_FILE, "rb");
    if(fu == NULL){
        return 0;
    }

    while ( fread(u, sizeof(user_t), 1, fu) > 0){
        if(u->id == id){            
            found = 1;
            break;
        }
    }

    fclose(fu);

    if(found == 1){
        return 1;
    }
    else {
        return 0 ;
    }
}

int user_update(char *email, char *phone, int id){
    user_t u;
    int updated = 0;
    long recsize = sizeof(user_t);

    FILE *fu;
    fu = fopen(USERS_FILE, "rb+");
    if(fu == NULL){
        return 0;
    }

    while( fread(&u, recsize , 1, fu) > 0 ) {
        
        // if id is matching
        if(id == u.id){
          
            strcpy(u.email,email);
            strcpy(u.phone,phone);
          
            fseek(fu, -recsize, SEEK_CUR);  // move file pos to one record back
            fwrite(&u, recsize , 1, fu);    // update changes into the file
            
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