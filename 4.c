#include <stdio.h>
#include <ctype.h> // for isalnum() check

#define SIZE 20
char s[SIZE];
int top = -1;

// Push an element onto the stack
void push(char elem)
{
    s[++top] = elem;
}

// Pop an element from the stack
char pop()
{
    return (s[top--]);
}

// Function to determine the precedence of operators
int precedence(char elem) 
{
    switch (elem) 
    {
        case '#': return 0;
        case '(': return 1;
        case '+':
        case '-': return 2;
        case '*':
        case '/':
        case '%': return 3;
        case '$':
        case '^': return 4;
    }
    return -1; // Non-operators will return -1
}

// Main function to convert infix to postfix
void main()
{
    char infix[50], postfix[50], ch, elem;
    int i = 0, k = 0;

    // Read infix expression from the user
    printf("\nEnter the Infix Expression: ");
    scanf("%[^\n]", infix);  // Capture the full expression including spaces

    push('#');  // Push a special character to mark the end of the expression

    // Process each character in the infix expression
    while ((ch = infix[i++]) != '\0') 
    {
        if (ch == '(') 
            push(ch);

        else if (isalnum(ch)) 
            postfix[k++] = ch;

        else if (ch == ')') 
        {
            while (s[top] != '(') 
                postfix[k++] = pop();
            elem = pop();  // Remove the '(' from the stack
        } 
        else 
        {
            // Pop operators from stack with higher or equal precedence
            while (precedence(s[top]) >= precedence(ch)) 
                postfix[k++] = pop();
            push(ch);  // Push the current operator onto the stack
        }
    }

    // Pop any remaining operators from the stack
    while (s[top] != '#') 
    {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';  // Null-terminate the postfix expression

    // Output the results
    printf("\nGiven Infix Expression is: %s\n", infix);
    printf("\nPostfix Expression is: %s\n", postfix);
}