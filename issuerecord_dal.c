#include<stdio.h>
#include<string.h>
#include"issuerecord.h"

int issuerecord_save(issuerecord_t *ir){
    FILE *fir;
    
    fir = fopen(ISSUERECORD_FILE, "ab");
    if(fir == NULL){
        return 0;
    }

    size_t recordwritten = fwrite(ir, RECSIZE_ISSUERECORD, 1, fir);

    fclose(fir);

    if(!recordwritten){
        return 0;
    }
    else{
        return 1;
    }
}
//returns -1 if encountered any error
int get_max_issuerecord_id(){
    issuerecord_t issuerecord_buff;
    // int max_id = 0;

    FILE *fir;
    fir = fopen(ISSUERECORD_FILE, "rb");
    if(fir == NULL){
        return 0;  //error
    }

    fseek(fir, -RECSIZE_ISSUERECORD, SEEK_END);
    size_t recordread = fread(&issuerecord_buff, RECSIZE_ISSUERECORD, 1, fir);

    fclose(fir);

    if(!recordread){
        return 0;       //error
    }
    else{
        return issuerecord_buff.id;  
    }
}