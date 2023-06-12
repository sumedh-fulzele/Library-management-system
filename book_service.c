#include<stdio.h>
#include<string.h>
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

int book_edit(char isbn[BOOK_ISBN_SIZE],book_t *b){  // *b contains new values
    int flag_update = 0;
    book_t book_buff;   

    if(book_find_by_isbn(isbn, &book_buff) == 1){   //saves record from book.db to book_buff.
        //updates respective fields of book_buff with user inputed b*.
        if(book_update(b) == 1){
            flag_update = 1;
        }
        else{
            flag_update = 0;
        }
    }
    else{
        return 2;   //book doesn't exist in the library.
    }

    if(!flag_update){
        return 0;
    }
    else{
        return 1;
    }

}
