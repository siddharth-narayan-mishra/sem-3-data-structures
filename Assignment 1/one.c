/**
 * @file array_reversal.c
 * @brief Demonstrates various array operations including randomization and reversal.
 * @author Siddharth Narayan Mishra
 * @date August 28, 2024
 *
 * This file contains functions to generate random integers and demonstrate array reversal.
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**
 * @brief Prints all elements of an integer array.
 *
 * @param arr The array to be printed.
 * @param l The length of the array.
 */
void printArray(int arr[], int l) {
    for (int i = 0; i < l; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * @brief Generates a random integer within a specified range.
 *
 * @param max The upper bound of the range (inclusive).
 * @return int A random integer between 1 and max.
 */
int generateRandomInt(int max) {
    return rand() % max + 1;
}

/**
 * @brief Fills an array with random integers within a specified range.
 *
 * @param arr The array to be filled.
 * @param l The length of the array.
 * @param range The upper bound for random numbers (inclusive).
 */
void randomiseArrayIntegers(int arr[], int l, int range) {
    for (int i = 0; i < l; i++) {
        arr[i] = generateRandomInt(range);
    }
}

/**
 * @brief Reverses the order of elements in an array.
 *
 * This function uses a two-pointer approach to swap elements
 * from the start and end of the array, moving towards the center.
 *
 * @param arr The array to be reversed.
 * @param l The length of the array.
 */
void reverseArray(int arr[], int l) {
    int i = 0;
    int j = l - 1;
    while (i < j) {
        // Swap elements without using a separate function
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}

/**
 * @brief Main function to demonstrate array operations.
 *
 * This function creates an array of random length, fills it with
 * random integers, prints it, reverses it, and prints it again.
 *
 * @return int 0 on successful execution, 1 if memory allocation fails.
 */
int main() {
    // Set seed for random number generation
    srand(time(0));

    // Generate an array of random length (1 to 10)
    int length = generateRandomInt(10);
    int *arr = malloc(length * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Fill the array with random integers (range: 1 to 1000)
    randomiseArrayIntegers(arr, length, 1000);

    // Print the original array
    printf("Randomised array:\n");
    printArray(arr, length);

    // Reverse and print the array
    printf("Reversing the array:\n");
    reverseArray(arr, length);
    printArray(arr, length);

    // Free allocated memory
    free(arr);

    return 0;
}
