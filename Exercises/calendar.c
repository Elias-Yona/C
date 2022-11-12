/*===================================================================================
 *         FILE: calendar.c
 *
 *        USAGE: gcc calendar.c -o calendar
 *               windows: calendar
 *               linux: ./calendar
 * 
 *  DESCRIPTION: Displays the current day of the week, the number of days in the current
 *              month and the current time. The program will work until the year 2099 is
 *              reached. The current day of the month is highlighted in red
 * 
 *      OPTIONS: ---
 * REQUIREMENTS: ---
 *         BUGS: ---
 *        NOTES: ---
 *       AUTHOR: Group C
 *      COMPANY: St. Pauls University 
 *      VERSION: 1.0
 *      CREATED: 2022-11-11 - 2022-11-12
 *     REVISION: --
 * ===================================================================================
*/

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

void display(int month, int month_date, int current_year);
int* month(char day[], char month[]);
void days(int end, int current, char current_year[], char month_name[]);
int startDay(int year, int month);
int monthName(char month_name[]);
void printDays(int end, int current, int offset);

int main() {
    char week_day[10], month_name[10], month_day[10], current_time[10], current_year[10];
    int index = 0;
    int* month_date;
    char date_time[50];

    time_t t;
    time(&t);

    strcpy(date_time, ctime(&t));
    char* token = strtok(date_time, " ");

    while(token != NULL) {
        index++;
        switch (index) {
            case 1:
                strcpy(week_day, token);
                break;
             case 2:
                strcpy(month_name, token);
                break;
             case 3:
                strcpy(month_day, token);
                break;
             case 4:
                strcpy(current_time, token);
                break;
             case 5:
                strcpy(current_year, token);
                break;
        }
        token = strtok(NULL, " ");
    }

    month_date = month(month_day, month_name);
            
    printf("\033[1;32m");
    printf("%s %s %s %s %s\n", week_day, month_name, month_day, current_time, current_year);
    printf("\033[0m");
    display(month_date[0], month_date[1], atoi(current_year));

    return 0;
}

/*
 * Function:  display 
 * --------------------
 * displays the current month with its days in a labelled format
 * 
 *
 *  month:          the month number according to the calendar. e.g. 1
 *  month_date:     the day of the month. e.g. 14
 *  current_year:   the year e.g. 2022
 *
 *  returns: nothing
 */
void display(int month, int month_date, int current_year) {
    int width = 15;
    char week_days[] = "sun mon tue wed thu fri sat\n";
    char current_year_str[5];
    sprintf(current_year_str, "%d", current_year);

    switch (month) {
        case 1:
            printf("%*s\n", width, "Jan");
            printf("---------------------------\n");
            printf("%s", week_days);
            days(31, month_date, current_year_str, "Jan");
            break;
        case 2:
            printf("%*s\n", width, "Feb");
            printf("---------------------------\n");
            printf("%s", week_days);
            if ((current_year % 4) == 0) {
                days(29, month_date, current_year_str, "Feb");
            } else {
                days(28, month_date, current_year_str, "Feb");
            }
            break;
        case 3:
            printf("%*s\n", width, "Mar");
            printf("---------------------------\n");
            printf("%s", week_days);
            days(31, month_date, current_year_str, "Mar");
            break;
        case 4:
            printf("%*s\n", width, "Apr");
            printf("---------------------------\n");
            printf("%s", week_days);
            days(30, month_date, current_year_str, "Apr");
            break;
        case 5:
            printf("%*s\n", width, "May");
            printf("---------------------------\n");
            printf("%s", week_days);
            days(31, month_date, current_year_str, "May");
            break;
        case 6:
            printf("%*s\n", width, "Jun");
            printf("---------------------------\n");
            printf("%s", week_days);
            days(30, month_date, current_year_str, "Jun");
            break;
        case 7:
            printf("%*s\n", width, "Jul");
            printf("---------------------------\n");
            printf("%s", week_days);
            days(31, month_date, current_year_str, "Jul");
            break;
        case 8:
            printf("%*s\n", width, "Aug");
            printf("---------------------------\n");
            printf("%s", week_days);
            days(31, month_date, current_year_str, "Aug");
            break;
        case 9:
            printf("%*s\n", width, "Sep");
            printf("---------------------------\n");
            printf("%s", week_days);
            days(30, month_date, current_year_str, "Sep");
            break;
        case 10:
            printf("%*s\n", width, "Oct");
            printf("---------------------------\n");
            printf("%s", week_days);
            days(31, month_date, current_year_str, "Oct");
            break;
        case 11:
            printf("%*s\n", width, "Nov");
            printf("---------------------------\n");
            printf("%s", week_days);
            days(30, month_date, current_year_str, "Nov");
            break;
        case 12:
            printf("%*s\n", width, "Dec");
            printf("---------------------------\n");
            printf("%s", week_days);
            days(31, month_date, current_year_str, "Dec");
            break;
        default:
            printf("Month not found");
    }
}

