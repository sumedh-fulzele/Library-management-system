#ifndef __BOOK_H
#define __BOOK_H

#define BOOK_FILE "book.db"
#define BOOK_COPY_FILE "books_copy.db"
#define BOOK_ISBN_SIZE 16
#define BOOK_TITLE_SIZE 100
#define BOOK_AUTHOR_SIZE 40
#define BOOK_CATEGORY_SIZE 40
#define RECSIZE_BOOK sizeof(book_t)
#define RECSIZE_BOOK_COPY sizeof(book_copy_t)

typedef struct book{
    char title[BOOK_TITLE_SIZE];
    char author[BOOK_AUTHOR_SIZE];
    char category[BOOK_CATEGORY_SIZE];
    float price;
    char isbn[BOOK_ISBN_SIZE];
}book_t;

typedef struct book_copy
{
    int id;
    char isbn[BOOK_ISBN_SIZE];
    int rack;
    int status;
}book_copy_t;

#endif