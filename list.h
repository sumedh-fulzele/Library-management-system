#ifndef __LIST_H
#define __LIST_H

#include "entry.h"

typedef struct node_category
{
    entry_category_t data;
    struct node_category *next;
}node_category_t;

typedef struct list_category
{
    node_category_t *head;
}list_category_t;

void init_list_category(list_category_t *cl);
int is_empty_list_category(list_category_t *cl);
node_category_t *create_node_category(entry_category_t data);
void add_first_category(entry_category_t data, list_category_t *cl);
node_category_t *search_node_category(int asc_key, list_category_t *cl);
void free_category_list(list_category_t *cl);



typedef struct node_book
{
    entry_book_t data;
    struct node_book *next;
}node_book_t;

typedef struct list_book
{
    node_book_t *head;
}list_book_t;

void init_list_book(list_book_t *bl);
int is_empty_list_book(list_book_t *bl);
node_book_t *create_node_book(entry_book_t data);
void add_first_book(entry_book_t data, list_book_t *bl);
node_book_t *search_node_book(int asc_key, list_book_t *bl);
void free_book_report_list(list_book_t *bl);


#endif