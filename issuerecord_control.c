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
    
    printf("\nEnter member ID \t\t: ");
    scanf("%d", &member_id);
    getchar();
    printf("\nEnter the ISBN of the book \t: ");
    scanf("%[^\n]", isbn);
    getchar();

    int flag_issued = issuerecord_add(isbn, member_id, &issuerecord_id);

    if(flag_issued == 1){
        printf("\nBook issued successfully.\nYour Issue ID is %d..!!\n", issuerecord_id);
        ir_press_any_key();

    }
    else if(flag_issued == 0){
        printf("\nBook copy isn't available..!!");
        ir_press_any_key();
    }
    else if(flag_issued == -2){
        printf("\nMember is not subscribed member");
        ir_press_any_key();
    }
    else if(flag_issued == -1){
        printf("\nError while saving issuerecord..!!");
        ir_press_any_key();
    }
    
}

void return_copy(){
    int issuerecord_id;
    float amount;
    book_copy_t bc;

    printf("\nEnter the issuerecord ID : ");
    scanf("%d", &issuerecord_id);
    getchar();

    if(issuerecord_edit(issuerecord_id, &bc, &amount) == 1){
        printf("\nFine amount : %.2f", amount);
        printf("\nPayment done successfully..!!");
        printf("\nIssued book copy with ID %d has been returned.", bc.id);
        ir_press_any_key();
    }
    else{
        printf("\nFailed to process your request..!!");
        ir_press_any_key();
    }
}

void print_issuerecord(){
    int issuerecord_id;
    issuerecord_t ir;

    printf("\nEnter the issue record id : ");
    scanf("%d", &issuerecord_id);

    if(issuerecord_find_by_id(issuerecord_id, &ir) == 1){
        printf("\n Issuer Record details are as follows :");
        printf("\nId \t: %d\nBook ID \t: %d\nMember ID \t: %d\nFine Amount \t: %d", ir.id, ir.book_copy_id, ir.member_id, ir.fine_amount);
        printf("\nIssue Date \t: %02d/%02d/%d", ir.issue_date.day, ir.issue_date.month, ir.issue_date.year);
        printf("\nReturn Due Date \t: %02d/%02d/%d", ir.return_due_date.day, ir.return_due_date.month, ir.return_due_date. year);
        printf("\nReturn Date \t: %02d/%02d/%d", ir.return_date.day, ir.return_date.month, ir.return_date.year);
        ir_press_any_key();

    }
    else{
        printf("\nNo Issue record found with this ID..\n!!");
        ir_press_any_key();

    }

}

void ir_press_any_key(){
    printf("\nPress Enter the continue...");
    getchar();
}