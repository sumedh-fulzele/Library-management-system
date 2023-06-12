#include<stdio.h>
#include<string.h>
#include"book.h"

//saves structure u in BOOK_FILE
int book_save(book_t *b){
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

// finds book by isbn in BOOK_FILE and saves record in *u
int book_find_by_isbn(char isbn[BOOK_ISBN_SIZE], book_t *b){
    int found = 0;  //flag
    FILE *fb;
    
    fb = fopen(BOOK_FILE, "rb");
    if(fb == NULL){
        return 0;
    }

    while ( fread(b, RECSIZE_BOOK, 1, fb) > 0){
            printf("check");          

        if(strcmp(b->isbn,isbn)){  
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

int book_update(book_t *b){
    
    book_t book_buff;
    
    int updated = 0;    //flag

    FILE *fb;
    fb = fopen(BOOK_FILE, "rb+");
    if(fb == NULL){
        return 0;
    }

    while( fread(&book_buff, RECSIZE_BOOK , 1, fb) > 0 ) {
        
        // if isbn is matching or not
        if(b->isbn == book_buff.isbn){
            
            //copies data to the respective fields.
            strcpy(book_buff.isbn, b->isbn);
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
