#ifndef __BOOK_DAL_H
#define __BOOK_DAL_H

#include"book.h"

int book_save(book_t *b);
int book_find_by_isbn(char isbn[BOOK_ISBN_SIZE], book_t *b);
int book_update(book_t *b);


#endif