//This file contains user related control(UI/UX) functions(Tier - 3).

#include <stdio.h>
#include <string.h>
#include "user.h"
#include "user_control.h"
#include "user_service.h"

void user_accept(user_t *u){

    printf("\nEnter the Name \t\t: ");
    scanf("%[^\n]", u->name);
    printf("\nEnter Email address \t: ");
    scanf("%*c%[^\n]", u->email);
    printf("\nEnter password \t\t: ");
    scanf("%*c%[^\n]", u->password);
    printf("\nEnter phone no. \t: ");
    scanf("%*c%[^\n]", u->phone);
    scanf("%*c");   //removes "\n" from input buffer
}

void user_print(user_t *u){
    printf("Member ID : %d\n",u->id);
    printf("Name : %s\n",u->name);
    printf("Email address : %s\n",u->email);
    printf("Phone : %s\n",u->phone);
    printf("Your next monthly payment due date : %02d/%02d/%d\n", u->nextpayment_duedate.day, u->nextpayment_duedate.month, u->nextpayment_duedate.year);
    user_press_any_key();
}

void signin(int *user_id, enum rol *user_role){
    user_t u;
    
    char email[EMAIL_SIZE];
    char password[PASSWD_SIZE];

LOGIN_PROMPT:

    printf("Enter login credentials.\n");
    printf("Email\t\t: ");
    scanf("%[^\n]", email);
    printf("Password\t: ");
    scanf("%*c%[^\n]", password);
    scanf("%*c");   //this removes \n from input buffer for re taking login credentials after failed user authentication.  
    
    if(user_authenticate(email, password, &u) == 1){
        *user_id = u.id;
        *user_role = u.role;
        printf("\nUser logged in successfully....!!");
        user_press_any_key();
        
    }
    else{
        printf("\nIncorrect email or password.");
        user_press_any_key();
        
        goto LOGIN_PROMPT;
    }
}

void signup(){
    user_t new_member;

    printf("Please enter the details.\n");
    user_accept(&new_member);
    
    int flag = member_register(&new_member);
    if(flag == 1){
        printf("New member successfully registered..!!\nMember ID is %d.\n", new_member.id);
        user_press_any_key();

    }
    else if(flag == 2){
        printf("Email is already registered with different account. Please use different email address.\n");
        user_press_any_key();
        
    }
    else{
        printf("Failed to register new user..!!\n");
        user_press_any_key();
    }
}

void change_password(int id){

    char new_passwd[PASSWD_SIZE];
    printf("Please enter new password : ");
    scanf("%[^\n]", new_passwd);
    getchar();
    if(update_password(id, new_passwd) == 1){
        printf("Password changed successfully..!!\n");
        user_press_any_key();
    }
    else{
        printf("Error while changing password.\n");
        user_press_any_key();
    }
}

void edit_profile(int id){
    char new_email[EMAIL_SIZE];
    char new_phone[PHONE_SIZE];

    printf("Enter new details.\n");
    printf("New email address \t: ");
    scanf("%[^\n]", new_email);
    printf("Enter new phone number \t: ");
    scanf("%*c%[^\n]",new_phone);
    getchar();
    if(update_profile(id, new_email, new_phone) == 1){
        printf("Profile updated successfully..!!\n");
        user_press_any_key();
    }
    else{
        printf("Error while updating profile.\n");
        user_press_any_key();
    }
}

void appoint_librarian(){
    user_t new_librarian;

    printf("\nPlease enter the librarian details.\n");
    user_accept(&new_librarian);
    
    int flag = librarian_register(&new_librarian);
    if(flag == 1){
        printf("New Librarian added...!!\n");
        user_press_any_key();
    }
    else if(flag == 2){
        printf("Email is already registered with different account. Please use different email address.\n");
        user_press_any_key();
    }
    else{
        printf("Failed to register new librarian..!!\n");
        user_press_any_key();
    }
}

void user_press_any_key(){
    printf("\nPress Enter the continue...");
    getchar();
}