/*
 * Function:  month 
 * --------------------
 * Translates month name to its integer equivalent and day into a string
 * The two variables are then compacted into an array
 * 
 *  day:    day in string form e.g "14"
 *  month   month in string form e.g. "Jan"
 *
 *  returns: an array consisting of day and month
 */
int* month(char day[], char month[]) {
    static int month_date[] = {0, 0}; // month, day
    if (strcmp(month, "Jan") == 0) {
        month_date[0] = 1;
    } else if (strcmp(month, "Feb") == 0) {
        month_date[0] = 2;
    } else if (strcmp(month, "Mar") == 0) {
        month_date[0] = 3;
    } else if (month == "Apr") {
        month_date[0] = 4;
    } else if (strcmp(month, "May") == 0) {
        month_date[0] = 5;
    } else if (strcmp(month, "Jun") == 0) {
        month_date[0] = 6;
    } else if (strcmp(month, "Jul") == 0) {
        month_date[0] = 7;
    } else if (strcmp(month, "Aug") == 0) {
        month_date[0] = 8;
    } else if (strcmp(month, "Sep") == 0) {
        month_date[0] = 9;
    } else if (strcmp(month, "Oct") == 0) {
        month_date[0] = 10;
    } else if (strcmp(month, "Nov") == 0) {
        month_date[0] = 11;
    } else {
        month_date[0] = 12;
    }

    month_date[1] = atoi(day);

    return month_date;
}

/*
 * Function: days
 * --------------------
 * Prints out the days of the month with the correct offset for day 1
 * 
 *  end:            number of days in the month. e.g. 31
 *  current:        the current day of the month. e.g. 14
 *  current_year    the current year. e.g. "2022"
 *  month_name      the name of the month. e.g. "Jan"
 *
 *  returns: nothing
 */
void days(int end, int current, char current_year[], char month_name[]) {
    char placeholder[] = "";
    int width = 0;
    int day = startDay(atoi(current_year), monthName(month_name));
    switch (day) {
        case 1:
            printf("%*s", width, placeholder);
            printDays(end, current, day);
            break;
        case 2:
            printf("%*s", width + 4, placeholder);
            printDays(end, current, day);
            break;
        case 3:
            printf("%*s", width + (4 * 2), placeholder);
            printDays(end, current, day);
            break;
        case 4:
            printf("%*s", width + (4 * 3), placeholder);
            printDays(end, current, day);
            break;
        case 5:
            printf("%*s", width + (4 * 4), placeholder);
            printDays(end, current, day);
            break;
        case 6:
            printf("%*s", width + (4 * 5), placeholder);
            printDays(end, current, day);
            break;
        case 7:
            printf("%*s", width + (4 * 6), placeholder);
            printDays(end, current, day);
            break;
    }
}

/*
 * Function: startDay
 * --------------------
 * Displays the day of the week to put day 1 of the month. Calculations
 * are based on the years 2000-2099
 * 
 *  year:   the year e.g. 2022
 *  month:  the month. e.g. 1  
 *
 *  returns: the day of the week as an integer
 */
