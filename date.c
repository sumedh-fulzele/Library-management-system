#include <stdio.h>
#include <time.h>
#include"date.h"

//date should be adjusted like below.
// year - 1900
// month (0 - 11)
// day of the month (1 - 31)


int date_diff(date_t date1, date_t date2 ){
    
    time_t time1 = mktime(&date1);
    time_t time2 = mktime(&date2);

    double diff_in_seconds = difftime(time1, time2);
    int diff_in_days = (int)(diff_in_seconds / (24 * 3600));

    return diff_in_days;
}

void adddays(date_t i_date, int days_to_add,date_t *d_date ) {
    i_date.tm_mday += days_to_add;

    while (i_date.tm_mday > days_in_month(i_date.tm_mon, i_date.tm_year)) {
        i_date.tm_mday -= days_in_month(i_date.tm_mon, i_date.tm_year);
        i_date.tm_mon++;

        if (i_date.tm_mon > 11) {
            i_date.tm_mon = 0;
            i_date.tm_year++;
        }
    }
    d_date->tm_year = i_date.tm_year;
    d_date->tm_mon  = i_date.tm_mon;
    d_date->tm_mday = i_date.tm_mday;
}

int is_leap_year(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1;
    return 0;
}

int days_in_month(int month, int year) {
    const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = daysInMonth[month];

    if (month == 1 && is_leap_year(year))
        days++;

    return days;
}