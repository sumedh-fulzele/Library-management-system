//This file contains user related bussiness logic functions(Tier - 2).
//This file contains user related bussiness logic functions(Tier - 2).
#ifndef __USER_SERVICE_H
#define __USER_SERVICE_H

#include"user.h"

int user_authenticate(char *email, char *password , user_t *u);  //validate user and return respective user data in u.
int owner_register(user_t *u);

#endif