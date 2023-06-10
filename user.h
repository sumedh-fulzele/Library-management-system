//This file contains user related functions

#ifndef __USER_H
#define __USER_H

#define USERS_FILE "users.db"
#define USER_NAME_SIZE 41
#define EMAIL_SIZE 60
#define PASSWD_SIZE 40
#define PHONE_SIZE 11
#define RECSIZE_USER sizeof(user_t)

enum rol {owner, librarian, member};

typedef struct user
{
    int id;
    char name[USER_NAME_SIZE];
    char email[EMAIL_SIZE];
    char password[PASSWD_SIZE];
    char phone[PHONE_SIZE];
    enum rol role;      //O - owner ,L - librarian, M - member
}user_t;

#endif