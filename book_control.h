#ifndef __BOOK_CONTROL_H
#define __BOOK_CONTROL_H

#include "book.h"
#include "entry.h"

void book_accept(book_t *b);
void book_print(book_t *b);
void book_category_report_print(entry_category_t *ec);
void book_report_print(entry_book_t *eb);
void add_new_book();
void find_book_by_isbn();
void edit_book();
void add_new_book_copy();
void change_rack();
void check_book_availability();
void find_book_by_title();
void book_categories_report();
void book_report();
void book_press_any_key();

#endif