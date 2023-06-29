#include <stdio.h>
#include <stdlib.h>
#include "user_control.h"
#include "book_control.h"
#include "issuerecord_control.h"
#include "payment_control.h"

// int loginpage_menu(){
//     int choice ;
//     printf("\e[1;1H\e[2J");
//     printf("\e[2J");
//     printf("\e[2J");
//     printf("\n\t\t######################################################################################");
//     printf("\n\t\t######################################################################################");
//     printf("\n\t\t########################    WELCOME TO THE LIBRARY SYSTEM    #########################");
//     printf("\n\t\t######################################################################################");
//     printf("\n\t\t######################################################################################");
//     printf("\n\t\t######################################################################################");
//     printf("\n\t\t######################################################################################");
//     printf("\n\t\t######################################################################################");
//     printf("\n\t\t###############################                      #################################");
//     printf("\n\t\t###############################     1. SIGN IN       #################################");
//     printf("\n\t\t###############################     2. SIGN UP       #################################");
//     printf("\n\t\t###############################     0. EXIT          #################################");
//     printf("\n\t\t###############################                      #################################");
//     printf("\n\t\t######################################################################################");
//     printf("\n\t\t######################################################################################");
//     printf("\n\t\t######################################################################################");
//     printf("\n\t\t######################################################################################");
//     printf("\n\t\t######################################################################################");
//     printf("\n\t\tEnter your choice : ");
//     scanf("%d", &choice);
//     getchar();
//     return choice;
// }

int owner_menu(){
    int choice ;
    printf("\e[1;1H\e[2J");
    printf("\e[2J");
    printf("\e[2J");
    printf("\n-------------------------------------------------------------");
    printf("\n##################          MENU          ###################");
    printf("\n-------------------------------------------------------------");
    printf("\n##################   1. EDIT PROFILE      ###################");
    printf("\n##################   2. CHANGE PASSWORD   ###################");
    printf("\n##################   3. BOOKWISE REPORT   ###################");
    printf("\n##################   4. CATEGORYWISE      ###################");
    printf("\n##################      REPORT            ###################");
    printf("\n##################   5. FEES/FINE REPORT  ###################");
    printf("\n##################   6. APPOINT LIBRARIAN ###################");
    printf("\n##################   0. LOGOUT            ###################");
    printf("\n-------------------------------------------------------------");
    printf("\nEnter your choice : ");
    scanf("%d", &choice);
    getchar();
    return choice;
}

void owner_switch(int *user_id, enum rol *user_role){
    while(1){
        int choice = owner_menu();

        switch(choice){
        
        case 0:
        *user_id = 0;
        *user_role = norole;
        loginpage_switch(user_id, user_role);
        break;

        case 1:
        edit_profile(*user_id);
        break;

        case 2:
        change_password(*user_id);
        break;

        case 3:
        book_report();
        break;
        
        case 4:
        book_categories_report();
        break;

        case 5:
        fine_fees_report();
        break;

        case 6:
        appoint_librarian();
        break;

        }
    }
}

int member_menu(){
    int choice ;
    printf("\e[1;1H\e[2J");
    printf("\e[2J");
    printf("\e[2J");
    printf("\n-----------------------------------------------------------");
    printf("\n##################         MENU         ###################");
    printf("\n-----------------------------------------------------------");
    printf("\n##################   1. EDIT PROFILE    ###################");
    printf("\n##################   2. CHANGE PASSWORD ###################");
    printf("\n##################   3. FIND BOOK       ###################");
    printf("\n##################   4. CHECK BOOK      ###################");
    printf("\n##################      AVAILABILITY    ###################");
    printf("\n##################   0. LOGOUT          ###################");
    printf("\n-----------------------------------------------------------");
    printf("\nEnter your choice : ");
    scanf("%d", &choice);
    getchar();
    return choice;
}

