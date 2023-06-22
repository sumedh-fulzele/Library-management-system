#ifndef __BOOK_CONTROL_H
#define __BOOK_CONTROL_H

void book_accept(book_t *b);
void book_print(book_t *b);
void add_new_book();
void find_book_by_title();
void edit_book();
void add_new_book_copy();
void change_rack();
void check_book_availability();
#endif