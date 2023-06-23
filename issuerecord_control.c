#include<stdio.h>
#include"book.h"
#include"issuerecord.h"
#include"date.h"
#include"issuerecord_service.h"
#include"issuerecord_dal.h"

void issue_copy(){
    int member_id;
    char isbn[BOOK_ISBN_SIZE] = {0};
    int issuerecord_id;
    
    printf("\nEnter member ID :");
    scanf("%d", &member_id);
    getchar();
    printf("\nEnter the ISBN of the book : ");
    scanf("%[^\n]", isbn);

    int flag_issued = issuerecord_add(isbn, member_id, &issuerecord_id);

    if(flag_issued == 1){
        printf("Book issued successfully.\n Your Issue ID is %d..!!", issuerecord_id);
    }
    else if(flag_issued == 0){
        printf("Book copy isn't available..!!");
    }
    else if(flag_issued == 0){
        printf("Error while saving issuerecord..!!");
    }
}

void return_copy(){
    int issuerecord_id;
    float amount;
    book_copy_t bc;

    printf("\nEnter the issuerecord ID");
    scanf("%d", &issuerecord_id);

    if(issuerecord_edit(issuerecord_id, &bc, &amount) == 1){
        printf("\nFine amount : %.2f", &amount);
        printf("Payment done successfully..!!");
        printf("\nIssued book copy with %d has been returned.", bc.id);
    }
    else{
        printf("\nFailed to process your request..!!");
    }
}

void print_issuerecord(){
    int issuerecord_id;
    issuerecord_t ir;

    printf("\nEnter the issue record id : ");
    scanf("%d", &issuerecord_id);

    if(issuerecord_find_by_id(issuerecord_id, &ir) == 1){
        printf("\n Issuer Record details are as follows :");
        printf("\nId : %d\nBook ID : %d\nMember ID: %d\nFine Amount : %d", ir.id, ir.book_copy_id, ir.member_id, ir.fine_amount);
        printf("\nIssue Date : %02d/%02d/%d", ir.issue_date.day, ir.issue_date.month, ir.issue_date.year);
        printf("\nReturn Due Date : %02d/%02d/%d", ir.return_due_date.day, ir.return_due_date.month, ir.return_due_date. year);
        printf("\nReturn Date : %02d/%02d/%d", ir.return_date.day, ir.return_date.month, ir.return_date.year);
    }
    else{
        printf("No Issue record found with this ID");
    }

}
