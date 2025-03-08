#include <stdio.h>
#include <string.h>
#include "DateFormat.h"

int CheckDate(int year, int month, int day) {
    if (year <= 0 || month < 1 || month > 12 || day < 1 || day > 31) {
        return 0;
    }
    
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) {
            return 0;
        }
    } else if (month == 2) {
        int isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        
        if (isLeapYear) {
            if (day > 29) {
                return 0;
            }
        } else {
            if (day > 28) {
                return 0;
            }
        }
    }
    return 1; 
}
int CheckRegionType(char type[]) {
    return (strcmp(type, "US") == 0 || strcmp(type, "UK") == 0 || strcmp(type, "TW") == 0);
}

const char* getDaySuffix(int day) {
    if (day % 10 == 1 && day != 11) {
        return "st";
    } else if (day % 10 == 2 && day != 12) {
        return "nd";
    } else if (day % 10 == 3 && day != 13) {
        return "rd";
    } else {
        return "th";
    }
}
const char* getMonthName(int month) {
    const char* months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    
    return months[month - 1];
}
void DateFormat(int year, int month, int day, char type[]) {
    if (strcmp(type, "US") == 0) {
        printf("The date \"%s %d%s, %d\" is in [US] format\n", 
               getMonthName(month), day, getDaySuffix(day), year);
    } else if (strcmp(type, "UK") == 0) {
        printf("The date \"%d%s %s, %d\" is in [UK] format\n", 
               day, getDaySuffix(day), getMonthName(month), year);
    } else if (strcmp(type, "TW") == 0) {
        printf("The date \"%d年%d月%d日\" is in [TW] format\n", 
               year, month, day);
    }
}
