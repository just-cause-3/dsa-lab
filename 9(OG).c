#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
    int coeff, pow_x, pow_y, pow_z;
    struct Node* next;
} Node;

Node* CreateNode(int coeff, int pow_x, int pow_y, int pow_z) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->coeff = coeff;
    temp->pow_x = pow_x;
    temp->pow_y = pow_y;
    temp->pow_z = pow_z;
    temp->next = temp; // Circular linked list
    return temp;
}

Node* CreateHeader() {
    return CreateNode(0, -1, -1, -1); // Header node with dummy values
}

Node* Insert(Node* p, int coeff, int pow_x, int pow_y, int pow_z) {
    Node* temp = CreateNode(coeff, pow_x, pow_y, pow_z);
    Node* cur = p;
    while (cur->next != p) cur = cur->next;
    cur->next = temp;
    temp->next = p;
    return p;
}

void PrintPolynomial(Node* p) {
    Node* cur = p->next;
    while (cur != p) {
        printf("%dx^%dy^%dz^%d", cur->coeff, cur->pow_x, cur->pow_y, cur->pow_z);
        if (cur->next != p) printf(" + ");
        cur = cur->next;
    }
    printf("\n");
}

void ReadPolynomial(Node* p, int n) {
    int coeff, pow_x, pow_y, pow_z;
    for (int i = 0; i < n; ++i) {
        printf("Enter coeff and powers of x, y, z: ");
        scanf("%d %d %d %d", &coeff, &pow_x, &pow_y, &pow_z);
        Insert(p, coeff, pow_x, pow_y, pow_z);
    }
    PrintPolynomial(p);
}

int CompareTerms(Node* a, Node* b) {
    return a->pow_x == b->pow_x && a->pow_y == b->pow_y && a->pow_z == b->pow_z;
}

Node* AddPolynomials(Node* p1, Node* p2) {
    Node* result = CreateHeader();
    Node *cur1 = p1->next, *cur2;
    
    while (cur1 != p1) {
        cur2 = p2->next;
        int matched = 0;
        while (cur2 != p2) {
            if (CompareTerms(cur1, cur2)) {
                Insert(result, cur1->coeff + cur2->coeff, cur1->pow_x, cur1->pow_y, cur1->pow_z);
                matched = 1; break;
            }
            cur2 = cur2->next;
        }
        if (!matched) Insert(result, cur1->coeff, cur1->pow_x, cur1->pow_y, cur1->pow_z);
        cur1 = cur1->next;
    }
    
    cur2 = p2->next;
    while (cur2 != p2) {
        cur1 = result->next;
        int matched = 0;
        while (cur1 != result) {
            if (CompareTerms(cur1, cur2)) { matched = 1; break; }
            cur1 = cur1->next;
        }
        if (!matched) Insert(result, cur2->coeff, cur2->pow_x, cur2->pow_y, cur2->pow_z);
        cur2 = cur2->next;
    }
    
    return result;
}

int main() {
    Node *poly1 = CreateHeader(), *poly2 = CreateHeader(), *polySum;
    int choice, n;
    while (1) {
        printf("\nMenu:\n 1: Add Polynomials\n 2: Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter number of terms in polynomial 1: "); scanf("%d", &n);
                ReadPolynomial(poly1, n);
                printf("Enter number of terms in polynomial 2: "); scanf("%d", &n);
                ReadPolynomial(poly2, n);
                polySum = AddPolynomials(poly1, poly2);
                printf("Sum of Polynomials: ");
                PrintPolynomial(polySum);
                free(polySum);
                poly1 = CreateHeader();
                poly2 = CreateHeader();
                break;

            case 2:
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
    }
    return 0;
}
}
