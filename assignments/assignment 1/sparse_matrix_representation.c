/**
 * @file sparse_matrix_representation.c
 * @brief Demonstrates sparse matrix representation with a randomly generated matrix.
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
 * @brief Count the number of non-zero elements in a matrix.
 *
 * @param matrix The original matrix
 * @param rows The number of rows in the original matrix
 * @param cols The number of columns in the original matrix
 * @return an integer for the number of non-zero elements in the matrix.
 */
int countNonZeroElements(int matrix[MAX_ROWS][MAX_COLS],int rows, int cols){
    int nonZeroElements = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j])
            {
                nonZeroElements++;
            }
        }
    }
    return nonZeroElements;
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
 * @brief Prints the sparse matrix
 * @param nonZeroElemnts number of non zero elements, also the number of elements in the sparse matrix
 * @param sparseMatrix the sparse matrix
 */
void printSparseMatrix(int nonZeroElements,int sparseMatrix[3][nonZeroElements]){
    printf("Row Column Value\n");
    for (int i = 0; i < nonZeroElements; i++)
    {
        printf("%3d %6d %5d \n",sparseMatrix[0][i],sparseMatrix[1][i],sparseMatrix[2][i]);
    }

}

/**
 * @brief Generates sparse matrix
 * @param matrix The original matrix
 * @param
 */
void generateSparseMatrix(int nonZeroElements,int matrix[MAX_ROWS][MAX_COLS],int sparseMatrix[3][nonZeroElements],int rows, int cols){
    int k = 0;
    for (int i = 0; i < rows; i++)
    {
       for (int j = 0; j < cols; j++)
       {
            if (matrix[i][j])
            {
               sparseMatrix[0][k]=i+1;
               sparseMatrix[1][k]=j+1;
               sparseMatrix[2][k]=matrix[i][j];
               k++;
            }
       }
    }
    printSparseMatrix(nonZeroElements,sparseMatrix);
}

/**
 * @brief Main function to make sparse matrix.
 *
 * This function creates a random matrix, prints it, then prints it's sparse matrix,
 *
 * @return int 0 on successful execution.
 */

int main(){
    int matrix[MAX_ROWS][MAX_COLS];
    int sparseMatrix[3][MAX_COLS*MAX_ROWS];
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

    //Count the number of non-zero elements in the matrix
    int nonZeroElements = countNonZeroElements(matrix,rows,cols);

    //Generate and print the sparse matrix
    generateSparseMatrix(nonZeroElements,matrix,sparseMatrix,rows,cols);
}
