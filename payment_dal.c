#include<stdio.h>
#include"payment.h"

int payment_save(payment_t *p){

    FILE *fp;

    fp = fopen(PAYMENT_FILE,"ab");
    if(fp == NULL){
        return 0;
    }

    size_t recordwritten = fwrite(p, RECSIZE_PAYMENT, 1, fp);

    fclose(fp);

    if(!recordwritten){
        return 0;
    }
    else{
        return 1;
    }
}

int get_max_pay_id(){
    payment_t p_buff;
    FILE *fp;

    fp = fopen(PAYMENT_FILE, "rb");
    if(fp == NULL){
        return 0;
    }

    fseek(fp, -RECSIZE_PAYMENT, SEEK_END);
    fread(&p_buff, RECSIZE_PAYMENT, 1, fp);
    
    fclose(fp);

    return p_buff.id;
}

int payment_search_by_id(int payment_id, payment_t *p){
    int flag_found = 0;  //flag
    FILE *fp;
    
    fp = fopen(PAYMENT_FILE , "rb");
    if(fp == NULL){
        return 0;
    }

    while ( fread(p, RECSIZE_PAYMENT, 1, fp) > 0){
        if(p->id == payment_id){            
            flag_found = 1;
            break;
        }
    }

    fclose(fp);

    if(!flag_found){
        return 0;
    }
    else{
        return 1;
    }
}