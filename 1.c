#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DAY_LENGTH 10
#define MAX_ACTIVITY_LENGTH 25

struct calElement {
    char day[MAX_DAY_LENGTH];      // Fixed-size array for day
    int date;
    char activity[MAX_ACTIVITY_LENGTH]; // Fixed-size array for activity
};

struct calElement* create() {
    struct calElement *calendar = malloc(sizeof(struct calElement) * 7);
    return calendar;
}

void read(struct calElement *calendar) {
    int i, date;
    for (i = 0; i < 7; i++) {
        printf("Enter the day: ");
        scanf("%s", calendar[i].day); // Directly store the day in the fixed-size array

        printf("Enter the date: ");
        scanf("%d", &date);
        calendar[i].date = date;

        getchar(); // Clear the newline character from the input buffer

        printf("Enter description of the activity: ");
        scanf("%s", calendar[i].activity); // Directly store the activity in the fixed-size array
    }
}

void display(struct calElement *calendar) {
    int i;
    printf("\n\nYour calendar\n");
    printf("Day\t\tDate\t\tActivity");
    // Display the calendar
    for (i = 0; i < 7; i++) {
        printf("\n%s\t\t%d\t\t%s", calendar[i].day, calendar[i].date, calendar[i].activity);
    }
}

int main() {
    struct calElement *calendar; // create structure variable of type pointer
    calendar = create(); // call create function
    read(calendar); // read function to read all inputs
    display(calendar); // Function to print calendar
    free(calendar); // Release the memory allocated dynamically
    return 0;
}