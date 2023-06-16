#include<stdio.h>
#include"book.h"
#include"issuerecord.h"
#include"date.h"
#include"issuerecord_service.h"

void issue_copy(){
    int member_id;
    char isbn[BOOK_ISBN_SIZE] = {0};
    
    printf("\nEnter member ID :");
    scanf("%d", &member_id);
    getchar();
    printf("\nEnter the ISBN of the book : ");
    scanf("%[^\n]", isbn);

    int flag_issued = issuerecord_add(isbn, member_id);

    if(flag_issued == 1){
        printf("Book issued successfully..!!");
    }
    else if(flag_issued == 0){
        printf("Book copy isn't available..!!");
    }
    else if(flag_issued == 0){
        printf("Error while saving issuerecord..!!");
    }
}