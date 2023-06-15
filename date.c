#include <stdio.h>
#include <time.h>

int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1;
    return 0;
}

int getDaysInMonth(int month, int year) {
    const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = daysInMonth[month];

    if (month == 1 && isLeapYear(year))
        days++;

    return days;
}

int main() {
    struct tm date1 = {0};
    struct tm date2 = {0};

    date1.tm_year = 123; // year - 1900
    date1.tm_mon = 4;    // month (0 - 11)
    date1.tm_mday = 15;  // day of the month (1 - 31)

    date2.tm_year = 122; // year - 1900
    date2.tm_mon = 3;    // month (0 - 11)
    date2.tm_mday = 10;  // day of the month (1 - 31)

    time_t time1 = mktime(&date1);
    time_t time2 = mktime(&date2);

    double differenceInSeconds = difftime(time1, time2);
    int differenceInDays = (int)(differenceInSeconds / (24 * 3600));

    int years = date1.tm_year - date2.tm_year;
    int months = date1.tm_mon - date2.tm_mon;
    int days = date1.tm_mday - date2.tm_mday;

    if (days < 0) {
        months--;
        days += getDaysInMonth(date2.tm_mon, date2.tm_year);
    }

    if (months < 0) {
        years--;
        months += 12;
    }

    printf("Difference: %d years, %d months, %d days\n", years, months, days);
    printf("Difference in seconds: %.0f\n", differenceInSeconds);
    printf("Difference in days: %d\n", differenceInDays);

    return 0;
}
