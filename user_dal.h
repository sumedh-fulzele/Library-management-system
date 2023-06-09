//This files contains user related data handling functions(Tier - 1).

#ifndef __USER_DAL_H
#define __USER_DAL_H

#include"user.h"

int user_save(user_t *u);
int user_update(char *email, char *phone, int id);
int user_find_by_email(char email[] , user_t *u);
int user_find_by_id(int , user_t *u);

#endif