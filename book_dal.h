#ifndef __BOOK_DAL_H
#define __BOOK_DAL_H

#include"book.h"

int book_save(book_t *b);
int book_find_by_isbn(char isbn[BOOK_ISBN_SIZE], book_t *b);
int book_update(book_t *b);
int book_copy_find_by_id(int id, book_copy_t *bc);
int book_copy_save(book_copy_t *bc);
int book_copy_update(book_copy_t *bc);
int book_copy_get_available_count(char isbn[BOOK_ISBN_SIZE]);
int get_max_book_copy_id();

#endif