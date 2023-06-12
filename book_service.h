#ifndef __BOOK_SERVICE_H
#define __BOOK_SERVICE_H

#include<book.h>

int book_add(book_t *b);
int book_edit(char isbn[BOOK_ISBN_SIZE],book_t *b);


#endif