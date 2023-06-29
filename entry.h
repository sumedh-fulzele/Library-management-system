#ifndef __ENTRY_H
#define __ENTRY_H

#include "book.h"

typedef struct category_data
{
    char book_category[BOOK_CATEGORY_SIZE];
    int count;
}category_data_t;

typedef struct entry_category
{
    int asc_key;
    category_data_t value;
}entry_category_t;



typedef struct book_data
{
    char title[BOOK_TITLE_SIZE];
    char isbn[BOOK_ISBN_SIZE];
    int total_count;
    int total_avail;
}book_data_t;

typedef struct entry_book
{
    int asc_key;
    book_data_t value;
}entry_book_t;


#endif