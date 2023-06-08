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

