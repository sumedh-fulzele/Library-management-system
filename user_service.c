//This file contains user related bussiness logic functions(Tier - 2).

#include <stdio.h>
#include <string.h>
#include "user_dal.h"
#include "user_service.h"
#include "date.h"
#include "book.h"
#include "issuerecord.h"
#include "payment.h"

//validate user and return respective user data in *u.
int user_authenticate(char *email, char *password, user_t *u){
    int found = 0;
    
    //comapares given email and password in db.
    if(user_find_by_email(email, u) == 1){
        if(strcmp(u->password,password) == 0){
            found = 1;
        }
    }
    else{
        found = 0;
    }

    if(!found){
        return 0;
    }
    else{
        return 1;
    }
}

int owner_register(user_t *u){
    u->id = 1;
    u->role = owner;
    u->nextpayment_duedate = (date_t){0,0,0};
    
    remove(USER_FILE);
    remove(BOOK_FILE);
    remove(BOOK_COPY_FILE);
    remove(ISSUERECORD_FILE);
    remove(PAYMENT_FILE);

    if(user_save(u) == 1){
        return 1;
    }
    else{
        return 0;
    }

}

int member_register(user_t *u){
    user_t new_member;
    u->id = get_max_id() + 1;
    u->role = member;
    
    date_t next_due_date;
    current_date(&next_due_date);
    adddays(next_due_date, 30, &u->nextpayment_duedate);

    if(user_find_by_email(u->email, &new_member) == 1){
        return 2;   // if found cannot register with same email. 
    }
    else{
        if(user_save(u) == 1){
            return 1;   // member registered successfully.
        }
        else{
            return 0;   //failed to register member
        }
    }
}

int librarian_register(user_t *u){
    u->id = get_max_id() + 1;
    u->role = librarian;
    u->nextpayment_duedate = (date_t){0,0,0};

    if(user_save(u) == 1){
        return 1;
    }
    else{
        return 0;
    }
 }

int update_password(int id, char new_passwd[PASSWD_SIZE]){
    int flag_update = 0;
    user_t u_temp;

    if(user_find_by_id(id, &u_temp) == 1){
        
        strcpy(u_temp.password, new_passwd);
        
        if(user_update(&u_temp) == 1){
            flag_update = 1;
        }
        else{
            flag_update = 0;
        }
    }

    if(!flag_update){
        return 0;
    }
    else{
        return 1;
    }
}

int update_profile(int id, char new_email[EMAIL_SIZE], char new_phone[PHONE_SIZE]){
    int flag_update = 0;
    user_t u_temp;

    if(user_find_by_id(id, &u_temp) == 1){

        strcpy(u_temp.email, new_email);
        strcpy(u_temp.phone, new_phone);
        
        if(user_update(&u_temp) == 1){
            flag_update = 1;
        }
        else{
            flag_update = 0;
        }
    }

    if(!flag_update){
        return 0;
    }
    else{
        return 1;
    }
}

int ispaid_user(int member_id){
    int flag_paid;
    user_t u_buff;
    date_t currdate;
    current_date(&currdate);

    if(user_find_by_id(member_id, &u_buff)){
        
        int diff = datecmp(currdate, u_buff.nextpayment_duedate);
        

        if(diff == 0){
            flag_paid = 1;
        }
        else{
            flag_paid = 0;
        }
    }
    
    if(!flag_paid){
        return 0;
    }
    else{
        return 1;
    }   
}

int update_due_date(int id, date_t nextpayment_duedate){
    int flag_update = 0;
    user_t u_temp;

    if(user_find_by_id(id, &u_temp) == 1){

        u_temp.nextpayment_duedate = nextpayment_duedate;        
        
        if(user_update(&u_temp) == 1){
            flag_update = 1;
        }
        else{
            flag_update = 0;
        }
    }

    if(!flag_update){
        return 0;
    }
    else{
        return 1;
    }
}