void member_switch(int *user_id, enum rol *user_role){
    while(1){
        int choice = member_menu();

        switch(choice){
            case 0:
            *user_id = 0;
            *user_role = norole;
            loginpage_switch(user_id,user_role);
            break;

            case 1:
            edit_profile(*user_id);
            break;
            
            case 2:
            change_password(*user_id);
            break;

            case 3:
            find_book_by_title();
            break;

            case 4:
            check_book_availability();
            break;

        }
    }
}

int librarian_menu(){
    int choice ;
    printf("\e[1;1H\e[2J");
    printf("\e[2J");
    printf("\e[2J");
    printf("\n------------------------------------------------------------");
    printf("\n##################          MENU         ###################");
    printf("\n------------------------------------------------------------");
    printf("\n##################   1. EDIT PROFILE     ###################");
    printf("\n##################   2. CHANGE PASSWORD  ###################");
    printf("\n##################   3. FIND BOOK        ###################");
    printf("\n##################   4. CHECK BOOK       ###################");
    printf("\n##################      AVAILABILITY     ###################");
    printf("\n##################   5. ADD NEW BOOK     ###################");
    printf("\n##################   6. ADD NEW COPY     ###################");
    printf("\n##################   7. EDIT BOOK        ###################");
    printf("\n##################   8. CHANGE RACK      ###################");
    printf("\n##################   9. ISSUE COPY       ###################");
    printf("\n##################  10. RETURN COPY      ###################");
    printf("\n##################  11. ADD NEW MEMBER   ###################");
    printf("\n##################  12. TAKE PAYMENT     ###################");
    printf("\n##################   0. LOGOUT           ###################");
    printf("\n------------------------------------------------------------");
    printf("\nEnter your choice : ");
    scanf("%d", &choice);
    getchar();
    return choice;
}

void librarian_switch(int *user_id, enum rol *user_role){
    while(1){
        int choice = librarian_menu();

        switch(choice){
            case 0:
            *user_id = 0;
            *user_role = norole;
            loginpage_switch(user_id, user_role);
            break;

            case 1:
            edit_profile(*user_id);
            break;

            case 2:
            change_password(*user_id);
            break;

            case 3:
            find_book_by_title();
            break;

            case 4:
            check_book_availability();
            break;

            case 5:
            add_new_book();
            break;

            case 6:
            add_new_book_copy();
            break;

            case 7:
            edit_book();
            break;

            case 8:
            change_rack();
            break;

            case 9:
            issue_copy();
            break;

            case 10:
            return_copy();
            break;

            case 11:
            signup();       // add member
            break;

            case 12:
            take_payment();
            break;

        }
    }
}

int loginpage_menu(){
    int choice ;
    printf("\e[1;1H\e[2J");
    printf("\e[2J");
    printf("\e[2J");
    printf("\n-----------------------------------------------------------");
    printf("\n##########    WELCOME TO THE LIBRARY SYSTEM    ############");
    printf("\n-----------------------------------------------------------");
    printf("\n###########################################################");
    printf("\n###########################################################");
    printf("\n##################                      ###################");
    printf("\n##################     1. SIGN IN       ###################");
    printf("\n##################     2. SIGN UP       ###################");
    printf("\n##################     0. EXIT          ###################");
    printf("\n##################                      ###################");
    printf("\n###########################################################");
    printf("\n###########################################################");
    printf("\n###########################################################");
    printf("\n-----------------------------------------------------------");
    printf("\nEnter your choice : ");
    scanf("%d", &choice);
    getchar();
    return choice;
}

void loginpage_switch(int *user_id, enum rol *user_role){
    
    while(1){
        int choice;

        choice = loginpage_menu();

        if(choice == 0){
            printf("\e[1;1H\e[2J");
            exit(0);
        }

        switch (choice){
            case 1 :
                signin(user_id, user_role);
                if(*user_role == owner){
                    owner_switch(user_id, user_role);
                }
                else if(*user_role == librarian){
                    librarian_switch(user_id, user_role);
                }
                else if(*user_role == member){
                    member_switch(user_id, user_role);
                }

                break;

            case 2:
                signup();
                break;

            default :
                printf("\nInvalid choice ..!!\nPress Enter the continue...");
                getchar();
                break;
        }
    }
}