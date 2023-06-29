#include <stdio.h>
#include "book.h"
#include "book_list.h"
#include "book_service.h"
#include "hashtable.h"
#include "entry.h"

void book_accept(book_t *b){
    printf("\nEnter the book details.");
    printf("\nTitle \t\t: ");
    scanf("%[^\n]", b->title );
    printf("Author \t\t: ");
    scanf("%*c%[^\n]", b->author );
    printf("ISBN \t\t: ");
    scanf("%*c%[^\n]", b->isbn);
    printf("Category \t: ");
    scanf("%*c%[^\n]", b->category);
    scanf("%*c");
    printf("Price \t\t: ");
    scanf("%f", &b->price);
    
}

void book_print(book_t *b){
    printf("| %14s | %-60s| %-25s | %-20s|%8.2f |\n", b->isbn, b->title, b->author, b->category, b->price);
}

void book_category_report_print(entry_category_t *ec){
    printf("| %-40s|%6d |\n", ec->value.book_category, ec->value.count);

}

void book_report_print(entry_book_t *eb){
    printf("| %14s | %-60s|%8d |%8d |\n", eb->value.isbn, eb->value.title, eb->value.total_count, eb->value.total_avail);
}

void add_new_book(){
    book_t b;
    int rack;
    book_accept(&b);
    printf("Rack No. \t: ");
    scanf("%d", &rack);
    getchar();
    int flag_add = book_add(&b) && book_copy_add(b.isbn, rack);
    if( flag_add == 1){
        printf("\nBook is successfully added..!!\n");
        book_press_any_key();
    }
    else{
        printf("\nFailed to add book\n");
        book_press_any_key();
    }
}

void find_book_by_isbn(){
    book_t  b;
    char isbn[BOOK_ISBN_SIZE];
    printf("\nEnter the ISBN of the book which you wish to search : ");
    scanf("%[^\n]",isbn);
    getchar();
    if(book_search_by_isbn(isbn, &b) == 1){
        printf("\nBook Found..!!\n");
        printf("+----------------+-------------------------------------------------------------+---------------------------+---------------------+---------+\n");
        printf("|  ISBN13        | Title                                                       | Author                    | Category            |  Price  |\n");
        printf("+----------------+-------------------------------------------------------------+---------------------------+---------------------+---------+\n");
        book_print(&b);
        printf("+----------------+-------------------------------------------------------------+---------------------------+---------------------+---------+\n");
        book_press_any_key();
    }
    else{
        printf("\nBook Not Found..!!");
        book_press_any_key();
    }
}

void find_book_by_title(){

    char title[BOOK_TITLE_SIZE];
    book_list_t bl;

    printf("\e[1;1H\e[2J");
    printf("\e[2J");
    printf("\e[2J");
    
    printf("Enter the title of the book : ");
    scanf("%[^\n]",title);
    getchar();
   
    if(book_search_by_title(title, &bl) == 1){
        printf("\nSearch Results :\n");
        printf("+----------------+-------------------------------------------------------------+---------------------------+---------------------+---------+\n");
        printf("|  ISBN13        | Title                                                       | Author                    | Category            |  Price  |\n");
        printf("+----------------+-------------------------------------------------------------+---------------------------+---------------------+---------+\n");

        book_node_t *trav = bl.head;
        while(trav != NULL)
        {
            //2. print data of current(trav) node
            book_print(&trav->data);
            //3. go on next node
            trav = trav->next;
        }//4. repeat step 2 and 3 till last node (trav != NULL)
        free_book_list(&bl);
        printf("+----------------+-------------------------------------------------------------+---------------------------+---------------------+---------+\n");
        book_press_any_key();        
    }
    else{
        printf("\nBook not found..!!\n");
        book_press_any_key();
    }

}

void edit_book(){
    book_t b;
    printf("Enter new details of the book except ISBN :");
    book_accept(&b);
    getchar();
    if(book_edit(&b) == 1){
        printf("\nBook updated successfully..!!");
        book_press_any_key();
    }
    else{
        printf("Failed to edit book..!!");
        book_press_any_key();
    }
}

