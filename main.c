
#include <stdio.h>

// Check leap year
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) ||
           (year % 400 == 0);
}

// Get days in month
int daysInMonth(int month, int year) {
    int days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    if (month == 2 && isLeapYear(year)) {
        return 29;
    }

    return days[month];
}

// Get month name
void monthName(int month) {
    char *names[] = {
        "", "January", "February", "March", "April",
        "May", "June", "July", "August", "September",
        "October", "November", "December"
    };

    printf("\n       %s\n", names[month]);
}

// Print calendar
void printCalendar(int month, int year) {

    int y = year;
    int m = month;

    if (m < 3) {
        m += 12;
        y--;
    }

    int firstDay = (1 + (13 * (m + 1)) / 5 +
                    y + y / 4 - y / 100 + y / 400) % 7;

    // Convert Sunday-first to Monday-first
    firstDay = (firstDay + 5) % 7;

    monthName(month);
    printf("Mo Tu We Th Fr Sa Su\n");

    for (int i = 0; i < firstDay; i++) {
        printf("   ");
    }

    for (int i = 1; i <= daysInMonth(month, year); i++) {
        printf("%2d ", i);

        if ((i + firstDay) % 7 == 0) {
            printf("\n");
        }
    }

    printf("\n");
}

int main() {
    int month, year, choice;

    do {
        printf("\nEnter month (1-12): ");
        scanf("%d", &month);

        printf("Enter year: ");
        scanf("%d", &year);

        if (month < 1 || month > 12 || year < 1) {
            printf("\nInvalid month or year! Try again.\n");
        }
        else {
            printCalendar(month, year);
        }

        printf("\nDo you want another calendar? (1 = Yes, 0 = No): ");
        scanf("%d", &choice);

    } while (choice == 1);

    printf("\nThank you for using the calendar!");

    return 0;
}
