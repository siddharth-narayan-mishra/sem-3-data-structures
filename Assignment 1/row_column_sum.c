/**
 * @file row_column_sum.c
 * @brief Calculates the sum of each row and each column in a matrix.
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
 * @brief Calculates the sum of elements in a specific row of a matrix
 * @param matrix The original matrix
 * @param row The row whose sum of elements is to be calculated
 * @param cols The number of columns in the matrix
 * @return int rowSum the sum of elements in the row
 */
int rowSum(int matrix[MAX_ROWS][MAX_COLS],int row,int cols){
    int rowSum = 0;
    for (int i = 0; i < cols; i++)
    {
        rowSum+=matrix[row][i];
    }
    return rowSum;
}

/**
 * @brief Calculates the sum of elements in a specific column of a matrix
 * @param matrix The original matrix
 * @param col The column whose sum of elements is to be calculated
 * @param rows The number of rows in the matrix
 * @return int colSum the sum of elements in the column
 */
int colSum(int matrix[MAX_ROWS][MAX_COLS],int rows,int col){
    int colSum = 0;
    for (int i = 0; i < rows; i++)
    {
        colSum+=matrix[i][col];
    }
    return colSum;
}

/**
 * @brief Prints the sum of elements in each row
 * @param matrix The original matrix
 * @param rows The number of rows
 * @param cols The number of columns
 */
void printRowSums(int matrix[MAX_ROWS][MAX_COLS],int rows,int cols){
    for (int i = 0; i < rows; i++)
    {
        printf("Sum of row %d = %d\n",i+1,rowSum(matrix,i,cols));
    }
}

/**
 * @brief Prints the sum of elements in each column
 * @param matrix The original matrix
 * @param rows The number of rows
 * @param cols The number of columns
 */
void printColSums(int matrix[MAX_ROWS][MAX_COLS],int rows,int cols){
    for (int i = 0; i < cols; i++)
    {
        printf("Sum of column %d = %d\n",i+1,colSum(matrix,rows,i));
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

    //Print the sum of each row and column
    printRowSums(matrix,rows,cols);
    printColSums(matrix,rows,cols);

    return 0;
}
