#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "list.h"

int generate_asc_key(char *string){
    int sum = 0;
    
    for (int i = 0; string[i] != '\0'; i++) {
        sum += (int)string[i];
    }

    return sum;
}

int hashfunction(int asc_key, int htable_size){
    return asc_key % htable_size;
}



void init_hashtable_category(int size_category_table, hashtable_category_t *hc){
    hc->size_category_table = size_category_table;
    hc->table = (list_category_t *)malloc(sizeof(list_category_t) * size_category_table);

    for(int i = 0; i < size_category_table; i ++){
        init_list_category(&hc->table[i]);
    }
}

void hc_insert(entry_category_t ec, hashtable_category_t *hc){
    // find the slot corresponding to key
    int slot = hashfunction(ec.asc_key, hc->size_category_table);
    
    if(!is_empty_list_category(&hc->table[slot]))
    {
        node_category_t *ret = search_node_category(ec.asc_key, &hc->table[slot]);
        
        if(ret != NULL)
        {
            (ret->data.value.count)= (ret->data.value.count) + 1;
            return;
        }
    }

    add_first_category(ec, &hc->table[slot]);
}

void free_hashtable_category(hashtable_category_t *hc){
    for(int i = 0; i < hc->size_category_table; i++){
        free_category_list(&hc->table[i]);
    }
    free_hashtable_category(hc);
}



void init_hashtable_book(int size_book_table, hashtable_book_t *hb){
    hb->size_book_table = size_book_table;
    hb->table = (list_book_t *)malloc(sizeof(list_book_t) * size_book_table);

    for(int i = 0; i < size_book_table; i ++){
        init_list_book(&hb->table[i]);
    }
}

void hb_insert(entry_book_t eb, hashtable_book_t *hb){
    // find the slot corresponding to key
    int slot = hashfunction(eb.asc_key, hb->size_book_table);
    
    // if(!is_empty_list_book(&hb->table[slot]))
    // {
    //     node_book_t *ret = search_node_book(eb.asc_key, &hb->table[slot]);
        
    //      if(ret != NULL)
    //      {
    //          (ret->data.value.count) = (ret->data.value.count) + 1;
    //     return;
    //      }
    // }

    add_first_book(eb, &hb->table[slot]);
}

void free_hashtable_book(hashtable_book_t *hb){
    for(int i = 0; i < hb->size_book_table; i++){
        free_book_report_list(&hb->table[i]);
    }
    free_hashtable_book(hb);
}