void book_copy_accept(char isbn[BOOK_ISBN_SIZE], int *rack){
    printf("\nEnter Book Copy details..");
    printf("\nEnter the ISBN of the book \t: ");
    scanf("%[^\n]", isbn);
    printf("\nEnter the rack number \t: ");
    scanf("%d", rack);

}

void add_new_book_copy(){
    char isbn[BOOK_ISBN_SIZE];
    int rack;
    book_copy_accept(isbn, &rack);
    getchar();
    if(book_copy_add(isbn, rack) == 1){
        printf("\nBook Copy added in the library..!!\n");
        book_press_any_key();
    }
    else{
        printf("\nFailed to add book copy\n");
        book_press_any_key();
    }
}

void change_rack(){
    book_copy_t bc;
    int book_copy_id;
    int rack;
    
    printf("\nEnter the ID of Book copy \t: ");
    scanf("%d", &book_copy_id);
    printf("\nEnter the new rack number \t: ");
    scanf("%d", &rack);
    getchar();
    
    if(book_copy_change_rack(book_copy_id, rack,  &bc) == 1){
        printf("\nRack of book copy with ID %d changed successfully..!!\n", book_copy_id);
        book_press_any_key();
    }
    else{
        printf("\nFailed to change rack..!!\n");
        book_press_any_key();
    }
}

void check_book_availability(){
    char isbn[BOOK_ISBN_SIZE] = {0};

    printf("\nEnter the ISBN of the book \t: ");
    scanf("%s", isbn);
    getchar();

    int avail = book_copy_available(isbn);
    if( avail == 1){
        printf("\nBook is available..!!\n");
        book_press_any_key();
    }
    else if(avail == 2){
        printf("\nBook is available but all the copies are issued..!!\n");
        book_press_any_key();
    }
    else{
        printf("\nBook is unavailable..!!\n");
        book_press_any_key();
    }
}

void book_categories_report(){
    hashtable_category_t hc;
    int hashtable_category_size = 11;
    
    init_hashtable_category(hashtable_category_size, &hc);

    if(get_category_list(&hc) == 1){
        printf("\e[1;1H\e[2J");
        printf("\e[2J");
        printf("\e[2J");
        printf("\nBook Report (Categorywise) :\n");
        printf("+-----------------------------------------+-------+\n");
        printf("| Book Category                           | Count |\n");
        printf("+-----------------------------------------+-------+\n");
        
        for(int i = 0; i < hashtable_category_size; i++){
                
                if(hc.table[i].head == NULL){
                    continue;
                }
    
                node_category_t *trav = hc.table[i].head;
                while (trav != NULL)
                {
                    book_category_report_print(&trav->data);
                    trav = trav->next;
                }
                 
        }
        printf("+-----------------------------------------+-------+\n");
        book_press_any_key();
    }
    else{
        printf("\nError while generating report..!!");
        book_press_any_key();
    }
}

void book_report(){
    hashtable_book_t hb;
    int hashtable_book_size = 11;
    
    init_hashtable_book(hashtable_book_size, &hb);

    if(get_book_list(&hb) == 1){
        printf("\e[1;1H\e[2J");
        printf("\e[2J");
        printf("\e[2J");
        printf("\nBook Report :\n");
        printf("+----------------+-------------------------------------------------------------+---------+---------+\n");
        printf("|    ISBN13      |   TITLE                                                     |  Total  |Available|\n");
        printf("+----------------+-------------------------------------------------------------+---------+---------+\n");
    
        for(int i = 0; i < hashtable_book_size; i++){
        
                if(hb.table[i].head == NULL){
                    continue;
                }   
                node_book_t *trav = hb.table[i].head;
                while (trav != NULL)
                {
                    book_report_print(&trav->data);
                    trav = trav->next;
                }
        }
        printf("+----------------+-------------------------------------------------------------+---------+---------+\n");
        book_press_any_key();
    }
    else{
        printf("\nError while generating report..!!");
        book_press_any_key();
    }
}

void book_press_any_key(){
    printf("\nPress Enter the continue...");
    getchar();
}