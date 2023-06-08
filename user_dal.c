//This files contains user related data handling functions(Tier - 1).

#include<stdio.h>
#include<string.h>
#include"user.h"

int user_save(user_t *u){
    FILE *fu;
    
    fu = fopen(USERS_FILE, "ab");
    if(fu == NULL){
        return 1;
    }
    
    size_t recordwritten = fwrite(u, sizeof(user_t), 1,fu);
    fclose(fu);
    
    if(recordwritten != 1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int user_find_by_email(char *email,user_t *u){
    int found = 1;
    FILE *fu;
    
    fu = fopen(USERS_FILE, "rb");
    if(fu == NULL){
        return 1;
    }

    while ( fread(u, sizeof(user_t), 1, fu) > 0){
        if(strcmp(u->email ,email) == 0){            
            found = 0;
            break;
        }
    }

    fclose(fu);

    if(found == 0){
        return 0;
    }
    else {
        return 1 ;
    }
}