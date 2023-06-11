//This file contains user related control(UI/UX) functions(Tier - 3).

#ifndef __USER_CONTROL_H
#define __USER_CONTROL_H

#include"user.h"

void user_accept(user_t *u);
void user_print(user_t *u);
void signin(int *id);
void signup();
void change_password(int id);
void edit_profile(int id);

#endif