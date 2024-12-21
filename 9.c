#include <stdio.h>
#include <math.h>

typedef struct {
    int coeff;
    int pow_x;
    int pow_y;
    int pow_z;
} TERM;

void readTerm(TERM *term) {
    printf("Enter coeff and powers of x, y, z: ");
    scanf("%d %d %d %d", &term->coeff, &term->pow_x, &term->pow_y, &term->pow_z);
}

void printTerm(TERM term) {
    printf("%dx^%dy^%dz^%d", term.coeff, term.pow_x, term.pow_y, term.pow_z);
}

double evaluateTerm(TERM term, int x, int y, int z) {
    return term.coeff * pow(x, term.pow_x) * pow(y, term.pow_y) * pow(z, term.pow_z);
}

void addTerms(TERM term1, TERM term2, TERM *result) {
    if (term1.pow_x == term2.pow_x && term1.pow_y == term2.pow_y && term1.pow_z == term2.pow_z) {
        result->coeff = term1.coeff + term2.coeff;
        result->pow_x = term1.pow_x;
        result->pow_y = term1.pow_y;
        result->pow_z = term1.pow_z;
    } else {
        printf("Terms do not have the same powers, cannot add.\n");
    }
}

int main() {
    TERM poly1[2], poly2[2], polySum[2];
    int x, y, z, choice;

    while (1) {
        printf("\nMenu\n1: Evaluate Polynomial\n2: Add Polynomials\n3: Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                for (int i = 0; i < 2; i++) {
                    printf("Enter term %d for polynomial 1:\n", i + 1);
                    readTerm(&poly1[i]);
                }
                printf("Enter values of x, y, z: ");
                scanf("%d %d %d", &x, &y, &z);
                double result = 0;
                for (int i = 0; i < 2; i++) {
                    result += evaluateTerm(poly1[i], x, y, z);
                }
                printf("Result: %.2f\n", result);
                break;
            case 2:
                for (int i = 0; i < 2; i++) {
                    printf("Enter term %d for polynomial 1:\n", i + 1);
                    readTerm(&poly1[i]);
                }
                for (int i = 0; i < 2; i++) {
                    printf("Enter term %d for polynomial 2:\n", i + 1);
                    readTerm(&poly2[i]);
                }
                for (int i = 0; i < 2; i++) {
                    addTerms(poly1[i], poly2[i], &polySum[i]);
                }
                printf("Sum of Polynomials:\n");
                for (int i = 0; i < 2; i++) {
                    printTerm(polySum[i]);
                    if (i < 1) printf(" + ");
                }
                printf("\n");
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}