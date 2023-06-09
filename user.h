//This file contains user related functions

#ifndef __USER_H
#define __USER_H
#define USERS_FILE "users.db"

enum rol {owner, librarian, member};

typedef struct user
{
    int id;
    char name[40];
    char email[64];
    char password[41];
    char phone[10];
    enum rol role;      //O - owner ,L - librarian, M - member
}user_t;


#endif