#include <stdio.h>
#include <stdlib.h> // Include for exit()
#define MAX 10

// Function prototypes
void create();
void insert();
void deletion();
void search();
void display();

int b[MAX]; // Array to hold the list elements
int n = 0;  // Current number of elements in the list

int main() {
    int ch;
    char g = 'y';

    do {
        printf("\nMain Menu");
        printf("\n1. Create");
        printf("\n2. Delete");
        printf("\n3. Search");
        printf("\n4. Insert");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("\nEnter the correct choice:");
        }

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &g); // Note the space before %c to consume any newline character
    } while (g == 'y' || g == 'Y');

    return 0; // Return 0 to indicate successful completion
}

void create() {
    printf("\nEnter the number of nodes (max %d): ", MAX);
    scanf("%d", &n);

    if (n > MAX) {
        printf("Cannot create more than %d elements.\n", MAX);
        n = MAX; // Limit n to MAX
    }

    for (int i = 0; i < n; i++) {
        printf("Enter the Element %d: ", i + 1);
        scanf("%d", &b[i]);
    }
}

void deletion() {
    int pos;
    printf("\nEnter the position you want to delete (0 to %d): ", n - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= n) {
        printf("\nInvalid Location.\n");
    } else {
        for (int i = pos; i < n - 1; i++) {
            b[i] = b[i + 1];
        }
        n--;
        printf("\nThe Elements after deletion:\n");
        display();
    }
}

void search() {
    int e;
    printf("\nEnter the Element to be searched: ");
    scanf("%d", &e);
    int found = 0;

    for (int i = 0; i < n; i++) {
        if (b[i] == e) {
            printf("Value %d is in the position %d.\n", e, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Value %d is not in the list.\n", e);
    }
}

void insert() {
    int pos, p;
    printf("\nEnter the position you need to insert (0 to %d): ", n);
    scanf("%d", &pos);

    if (pos < 0 || pos > n || n >= MAX) {
        printf("\nInvalid Location or list is full.\n");
    } else {
        for (int i = n; i > pos; i--) {
            b[i] = b[i - 1];
        }
        printf("Enter the element to insert: ");
        scanf("%d", &p);
        b[pos] = p;
        n++;
        printf("\nThe list after insertion:\n");
        display();
    }
}

void display() {
    printf("\nThe Elements of The list are:");
    for (int i = 0; i < n; i++) {
        printf("\n%d", b[i]);
    }
    printf("\n");
}
