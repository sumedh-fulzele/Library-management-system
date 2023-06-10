#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"user.h"
#include"user_control.h"
#include"user_service.h"


int main(int argc, char *argv[]) {
    if(argc == 2 && strcmp(argv[1], "--init") == 0) {
        user_t owner;
        user_accept(&owner);
        
        if(owner_register(&owner) == 1){
            printf("Intialization is successful.\n");
        }
        exit(0);
    }


    return 0;
}