//This file contains user related control(UI/UX) functions(Tier - 3).

#include<stdio.h>
#include<string.h>
#include"user_control.h"
#include"user_service.h"
#include"user_dal.h"

void accept_user(user_t *u){

    printf("\n Enter the Name : ");
    scanf("%*c%[^\n]", u->name);
    printf("\nEnter Email address : ");
    scanf("%*c%[^\n]", u->email);
    printf("\nEnter password : ");
    scanf("%*c%[^\n]", u->password);
    printf("\nEnter phone no. : ");
    scanf("%*c%[^\n]", u->phone);
}

void user_print(user_t *u){
    printf("Member ID : %d\n",u->id);
    printf("Name : %s\n",u->name);
    printf("Email address : %s\n",u->email);
    printf("Phone : %s\n",u->phone);
}

void edit_profile(){
    
    user_t *u;
    char *email;
    char *phone;
    
    printf("Enter new email address : ");
    scanf("%[^\n]", email);
    printf("Enter new phone number : ");
    scanf("%*c%[^\n]", phone);
    
    printf("email is %s", email);
    printf("phone is %s", phone);
    
    
    strcpy(u->email, email);
    strcpy(u->phone, phone);

    if(user_save(u) == 1){
        printf("Profile edited successfully..!!\n");
    }
    else{
        printf("Failed to edit profile..!!\n");
    }
}
