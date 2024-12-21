#include <stdio.h>
#include <stdlib.h>

#define MAX 10  // Size of the hash table

int create(int num) {
    return num % 10;  // this is a Hash function
}

void linear_prob(int a[MAX], int key, int num) {

    // If the calculated index is empty, insert the number
    if (a[key] == -1)
        a[key] = num;
                            else {
                                // Collision occurred, use linear probing
                                for (int i = (key + 1) % MAX; i != key; i = (i + 1) % MAX) {
                                    if (a[i] == -1) {
                                        a[i] = num;
                                        return;  // Inserted successfully
                                    }
                                }
                                // If we reach here, the table is full
                                printf("\nHash table is full\n");
                                exit(1);
                            }
}

void display(int a[MAX], int m) {
    printf("\nThe hash table is...\n");
    printf("Index\tEmployee ID\n");
    for (int i = 0; i < m; i++) {
        if (a[i] != -1) {  // Only display filled slots
            printf("%d\t%d\n", i, a[i]);
        }
    }
}

int main() {
    int a[MAX], num, key, choice;
    int m = 10;  // Size of the hash table function (can be changed)

    // Initialize the hash table
    for (int i = 0; i < m; i++) 
        a[i] = -1;

    do {
        printf("\nEnter the four-digit number: ");
        scanf("%d", &num);

        key = create(num);
        linear_prob(a, key, num);
        
        printf("Do you want to continue? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
    
    } while (choice == 1);
    
    display(a, m);
    return 0;
}