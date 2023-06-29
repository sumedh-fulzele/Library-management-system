//This file contains user related functions

#ifndef __USER_H
#define __USER_H

#include "date.h"

#define USER_FILE "user.db"
#define USER_NAME_SIZE 41
#define EMAIL_SIZE 60
#define PASSWD_SIZE 40
#define PHONE_SIZE 11
#define RECSIZE_USER sizeof(user_t)

enum rol {owner, librarian, member, norole};

typedef struct user
{
    int id;
    char name[USER_NAME_SIZE];
    char email[EMAIL_SIZE];
    char password[PASSWD_SIZE];
    char phone[PHONE_SIZE];
    enum rol role;      
    date_t nextpayment_duedate;   //due date for next monthly fees.
}user_t;

#endif