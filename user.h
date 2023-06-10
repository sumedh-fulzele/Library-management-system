//This file contains user related functions

#ifndef __USER_H
#define __USER_H

#define USERS_FILE "users.db"
#define RECSIZE_USER sizeof(user_t)

enum rol {owner, librarian, member};

typedef struct user
{
    int id;
    char name[42];
    char email[60];
    char password[40];
    char phone[10];
    enum rol role;      //O - owner ,L - librarian, M - member
}user_t;

#endif