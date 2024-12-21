#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

int compute(char symbol, int op1, int op2) 
{
    switch(symbol) 
    {
        case '+': return op1 + op2;  // Perform addition
        case '-': return op1 - op2;  // Perform subtraction
        case '*': return op1 * op2;  // Perform multiplication
        case '/': return op1 / op2;  // Perform division
        case '%': return op1 % op2;  // Perform modulo
        case '$':  // Handle power using '$' as exponentiation operator
        case '^': return (int)pow(op1, op2);  // Compute power, cast to int
        default: return 0;  // Default case for unknown operators
    }
}

void main() 
{
    int s[20];  // Stack for operands
    int res;     // Holds partial or final result
    int op1, op2;  // Operands
    int top = -1;   // Stack pointer
    int i;          // Index for processing the expression
    char postfix[20];  // Input postfix expression
    char symbol;       // Scanned postfix symbol

    printf("Enter the postfix expression: ");
    scanf("%s", postfix);

    for(i = 0; i < strlen(postfix); i++) 
    {
        symbol = postfix[i];  // Get the current character
        if(isdigit(symbol))  // If it's a digit
        {
            s[++top] = symbol - '0';  // Convert char to int and push onto stack
        }
        else 
        {
            op2 = s[top--];  // Pop second operand
            op1 = s[top--];  // Pop first operand
            res = compute(symbol, op1, op2);  // Perform the operation
            s[++top] = res;  // Push result back onto the stack
        }
    }

    res = s[top];  // Final result will be at the top of the stack
    printf("The result is: %d\n", res);  // Print the final result
}