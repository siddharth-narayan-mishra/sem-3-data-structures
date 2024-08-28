/**
 * @file matrix_diagonal_sum.c
 * @brief Calculates the sum of diagonal elements of a matrix with a randomly generated square matrix.
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
 * @brief Calculates sum of diagonal elements
 * @param matrix The matrix whose diagonal sum is to be calculated.
 * @param rows The number of rows in the matrix
 * @return int diagonalSum the sum of diagonal elements
 */
int calculateDiagonalSum(int matrix[MAX_ROWS][MAX_COLS],int rows){
    int diagonalSum = 0;
    for (int i = 0; i < rows; i++)
    {
        diagonalSum+=matrix[i][i];
    }
    return diagonalSum;
}

/**
 * @brief main function to calculate sum of diagonal elements
 * @return returns 0 on successful exit
 */
int main(){
    int matrix[MAX_ROWS][MAX_COLS];
    int rows;

    // Seed the random number generator
    srand(time(0));

    // Generate random dimensions for the matrix
    rows = generateRandomInt(MAX_ROWS - 1) + 1;  // Ensure at least 1 row

    // Generate and print the original matrix
    generateRandomMatrix(matrix, rows,rows);
    printf("Original Matrix (%d x %d):\n", rows,rows);
    printMatrix(matrix, rows,rows);

    //Calculate and print the sum of diagonal elements
    printf("Sum of diagonal elements = %d",calculateDiagonalSum(matrix,rows));
}
