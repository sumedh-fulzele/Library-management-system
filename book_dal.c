#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "book.h"
#include "book_list.h"

//saves structure u in BOOK_FILE
int book_save(book_t *b)
{
    FILE *fb;
    
    fb = fopen(BOOK_FILE, "ab");
    if(fb == NULL){
        return 0;
    }
    
    size_t recordwritten = fwrite(b, RECSIZE_BOOK, 1,fb);
    fclose(fb);
    
    // This check if record is written successfully or not in the BOOK_FILE 
    if(recordwritten != 1){
        return 0; //failure
    }
    else{
        return 1; //success
    }
}

// finds book by isbn in BOOK_FILE and saves record in *b
int book_find_by_isbn(char isbn[BOOK_ISBN_SIZE], book_t *b)
{
    int found = 0;  //flag
    FILE *fb;
    
    fb = fopen(BOOK_FILE, "rb");
    if(fb == NULL){
        return 0;
    }

    while ( fread(b, RECSIZE_BOOK, 1, fb) > 0){       

        if(strcmp(b->isbn,isbn) == 0){  
            found = 1;
            break;
        }
    }

    fclose(fb);

    if(!found){
        return 0;
    }
    else{
        return 1;
    }
}

int book_update(book_t *b)
{    
    book_t book_buff;
    
    int updated = 0;    //flag

    FILE *fb;
    fb = fopen(BOOK_FILE, "rb+");
    if(fb == NULL){
        return 0;
    }

    while( fread(&book_buff, RECSIZE_BOOK , 1, fb) > 0 ) {
        
        // if isbn is matching or not
        if(strcmp(b->isbn, book_buff.isbn) == 0){
            
            //copies data to the respective fields.
            strcpy(book_buff.title, b->title);
            strcpy(book_buff.author, b->author);
            strcpy(book_buff.category, b->category);
            book_buff.price = b->price;

            fseek(fb, -RECSIZE_BOOK, SEEK_CUR);  // move file fpos to one record back
            fwrite(&book_buff, RECSIZE_BOOK, 1, fb);    // update changes into the file
            
            updated = 1;
            break;
        }
    }
    fclose(fb);

    if(!updated){
        return 0;
    }
    else{
        return 1;
    }
}

int book_copy_find_by_id(int id, book_copy_t *bc)
{
    int flag_found = 0;  //flag
    FILE *fbc;
    
    fbc = fopen(BOOK_COPY_FILE , "rb");
    if(fbc == NULL){
        return 0;
    }

    while ( fread(bc, RECSIZE_BOOK_COPY, 1, fbc) > 0){
        if(bc->id == id){            
            flag_found = 1;
            break;
        }
    }

    fclose(fbc);

    if(!flag_found){
        return 0;
    }
    else{
        return 1;
    }
}

int book_copy_save(book_copy_t *bc)
{
    FILE *fbc;

    fbc = fopen(BOOK_COPY_FILE,"ab");
    if(fbc == NULL){
        return 0;
    }

    size_t copywritten = fwrite(bc, RECSIZE_BOOK_COPY, 1, fbc);

    fclose(fbc);
    if(!copywritten){
        return 0;
    }
    else{
        return 1;
    }   
}

int book_copy_update(book_copy_t *bc)
{
    book_copy_t book_copy_buff;
    
    int flag_update = 0;    //flag

    FILE *fbc;
    fbc = fopen(BOOK_COPY_FILE, "rb+");
    if(fbc == NULL){
        return 0;
    }

    while( fread(&book_copy_buff, RECSIZE_BOOK_COPY , 1, fbc) > 0 ) {
        
        // if isbn is matching or not
        if(bc->id == book_copy_buff.id){
            
            //copies data to the respective fields.
            book_copy_buff.rack = bc->rack;            
            book_copy_buff.status = bc->status;

            fseek(fbc, -RECSIZE_BOOK_COPY, SEEK_CUR);  // move file fpos to one record back
            fwrite(&book_copy_buff, RECSIZE_BOOK_COPY, 1, fbc);    // update changes into the file
            
            flag_update = 1;
            break;
        }
    }
    fclose(fbc);

    if(!flag_update){
        return 0;
    }
    else{
        return 1;
    }
}

int book_copy_get_count(char isbn[BOOK_ISBN_SIZE], int *total_count, int *avail_count)
{
    book_copy_t book_copy_buff;
    FILE *fbc;

    fbc = fopen(BOOK_COPY_FILE, "rb");
    if(fbc == NULL){
        return 0;      //error while opening file.
    }

    while(fread(&book_copy_buff, RECSIZE_BOOK_COPY, 1, fbc) > 0){
        printf("%s", book_copy_buff.isbn);
        if(strcmp(isbn, book_copy_buff.isbn) == 0){
            (*total_count)++;
            if(book_copy_buff.status == 1){
                (*avail_count)++;
            }
        }
    }

    fclose(fbc);

    return 1;
}

int get_max_book_copy_id()
{
    book_copy_t book_copy_buff;
    FILE *fbc;
    fbc = fopen(BOOK_COPY_FILE,"rb");
    if(fbc == NULL){
        return 0;
    }

    fseek(fbc, -RECSIZE_BOOK_COPY, SEEK_END);
    fread(&book_copy_buff, RECSIZE_BOOK_COPY, 1, fbc);

    fclose(fbc);

    return book_copy_buff.id;
}

int book_find_by_title(char title[BOOK_TITLE_SIZE], book_list_t *bl){  //return type will be int in future
    int flag_found = 0;
    book_t b;
    
    FILE *fb;
    fb = fopen(BOOK_FILE, "rb");
    if(fb == NULL){
        return -1;
        // printf("Error opening file..!!");   //will be removed in future
    }

    // for converting string to lower.
    for(int i = 0; title[i]; i++){
        title[i] = tolower(title[i]);
    }

    while( fread(&b, RECSIZE_BOOK, 1, fb) > 0){
        
        char str_buff[BOOK_TITLE_SIZE];
        strcpy(str_buff, b.title);

        // for converting string to lower.
        for(int i = 0; str_buff[i]; i++){
           str_buff[i] = tolower(str_buff[i]);
        }

        if(strstr(str_buff, title) != NULL){
            // book_print(&b);                 //will be removed in future
            // printf("\n");                   //will be removed in future
            add_first_book_node(b, bl);        
            flag_found = 1;
        }
        
    }

    fclose(fb);

    if(!flag_found){
        return 0;
        // printf("Book not found..!!");       //will be removed in future
    }
    else{
        return 1;
    }
}

int book_copy_avail_id(char isbn[BOOK_ISBN_SIZE], book_copy_t *bc){
    int flag_avail = 0;

    FILE *fbc;
    fbc = fopen(BOOK_COPY_FILE, "rb");
    if(fbc == NULL){
        return -1;      //error opening file.
    }

    while(fread(bc, RECSIZE_BOOK_COPY, 1, fbc) > 0){
        if(strcmp(isbn, bc->isbn) == 0){            
            if(bc->status == 1){
                flag_avail = 1;
                break;
            }
        }
    }

    fclose(fbc);

    if(!flag_avail){
        return 0;   //book copy isn't available.
    }
    else{
        return 1;   //book copy is available.
    }
}
