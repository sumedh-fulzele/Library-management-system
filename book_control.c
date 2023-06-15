#include<stdio.h>
#include"book.h"
#include"book_service.h"

void book_accept(book_t *b){
    printf("\nEnter the book details.");
    printf("\nTitle :");
    scanf("%[^\n]", b->title );
    printf("Author : ");
    scanf("%*c%[^\n]", b->author );
    printf("ISBN : ");
    scanf("%*c%[^\n]", b->isbn);
    printf("Category : ");
    scanf("%*c%[^\n]", b->category);
    scanf("%*c");
    printf("Price : ");
    scanf("%f", &b->price);
}

void book_print(book_t *b){
    printf("\nTitle : %s", b->title);
    printf("\nAuthor : %s", b->author);
    printf("\nISBN : %s", b->isbn);
    printf("\nCategory : %s", b->category);
    printf("\nPrice : %f", b->price);
}

void add_new_book(){
    book_t b;
    book_accept(&b);
    int flag_add = book_add(&b);
    if( flag_add == 1){
        printf("Book is successfully added..!!");
    }
    else{
        printf("Failed to add book");
    }
}

void find_book(){
    book_t  b;
    char isbn[BOOK_ISBN_SIZE];
    printf("Enter the ISBN of the book which you wish to search : ");
    scanf("%[^\n]",isbn);
    if(book_search_by_isbn(isbn, &b) == 1){
        printf("\nBook Found..!!\n");
        book_print(&b);
    }
    else{
        printf("\nBook Not Found..!!");
    }
}

void edit_book(){
    book_t b;
    printf("Enter new details of the book except ISBN :");
    book_accept(&b);
    if(book_edit(&b) == 1){
        printf("\nBook updated successfully..!!");
    }
    else{
        printf("Failed to edit book..!!");
    }
}

// void check_book_availability(){
    

// }

void book_copy_accept(char isbn[BOOK_ISBN_SIZE], int *rack){
    printf("\nEnter Book Copy details..");
    printf("\nEnter the ISBN of the book : ");
    scanf("%[^\n]", isbn);
    printf("\nEnter the rack number : ");
    scanf("%d", rack);
}

void add_new_book_copy(){
    char isbn[BOOK_ISBN_SIZE];
    int rack;
    book_copy_accept(isbn, &rack);
    if(book_copy_add(isbn, rack) == 1){
        printf("Book Copy added in the library..!!\n");
    }
    else{
        printf("Failed to add book copy\n");
    }
}

void change_rack(){
    book_copy_t bc;
    int book_copy_id;
    int rack;
    
    printf("\nEnter the ID of Book copy : ");
    scanf("%d", &book_copy_id);
    printf("\nEnter the new rack number : ");
    scanf("%d", &rack);
    
    if(book_copy_change_rack(book_copy_id, rack,  &bc) == 1){
        printf("Rack of book copy with ID %d changed successfully..!!", book_copy_id);
    }
    else{
        printf("Failed to change rack..!!");
    }
}

void check_book_availability(){
    char isbn[BOOK_ISBN_SIZE] = {0};
    printf("\nEnter the ISBN of the book : ");
    scanf("%s", isbn);
    if(book_copy_available(isbn) == 1){
        printf("\nBook is available..!");
    }
    else{
        printf("\nBook is unavailable..!!");
    }
}