#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"book.h"
#include"book_dal.h"

int book_add(book_t *b){
    if(book_save(b) == 1){
        return 1;   //when book added successfully.
    }
    else{
        return 0;   //failed to add book.
    }
}

int book_edit(book_t *b){  // *b contains new values
    int flag_update = 0;

    //updates respective fields of book_buff with user inputed b*.
    if(book_update(b) == 1){
        flag_update = 1;
    }
    else{
        flag_update = 0;
    }

    if(!flag_update){
        return 0;
    }
    else{
        return 1;
    }
}

int book_copy_add(char isbn[BOOK_ISBN_SIZE], int rack){
    
    book_copy_t book_copy_buff;
    int flag_save = 0;
    
    book_copy_buff.id = get_max_book_copy_id() + 1;
    strcpy(book_copy_buff.isbn,isbn);
    book_copy_buff.rack = rack;
    book_copy_buff.status = 1;

    if(book_copy_save(&book_copy_buff) == 1){
        flag_save = 1;
    }
    else{
        flag_save = 0;
    }

    if(!flag_save){
        return 0;
    }
    else{
        return 1;
    }
}

int book_copy_change_status(int book_copy_id, int status, book_copy_t *bc){
    int flag_status = 0;
    bc->id = book_copy_id;
    bc->status = status;
    
    if(book_copy_update(bc) == 1){
        flag_status = 1;
    }
    else{
        flag_status = 0;
    }

    if(!flag_status){
        return 0;
    }
    else{
        return 1;
    }
}

int book_copy_change_rack(int book_copy_id, int rack, book_copy_t *bc){
    int flag_chrack = 0;
    bc->id = book_copy_id;
    bc->rack = rack;

    
    if(book_copy_update(bc) == 1){
        flag_chrack = 1;
    }
    else{
        flag_chrack = 0;
    }
    
    if(!flag_chrack){
        return 0;
    }
    else{
        return 1;
    }
}

int book_search_by_isbn(char isbn[BOOK_ISBN_SIZE], book_t *b){
    if(book_find_by_isbn(isbn, b) == 1){
        return 1;
    }
    else{
        return 0;
    }
}


// int book_copy_available_id(char isbn[BOOK_ISBN_SIZE]){
//     int book_copy_count = book_copy_get_available_count(isbn);

// }

