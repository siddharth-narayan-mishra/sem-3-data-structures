/**
 * @file matrix_transpose.c
 * @brief Demonstrates matrix transposition with a randomly generated matrix.
 * @author Siddharth Narayan Mishra
 * @date August 28, 2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define MAX_VALUE 100

/**
 * @brief Generates a random integer within a specified range.
 *
 * @param max The upper bound of the range (exclusive).
 * @return int A random integer between 0 and max-1.
 */
int generateRandomInt(int max) {
    return rand() % max;
}

/**
 * @brief Generates a random matrix with the specified dimensions.
 *
 * @param matrix The 2D array to store the generated matrix.
 * @param rows Number of rows in the matrix.
 * @param cols Number of columns in the matrix.
 */
void generateRandomMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = generateRandomInt(MAX_VALUE);
        }
    }
}

/**
 * @brief Prints a matrix to the console.
 *
 * @param matrix The matrix to be printed.
 * @param rows Number of rows in the matrix.
 * @param cols Number of columns in the matrix.
 */
void printMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief Transposes a given matrix.
 *
 * @param matrix The original matrix.
 * @param transposed The resulting transposed matrix.
 * @param rows Number of rows in the original matrix.
 * @param cols Number of columns in the original matrix.
 */
void transposeMatrix(int matrix[MAX_ROWS][MAX_COLS], int transposed[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

/**
 * @brief Main function to demonstrate matrix transposition.
 *
 * This function creates a random matrix, prints it, transposes it,
 * and then prints the transposed matrix.
 *
 * @return int 0 on successful execution.
 */
int main() {
    int matrix[MAX_ROWS][MAX_COLS];
    int transposed[MAX_ROWS][MAX_COLS];
    int rows, cols;

    // Seed the random number generator
    srand(time(0));

    // Generate random dimensions for the matrix
    rows = generateRandomInt(MAX_ROWS - 1) + 1;  // Ensure at least 1 row
    cols = generateRandomInt(MAX_COLS - 1) + 1;  // Ensure at least 1 column

    // Generate and print the original matrix
    generateRandomMatrix(matrix, rows, cols);
    printf("Original Matrix (%d x %d):\n", rows, cols);
    printMatrix(matrix, rows, cols);

    // Transpose and print the matrix
    transposeMatrix(matrix, transposed, rows, cols);
    printf("\nTransposed Matrix (%d x %d):\n", cols, rows);
    printMatrix(transposed, cols, rows);

    return 0;
}
