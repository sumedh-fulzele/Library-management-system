#ifndef __ISSUERECORD_SERVICE_H
#define __ISSUERECORD_SERVICE_H

int issuerecord_add(char isbn[BOOK_ISBN_SIZE], int member_id, int *issuerecord_id);
int issuerecord_edit(int issuerecord_id, book_copy_t *bc);

#endif