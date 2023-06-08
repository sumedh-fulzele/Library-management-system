# Library Management Case Study

## Software Engg
* SDLC -- Software Development Life Cycle -- Waterfall model
    * Requirement Analysis
        * Users (Owner, Librarian, Member)
        * Features (Use case diagrams)
        * Platform/Technology (C, File IO, Console application*, Windows/Linux).
    * Design
        * Architecture (3-tier applications)
            * Tier-1: Data handling
            * Tier-2: Business logic
            * Tier-3: User interfacing
        * Entities/Objects design
            * OOP - Class diagram
            * POP - Structures
                * struct user -- (id, name, email, password, phone, role)
                * struct book -- (isbn, title, author, category, price)
                * struct copy -- (id, rack, isbn, status)
                * struct issuerecord -- (id, copy_id, user_id, issue_date, due_date, return_date, fine_amount)
                * struct payment -- (id, user_id, amount, payment_date, type, next_payment_due_date) -- type = fees/fine
        * Database design
            * Relational DBMS - ER diagram
            * File IO - (Application Specific)
                * users.db -- struct user
                * payments.db -- struct payment
                * books.db -- struct book
                * copies.db -- struct copy
                * issuerecords.db -- struct issuerecords
        * Functionalities/Implementation
            * struct user
                * void user_accept(user_t *u); -- Tier-3
                * void user_print(user_t *u); -- Tier-3
                * int user_save(user_t *u); -- write (append) user in file -- Tier-1
                * user_update(); -- write (overwrite) user in file -- Tier-1
                * user_find_by_email(); -- find user from file -- Tier-1
                * user_find_by_id(); -- find user from file -- Tier-1
                * int user_get_max_id(); -- return last user id from file -- Tier-3
                * int user_authenticate(char email[], char passwd[], struct user *u); -- Tier-2
                * int user_register(user_t *u); -- assign max id+1 -- call user_save() -- Tier-2
                * int owner_register(user_t *u); -- delete users.db (if exists), id = 1, call user_save() -- Tier-2
                * int sign_in(); -- input email & passwd, call authenticate(), print welcome/failed -- Tier-3
                * void sign_up(); -- input details -- call user_register() -- Tier-3
                * void edit_profile(); -- input details -- call user_update() -- Tier-3
                * void change_passwd(); -- input details -- call user_update() -- Tier-3
            * ...
        * User interface design
            * Console application* -- Screenshots
                * Menu driven - Menus
                * Each menu - Input and Output
    * Implementation
        * cmd: ./main.exe --init
            * Database initialization
                * input owner details (id=1) and save into users.db
                    ```C
                    int main(int argc, char *argv[]) {
                        if(argc == 2 && strcmp(argv[1], "--init") == 0) {
                            user_t owner;
                            user_accept(&owner);
                            owner_register(&owner);
                            exit(0);
                        }

                        // menu-driven program
                    }
                    ```
        * cmd: ./main.exe
    * Testing
        * Unit testing
            * test each function
        * Integration testing
            * test functionality
        * main() -- for testing each functionality and then commit.
        * ...

### Day 07 Tasks
* Create new repository.
* Create Makefile
* Create main.c
* Create user.h -- struct user
* Create user_dal.h, user_dal.c -- Tier-1 user
* Create user_service.h, user_service.c -- Tier-2 user
* Create user_control.h, user_control.c -- Tier-3 user
* Create book.h -- struct book
* ...
