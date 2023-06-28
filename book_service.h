#ifndef __BOOK_SERVICE_H
#define __BOOK_SERVICE_H

#include "book.h"
#include "hashtable.h"

int book_add(book_t *b);
int book_edit(book_t *b);
int book_copy_add(char isbn[BOOK_ISBN_SIZE], int rack);
int book_copy_change_status(int book_copy_id, int status, book_copy_t *bc);
int book_copy_change_rack(int book_copy_id, int rack, book_copy_t *bc);
int book_search_by_isbn(char isbn[BOOK_ISBN_SIZE], book_t *b);
int book_copy_available(char isbn[BOOK_ISBN_SIZE]);
int book_search_by_title(char title[BOOK_TITLE_SIZE]);
int get_category_list(hashtable_category_t *hc);

#endif