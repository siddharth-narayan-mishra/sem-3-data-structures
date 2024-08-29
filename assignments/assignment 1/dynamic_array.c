/**
 * @file dynamic_array.c
 * @brief Implements basic dynamic array operations: insert, delete, and search.
 * @author Siddharth Narayan Mishra
 * @date August 29, 2024
 */

#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 5

int *array;
int size = 0;
int capacity = INITIAL_CAPACITY;

/**
 * @brief Initializes the dynamic array.
 */
void initializeArray() {
    array = (int*)malloc(capacity * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
}

/**
 * @brief Resizes the array if it's full.
 */
void resizeIfNeeded() {
    if (size == capacity) {
        capacity *= 2;
        int *temp = (int*)realloc(array, capacity * sizeof(int));
        if (temp == NULL) {
            printf("Memory reallocation failed.\n");
            exit(1);
        }
        array = temp;
        printf("Array resized. New capacity: %d\n", capacity);
    }
}

/**
 * @brief Inserts an element at the end of the array.
 * @param element The element to be inserted.
 */
void insert(int element) {
    resizeIfNeeded();
    array[size++] = element;
    printf("%d inserted successfully.\n", element);
}

/**
 * @brief Deletes the last element from the array.
 */
void delete() {
    if (size > 0) {
        printf("%d deleted successfully.\n", array[--size]);
    } else {
        printf("Array is empty. Cannot delete.\n");
    }
}

/**
 * @brief Searches for an element in the array.
 * @param element The element to search for.
 * @return int The index of the element if found, -1 otherwise.
 */
int search(int element) {
    for (int i = 0; i < size; i++) {
        if (array[i] == element) {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Prints all elements in the array.
 */
void printArray() {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\nSize: %d, Capacity: %d\n", size, capacity);
}

/**
 * @brief Main function to demonstrate dynamic array operations.
 * @return int 0 on successful execution.
 */
int main() {
    initializeArray();

    int choice, element;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Print\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                insert(element);
                break;
            case 2:
                delete();
                break;
            case 3:
                printf("Enter element to search: ");
                scanf("%d", &element);
                int index = search(element);
                if (index != -1) {
                    printf("%d found at index %d.\n", element, index);
                } else {
                    printf("%d not found in the array.\n", element);
                }
                break;
            case 4:
                printArray();
                break;
            case 5:
                free(array);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
