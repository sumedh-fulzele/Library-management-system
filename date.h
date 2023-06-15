#ifndef __DATE_H
#define __DATE_H

#include<time.h>

typedef struct tm date_t; 

int date_diff(date_t date1, date_t date2, int *diff_in_days );
void adddays(date_t i_date, int days_to_add,date_t *d_date );

#endif