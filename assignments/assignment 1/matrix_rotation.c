/**
 * @file matrix_rotation.c
 * @brief Rotates a square matrix by 90 degrees clockwise.
 * @author Siddharth Narayan Mishra
 * @date August 28, 2024
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

/**
 * @brief Reads a square matrix from user input.
 *
 * @param matrix The 2D array to store the input matrix.
 * @param size Pointer to store the size of the matrix.
 */
void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int *size) {
    printf("Enter the size of the square matrix (max %d): ", MAX_SIZE);
    scanf("%d", size);

    if (*size <= 0 || *size > MAX_SIZE) {
        printf("Invalid size. Please enter a size between 1 and %d.\n", MAX_SIZE);
        exit(1);
    }

    printf("Enter the matrix elements:\n");
    for (int i = 0; i < *size; i++) {
        for (int j = 0; j < *size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

/**
 * @brief Prints a matrix to the console.
 *
 * @param matrix The matrix to be printed.
 * @param size Size of the square matrix.
 */
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief Rotates a square matrix 90 degrees clockwise.
 *
 * @param matrix The original matrix to be rotated.
 * @param rotated The resulting rotated matrix.
 * @param size Size of the square matrix.
 */
void rotateMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rotated[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            rotated[j][size - i - 1] = matrix[i][j];
        }
    }
}

/**
 * @brief Main function to demonstrate matrix rotation.
 *
 * This function reads a square matrix from user input, rotates it
 * 90 degrees clockwise, and prints both the original and rotated matrices.
 *
 * @return int 0 on successful execution.
 */
int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int rotated[MAX_SIZE][MAX_SIZE];
    int size;

    // Read the matrix from user input
    readMatrix(matrix, &size);

    // Print the original matrix
    printf("\nOriginal Matrix:\n");
    printMatrix(matrix, size);

    // Rotate the matrix
    rotateMatrix(matrix, rotated, size);

    // Print the rotated matrix
    printf("\nRotated Matrix (90 degrees clockwise):\n");
    printMatrix(rotated, size);

    return 0;
}
