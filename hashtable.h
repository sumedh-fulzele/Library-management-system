#ifndef TABLE_H
#define TABLE_H

#include "entry.h"
#include "list.h"

int generate_asc_key(char *str);
int hashfunction(int k, int SIZE);


typedef struct hashtable_category
{
    int size_category_table;
    list_category_t *table;
}hashtable_category_t;

void init_hashtable_category(int size_category_table, hashtable_category_t *hc);
void hc_insert(entry_category_t ec, hashtable_category_t *hc);
// int hc_search(int asc_key, hashtable_category_t *hc);
void free_hashtable_category(hashtable_category_t *hc);


typedef struct hashtable_book
{
    int size_book_table;
    list_book_t *table;
}hashtable_book_t;

void init_hashtable_book(int size_book_table, hashtable_book_t *hb);
void hb_insert(entry_book_t eb, hashtable_book_t *hb);
// int hb_search(int asc_key, hashtable_book_t *hb);
void free_hashtable_book(hashtable_book_t *hb);

#endif