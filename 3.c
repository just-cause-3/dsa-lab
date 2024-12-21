#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 5

int stack[MAX], top = -1, item;

// Function to check if stack is full
int IsFull() 
{
    if (top >= MAX - 1)
        return 1;
    return 0;
}

// Function to check if stack is empty
int IsEmpty() 
{
    if (top == -1)
        return 1;
    return 0;
}

// Function to push an element to the stack
void push(int item) 
{
    if (IsFull()) {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = item;
}

// Function to pop an element from the stack (now void)
void pop() 
{
    if (IsEmpty()) {
        printf("Stack Underflow\n");
        return;
    }
    top--; // Simply decrement the top to remove the item
}

// Function to display the elements of the stack
void display() 
{
    int i;
    if (IsEmpty()) {
        printf("Stack is Empty\n");
        return;
    }
    printf("\nThe elements of the stack are:");
    for (i = top; i >= 0; i--)
        printf("\n%d", stack[i]);
}

// Function to check if the stack contains a palindrome number
void check_pal() 
{
    int num = 0, revnum = 0, temp, temp_top = top;
    
    // Build the number from stack elements
    while (temp_top != -1) 
    {
        int temp_item = stack[temp_top];
        num = num * 10 + temp_item; // Form the number
        temp_top--;
    }

    temp=num;

    // Reverse the number
    while (temp != 0) 
    {
        revnum = revnum * 10 + (temp % 10);
        temp /= 10;
    }

    printf("\nOriginal Number: %d\n", num);
    printf("Reversed Number: %d\n", revnum);

    // Compare the original number with the reversed number
    if (num == revnum)
        printf("The stack contains a Palindrome number\n");
    else
        printf("The stack does not contain a Palindrome number\n");
}

// Main function to drive the program
int main() 
{
    int ch;

    do 
    {
        printf("\n1. Push \n2. Pop \n3. Display\n4. Check Palindrome\n5. Exit\n");
        printf("\nEnter the choice: ");
        scanf("%d", &ch);

        switch (ch) 
        {
            case 1:
                printf("\nEnter the element to be inserted: ");
                scanf("%d", &item);
                push(item);
                break;

            case 2:
                pop();  // Now no need to print the popped item here
                break;

            case 3:
                display();
                break;

            case 4:
                check_pal();
                break;

            case 5:
                printf("Program Terminated\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    } 
    while (1);
    
    return 0;
}
