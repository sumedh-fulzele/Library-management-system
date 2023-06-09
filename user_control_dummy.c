#include<stdio.h>
#include"user.h"
#include"user_dal.h"
#include"user_service.h"

#include<string.h>



void authuser(){

    int id;
    user_t u;
    char *email = "sumedh@sunbeam.com";
    char *password = "sumedh";
    if(user_authenticate(email, password, &u) == 1)
    {
        id = u.id;
        printf("logged in successfully with id = %d.\n", id);
        
    }
    else{
        printf("failed\n");
    }
}

void findemail(){
    user_t u;
    char email[60] = "sumedh@sumedh.com";
    if(user_find_by_email(email, &u) == 1)
    {
        printf("record found");
    }
    else
        printf("failed!!");
}

void newuser(){
    user_t u;
    u.id = 1;
    strcpy(u.name,"Sumedh");
    strcpy(u.email, "sumedh@sunbeam.com");
    strcpy(u.password, "sumedh");
    strcpy(u.phone, "8625791579");
    u.role = member;

    

    if(user_save(&u) == 1){
        printf("User saves successfully\n");
    }
    else
    {
        printf("failed!!");
    }

}

void updateuser(){
    char *email = "sumedh@sumedh.com";
    char *phone = "5862471239";
    if(user_update(email, phone, 1) == 1)
    {
        printf("updated successfully\n");
    }
    else{
       printf("failed!!");
   }
}
