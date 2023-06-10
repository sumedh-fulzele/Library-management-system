//This file contains user related control(UI/UX) functions(Tier - 3).

#include<stdio.h>
#include<string.h>
#include"user_control.h"
#include"user_service.h"

void user_accept(user_t *u){

    printf("\n Enter the Name : ");
    scanf("%[^\n]", u->name);
    printf("\nEnter Email address : ");
    scanf("%*c%[^\n]", u->email);
    printf("\nEnter password : ");
    scanf("%*c%[^\n]", u->password);
    printf("\nEnter phone no. : ");
    scanf("%*c%[^\n]", u->phone);
    scanf("%*c");   //removes "\n" from input buffer
}

void user_print(user_t *u){
    printf("Member ID : %d\n",u->id);
    printf("Name : %s\n",u->name);
    printf("Email address : %s\n",u->email);
    printf("Phone : %s\n",u->phone);
}

void signin(){
    user_t u;
    
    char email[EMAIL_SIZE];
    char password[PASSWD_SIZE];

LOGIN_PROMPT:

    printf("Enter login credentials.\n");
    printf("Email\t: ");
    scanf("%[^\n]", email);
    printf("Password\t:");
    scanf("%*c%[^\n]", password);
    scanf("%*c");   //this removes \n from input buffer for re taking login credentials after failed user authentication.  
    
    if(user_authenticate(email, password, &u) == 1){
        printf("User logged in successfully....!");
    }
    else{
        printf("Incorrect email or password.");
        goto LOGIN_PROMPT;
    }
}

void signup(){
    user_t new_member;

    printf("Please enter the details.\n");
    user_accept(&new_member);
    
    int flag = member_register(&new_member);
    if(flag == 1){
        printf("New member successfully registered..!!\n");
    }
    else if(flag == 2){
        printf("Email is already registered with different account. Please use different email address.\n");
    }
    else{
        printf("Failed to register new user..!!\n");
    }
}

void change_password(int id){

    char new_passwd[PASSWD_SIZE];
    printf("Please enter your new password : ");
    scanf("%[^\n]", new_passwd);
    if(update_password(id, new_passwd) == 1){
        printf("Password changed successfully..!!\n");
    }
    else{
        printf("Error while changing password.\n");
    }
}