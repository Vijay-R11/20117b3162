#include <stdio.h>

#define MAX_TERMS 10

// Structure definition for polynomial terms
struct poly {
    int coeff; // Coefficient
    int expo;  // Exponent
};

// Function prototypes
int readPoly(struct poly []);
int addPoly(struct poly [], struct poly [], int, int, struct poly []);
void displayPoly(struct poly [], int terms);

int main() {
    struct poly p1[MAX_TERMS], p2[MAX_TERMS], p3[MAX_TERMS];
    int t1, t2, t3;

    // Read and display the first polynomial
    t1 = readPoly(p1);
    printf("\nFirst polynomial: ");
    displayPoly(p1, t1);

    // Read and display the second polynomial
    t2 = readPoly(p2);
    printf("\nSecond polynomial: ");
    displayPoly(p2, t2);

    // Add two polynomials and display the resultant polynomial
    t3 = addPoly(p1, p2, t1, t2, p3);
    printf("\nResultant polynomial after addition: ");
    displayPoly(p3, t3);
    printf("\n");

    return 0;
}

int readPoly(struct poly p[MAX_TERMS]) {
    int t1, i;
    printf("\nEnter the total number of terms in the polynomial (max %d): ", MAX_TERMS);
    scanf("%d", &t1);

    // Validate the number of terms
    if (t1 < 1 || t1 > MAX_TERMS) {
        printf("Invalid number of terms. Please enter a value between 1 and %d.\n", MAX_TERMS);
        return 0;
    }

    printf("\nEnter the COEFFICIENT and EXPONENT in DESCENDING ORDER\n");
    for (i = 0; i < t1; i++) {
        printf("Enter the Coefficient(%d): ", i + 1);
        scanf("%d", &p[i].coeff);
        printf("Enter the Exponent(%d): ", i + 1);
        scanf("%d", &p[i].expo);
    }
    return t1;
}

int addPoly(struct poly p1[MAX_TERMS], struct poly p2[MAX_TERMS], int t1, int t2, struct poly p3[MAX_TERMS]) {
    int i = 0, j = 0, k = 0;

    while (i < t1 && j < t2) {
        if (p1[i].expo == p2[j].expo) {
            p3[k].coeff = p1[i].coeff + p2[j].coeff;
            p3[k].expo = p1[i].expo;
            i++;
            j++;
        } else if (p1[i].expo > p2[j].expo) {
            p3[k].coeff = p1[i].coeff;
            p3[k].expo = p1[i].expo;
            i++;
        } else {
            p3[k].coeff = p2[j].coeff;
            p3[k].expo = p2[j].expo;
            j++;
        }
        k++;
    }

    // Add remaining terms from p1
    while (i < t1) {
        p3[k].coeff = p1[i].coeff;
        p3[k].expo = p1[i].expo;
        i++;
        k++;
    }

    // Add remaining terms from p2
    while (j < t2) {
        p3[k].coeff = p2[j].coeff;
        p3[k].expo = p2[j].expo;
        j++;
        k++;
    }

    return k; // k is the number of terms in the resultant polynomial
}

void displayPoly(struct poly p[MAX_TERMS], int term) {
    if (term == 0) {
        printf("0");
        return;
    }

    for (int k = 0; k < term - 1; k++) {
        printf("%d(x^%d) + ", p[k].coeff, p[k].expo);
    }
    printf("%d(x^%d)", p[term - 1].coeff, p[term - 1].expo);
}
