#include <stdio.h>

#define TRUE 1
#define FALSE 0

// Function to check if a year is a leap year
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return TRUE;
    return FALSE;
}

// Function to get the first day of the year
int getFirstDayOfYear(int year) {
    int day = (year * 365 + (year / 4) - (year / 100) + (year / 400)) % 7;
    return day;
}

// Function to print the calendar for a given year
void printCalendar(int year) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char *months[] = {"January", "February", "March", "April", "May", "June",
                      "July", "August", "September", "October", "November", "December"};

    int firstDay = getFirstDayOfYear(year);

    // Adjust February days for leap years
    if (isLeapYear(year))
        daysInMonth[1] = 29;

    printf("\n===== Calendar for Year %d =====\n", year);

    for (int i = 0; i < 12; i++) {
        printf("\n  -------- %s --------\n", months[i]);
        printf(" Sun Mon Tue Wed Thu Fri Sat\n");

        // Print leading spaces
        for (int j = 0; j < firstDay; j++)
            printf("    ");

        // Print the days of the month
        for (int day = 1; day <= daysInMonth[i]; day++) {
            printf("%4d", day);
            if (++firstDay > 6) {  // Move to a new line after Saturday
                firstDay = 0;
                printf("\n");
            }
        }
        printf("\n");
    }
}

int main() {
    int year;
    printf("Enter a year: ");
    scanf("%d", &year);

    printCalendar(year);
    return 0;
}