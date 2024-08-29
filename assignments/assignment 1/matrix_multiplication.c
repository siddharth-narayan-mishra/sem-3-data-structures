/**
 * @file matrix_multiplication.c
 * @brief Multiplies two matrices which are input by the user.
 * @author Siddharth Narayan Mishra
 * @date August 28, 2024
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10

/**
 * @brief Reads a matrix from user input.
 *
 * @param matrix The 2D array to store the input matrix.
 * @param rows Number of rows in the matrix.
 * @param cols Number of columns in the matrix.
 */
void readMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
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
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief Multiplies two matrices.
 *
 * @param mat1 The first matrix.
 * @param rows1 Number of rows in the first matrix.
 * @param cols1 Number of columns in the first matrix.
 * @param mat2 The second matrix.
 * @param rows2 Number of rows in the second matrix.
 * @param cols2 Number of columns in the second matrix.
 * @param result The resulting matrix after multiplication.
 */
void multiplyMatrices(int mat1[MAX_ROWS][MAX_COLS], int rows1, int cols1,int mat2[MAX_ROWS][MAX_COLS], int rows2, int cols2, int result[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

/**
 * @brief Main function to demonstrate matrix multiplication.
 *
 * This function reads two matrices from user input, multiplies them,
 * and prints the resulting matrix.
 *
 * @return int 0 on successful execution, 1 if multiplication is not possible.
 */
int main() {
    int mat1[MAX_ROWS][MAX_COLS], mat2[MAX_ROWS][MAX_COLS], result[MAX_ROWS][MAX_COLS];
    int rows1, cols1, rows2, cols2;

    // Input dimensions for the first matrix
    printf("Enter dimensions of first matrix (rows columns): ");
    scanf("%d %d", &rows1, &cols1);

    // Input dimensions for the second matrix
    printf("Enter dimensions of second matrix (rows columns): ");
    scanf("%d %d", &rows2, &cols2);

    // Check if multiplication is possible
    if (cols1 != rows2) {
        printf("Matrix multiplication not possible.\n");
        return 1;
    }

    // Check if dimensions are within bounds
    if (rows1 > MAX_ROWS || cols1 > MAX_COLS || rows2 > MAX_ROWS || cols2 > MAX_COLS) {
        printf("Matrix dimensions exceed maximum allowed size.\n");
        return 1;
    }

    // Read the first matrix
    printf("For the first matrix:\n");
    readMatrix(mat1, rows1, cols1);

    // Read the second matrix
    printf("For the second matrix:\n");
    readMatrix(mat2, rows2, cols2);

    // Multiply the matrices
    multiplyMatrices(mat1, rows1, cols1, mat2, rows2, cols2, result);

    // Print the matrices and the result
    printf("\nFirst Matrix:\n");
    printMatrix(mat1, rows1, cols1);

    printf("\nSecond Matrix:\n");
    printMatrix(mat2, rows2, cols2);

    printf("\nResulting Matrix after multiplication:\n");
    printMatrix(result, rows1, cols2);

    return 0;
}
