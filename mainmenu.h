#ifndef __MAINMENU_H
#define __MAINMENU_H

int loginpage_menu();
void loginpage_switch(int *user_id, enum rol *user_role);
int member_menu();
void member_switch(int *user_id, enum rol *user_role);
int librarian_menu();
void librarian_switch(int *user_id, enum rol *user_role);
int owner_menu();
void owner_switch(int *user_id, enum rol *user_role);



#endif