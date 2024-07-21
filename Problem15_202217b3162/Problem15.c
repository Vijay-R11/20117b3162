#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linked List node
struct node {
    char* key;       // key is string
    char* value;     // value is also string
    struct node* next;
};

// Function to initialize a node
void setNode(struct node* node, char* key, char* value) {
    node->key = strdup(key);    // Allocate memory for key and copy
    node->value = strdup(value);// Allocate memory for value and copy
    node->next = NULL;
}

// Hash Map structure
struct hashMap {
    int numOfElements;  // Current number of elements in hashMap
    int capacity;       // Capacity of hashMap
    struct node** arr;  // Array of linked list (array of pointers)
};

// Function to initialize the hash map
void initializeHashMap(struct hashMap* mp, int capacity) {
    mp->capacity = capacity;
    mp->numOfElements = 0;
    mp->arr = (struct node**)malloc(capacity * sizeof(struct node*));
    for (int i = 0; i < capacity; i++) {
        mp->arr[i] = NULL;  // Initialize each bucket with NULL
    }
}

// Hash function to compute bucket index
int hashFunction(struct hashMap* mp, char* key) {
    unsigned long hash = 5381;
    int c;
    while ((c = *key++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash % mp->capacity;
}

// Function to insert a key-value pair into the hash map
void insert(struct hashMap* mp, char* key, char* value) {
    int bucketIndex = hashFunction(mp, key);
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    setNode(newNode, key, value);

    if (mp->arr[bucketIndex] == NULL) {
        mp->arr[bucketIndex] = newNode;
    } else {
        newNode->next = mp->arr[bucketIndex];
        mp->arr[bucketIndex] = newNode;
    }
    mp->numOfElements++;
}

// Function to delete a key-value pair from the hash map
void delete(struct hashMap* mp, char* key) {
    int bucketIndex = hashFunction(mp, key);
    struct node* prevNode = NULL;
    struct node* currNode = mp->arr[bucketIndex];

    while (currNode != NULL) {
        if (strcmp(key, currNode->key) == 0) {
            if (prevNode == NULL) {
                mp->arr[bucketIndex] = currNode->next;
            } else {
                prevNode->next = currNode->next;
            }
            free(currNode->key);
            free(currNode->value);
            free(currNode);
            mp->numOfElements--;
            return;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
}

// Function to search for a key in the hash map and return its value
char* search(struct hashMap* mp, char* key) {
    int bucketIndex = hashFunction(mp, key);
    struct node* bucketHead = mp->arr[bucketIndex];

    while (bucketHead != NULL) {
        if (strcmp(bucketHead->key, key) == 0) {
            return bucketHead->value;
        }
        bucketHead = bucketHead->next;
    }

    char* errorMssg = "Oops! No data found.\n";
    return errorMssg;
}

// Driver code
int main() {
    struct hashMap* mp = (struct hashMap*)malloc(sizeof(struct hashMap));
    initializeHashMap(mp, 100);  // Initialize with capacity 100

    insert(mp, "Yogaholic", "Anjali");
    insert(mp, "pluto14", "Vartika");
    insert(mp, "elite_Programmer", "Manish");
    insert(mp, "GFG", "BITS");
    insert(mp, "decentBoy", "Mayank");

    printf("%s\n", search(mp, "elite_Programmer"));
    printf("%s\n", search(mp, "Yogaholic"));
    printf("%s\n", search(mp, "pluto14"));
    printf("%s\n", search(mp, "decentBoy"));
    printf("%s\n", search(mp, "GFG"));
    printf("%s\n", search(mp, "randomKey")); // Key not inserted

    printf("\nAfter deletion : \n");
    delete(mp, "decentBoy");
    printf("%s\n", search(mp, "decentBoy")); // Key deleted

    return 0;
}