int startDay(int year, int month) {
    int jan, feb;
    int mar = 4, apr = 0, may = 2, jun = 5, jul = 0, aug = 3, sep = 6, oct = 1, nov = 4, dec = 6;
    char year_str[10];
    int last_two_digits_of_year, day_of_month, key_number, sum, rem;
    double one_quarter_of_two_digits;
    char digits_temp[2];

    if ((year % 4) == 0) {
        jan = 0;
        feb = 3;
    } else {
        jan = 1;
        feb = 4;
    }

    itoa(year, year_str, 10);
    sprintf(digits_temp, "%c%c", year_str[2], year_str[3]);
    last_two_digits_of_year = atoi(digits_temp);
    one_quarter_of_two_digits = (0.25 * last_two_digits_of_year);
    day_of_month = 1;

    switch(month) {
        case 1:
            key_number = jan;
            break;
        case 2:
            key_number = feb;
            break;
        case 3:
            key_number = mar;
            break;
        case 4:
            key_number = apr;
            break;
        case 5:
            key_number = may;
            break;
        case 6:
            key_number = jun;
            break;
        case 7:
            key_number = jul;
            break;
        case 8:
            key_number = aug;
            break;
        case 9:
            key_number = sep;
            break;
        case 10:
            key_number = oct;
            break;
        case 11:
            key_number = nov;
            break;
        case 12:
            key_number = dec;
            break;
    }
    sum = (last_two_digits_of_year + day_of_month + one_quarter_of_two_digits + key_number) - 1;
    rem = sum % 7;
    return rem;
}

/*
 * Function: monthName
 * --------------------
 * Displays the integer equivalent of a given month
 * 
 *  month_name:   the month as a string. e.g. "Jan"
 *
 *  returns: the integer representation of the month
 */
int monthName(char month_name[]) {
    int num_rep = 0;

   if (strcmp(month_name, "Jan") == 0) {
        num_rep = 1;
    } else if (strcmp(month_name, "Feb") == 0) {
        num_rep = 2;
    } else if (strcmp(month_name, "Mar") == 0) {
        num_rep = 3;
    } else if (strcmp(month_name, "Apr") == 0) {
        num_rep = 4;
    } else if (strcmp(month_name, "May") == 0) {
        num_rep = 5;
    } else if (strcmp(month_name, "Jun") == 0) {
        num_rep = 6;
    } else if (strcmp(month_name, "Jul") == 0) {
        num_rep = 7;
    } else if (strcmp(month_name, "Aug") == 0) {
        num_rep = 8;
    } else if (strcmp(month_name, "Sep") == 0) {
        num_rep = 9;
    } else if (strcmp(month_name, "Oct") == 0) {
        num_rep = 10;
    } else if (strcmp(month_name, "Nov") == 0) {
        num_rep= 11;
    } else {
        num_rep = 12;
    } 

    return num_rep;
}

/*
 * Function: printDays
 * --------------------
 * Displays the days of the month that are well aligned according to
 * given offset. The offset is the day of the week in which day 1 of the
 * month started.
 * 1 - sunday
 * 2 - monday
 * 3 - wednesday
 * 4 - thursday
 * 5 - friday
 * 6 - saturday
 * 7 - sunday
 * 
 *  end:   the number of days in the month. e.g. 31
 *  current: the current day of the month. e.g. 12
 *  int offset: the day of the week that was day 1 of the month. e.g. 1
 *
 *  returns: the day of the week that was day 1 of the month as an integer
 */
void printDays(int end, int current, int offset) {
    int count = offset;

    for (int i = 1; i <= end; ++i) {
        count++;
        if (i < 10) {
            if (i == current) {
                printf("\033[1;31m");
                printf("  %d ", i);
                printf("\033[0m");
            } else {
                printf("  %d ", i);
            } 
        } else {
            if (i == current) {
                printf("\033[0;31m");
                printf(" %d ", i);
                printf("\033[0m");
            } else {
                printf(" %d ", i);
            } 
        }
        
        if (count == 8) {
            printf("\n");
            count = 1;
        } 
    }
}
