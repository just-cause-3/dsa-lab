#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to represent a term in the polynomial
typedef struct {
    int coeff;    // Coefficient of the term
    int pow_x;    // Power of x
    int pow_y;    // Power of y
    int pow_z;    // Power of z
} TERM;

// Structure for a node in the circular linked list
typedef struct Node {
    TERM info;      // Term information
    struct Node* next; // Pointer to the next node
} Node;

// Creates a new node with given term information
Node* CreateNode(TERM t) {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) { // Check for memory allocation failure
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    temp->info = t;
    temp->next = temp; // Make it circular
    return temp;
}

// Creates a header node for the polynomial
Node* CreateHeader() {
    TERM header = {-1, -1, -1, -1}; // Special values for header
    return CreateNode(header);
}

// Inserts a new term into the polynomial (circular linked list)
Node* Insert(Node* p, TERM t) {
    Node* temp = CreateNode(t);
    Node* cur = p;
    while (cur->next != p) {
        cur = cur->next;
    }
    cur->next = temp;
    temp->next = p;
    return p;
}

// Computes the value of a single term
double Compute(Node* node, int x, int y, int z) {
    TERM t = node->info;
    return t.coeff * pow(x, t.pow_x) * pow(y, t.pow_y) * pow(z, t.pow_z);
}

// Evaluates the polynomial for given x, y, z values
double Evaluate(Node* p, int x, int y, int z) {
    double sum = 0;
    Node* cur = p->next;
    while (cur != p) {
        sum += Compute(cur, x, y, z);
        cur = cur->next;
    }
    return sum;
}

// Displays a single term
void DisplayTerm(TERM t) {
    printf("%dx^%dy^%dz^%d", t.coeff, t.pow_x, t.pow_y, t.pow_z);
}

// Prints the entire polynomial
void PrintPolynomial(Node* p) {
    Node* cur = p->next;
    if (cur == p) { // Handle empty polynomial case
        printf("0\n");
        return;
    }
    while (cur != p) {
        DisplayTerm(cur->info);
        if (cur->next != p) printf(" + ");
        cur = cur->next;
    }
    printf("\n");
}

// Reads a polynomial from user input
void ReadPolynomial(Node* p, int n) {
    TERM t;
    for (int i = 0; i < n; ++i) {
        printf("Enter coefficient and powers of x, y, and z: ");
        scanf("%d %d %d %d", &t.coeff, &t.pow_x, &t.pow_y, &t.pow_z);
        p = Insert(p, t);
    }
    PrintPolynomial(p);
}

// Compares two terms for equality (based on powers)
int CompareTerms(TERM a, TERM b) {
    return a.pow_x == b.pow_x && a.pow_y == b.pow_y && a.pow_z == b.pow_z;
}

// Adds two terms (if they have the same powers)
TERM AddTerms(TERM a, TERM b) {
    a.coeff += b.coeff;
    return a;
}

// Adds two polynomials
Node* AddPolynomials(Node* p1, Node* p2) {
    Node* result = CreateHeader();
    Node* cur1 = p1->next;
    Node* cur2;

    while (cur1 != p1) {
        cur2 = p2->next;
        int matched = 0;
        while (cur2 != p2) {
            if (CompareTerms(cur1->info, cur2->info)) {
                result = Insert(result, AddTerms(cur1->info, cur2->info));
                matched = 1;
                break;
            }
            cur2 = cur2->next;
        }
        if (!matched) result = Insert(result, cur1->info);
        cur1 = cur1->next;
    }

    cur2 = p2->next;
    while (cur2 != p2) {
        cur1 = result->next;
        int matched = 0;
        while (cur1 != result) {
            if (CompareTerms(cur1->info, cur2->info)) {
                matched = 1;
                break;
            }
            cur1 = cur1->next;
        }
        if (!matched) result = Insert(result, cur2->info);
        cur2 = cur2->next;
    }

    return result;
}

int main() {
    Node* poly1 = CreateHeader();
    Node* poly2 = CreateHeader();
    Node* polySum;
    int choice, n, x, y, z;

    while (1) {
        printf("\nMenu:\n 1: Evaluate Polynomial\n 2: Add Polynomials\n 3: Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of terms in the polynomial: ");
                scanf("%d", &n);
                ReadPolynomial(poly1, n);
                printf("Enter the values of x, y, and z: ");
                scanf("%d %d %d", &x, &y, &z);
                printf("Result: %.2f\n", Evaluate(poly1, x, y, z));
                // Reset poly1 for next use
                poly1 = CreateHeader();
                break;

            case 2:
                printf("Enter the number of terms in polynomial 1: ");
                scanf("%d", &n);
                ReadPolynomial(poly1, n);

                printf("Enter the number of terms in polynomial 2: ");
                scanf("%d", &n);
                ReadPolynomial(poly2, n);

                polySum = AddPolynomials(poly1, poly2);
                printf("Sum of Polynomials: ");
                PrintPolynomial(polySum);
                // Free memory for polySum and reset poly1 and poly2
                free(polySum);
                poly1 = CreateHeader();
                poly2 = CreateHeader();
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
