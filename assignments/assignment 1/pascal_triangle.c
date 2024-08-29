/**
 * @file pascal_triangle.c
 * @brief Generates Pascal's triangle up to a given number of rows.
 * @author Siddharth Narayan Mishra
 * @date August 28, 2024
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 20

/**
 * @brief Generates Pascal's triangle up to the specified number of rows.
 *
 * @param triangle The 2D array to store Pascal's triangle.
 * @param rows Number of rows to generate.
 */
void generatePascalsTriangle(unsigned long long triangle[MAX_ROWS][MAX_ROWS], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                triangle[i][j] = 1;
            } else {
                triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
            }
        }
    }
}

/**
 * @brief Prints Pascal's triangle to the console.
 *
 * @param triangle The 2D array containing Pascal's triangle.
 * @param rows Number of rows to print.
 */
void printPascalsTriangle(unsigned long long triangle[MAX_ROWS][MAX_ROWS], int rows) {
    for (int i = 0; i < rows; i++) {
        // Print leading spaces for alignment
        for (int space = 0; space < rows - i - 1; space++) {
            printf("   ");
        }
        for (int j = 0; j <= i; j++) {
            printf("%6llu", triangle[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief Main function to demonstrate Pascal's triangle generation.
 *
 * This function prompts the user for the number of rows, generates
 * Pascal's triangle, and prints it to the console.
 *
 * @return int 0 on successful execution, 1 if input is invalid.
 */
int main() {
    unsigned long long triangle[MAX_ROWS][MAX_ROWS] = {0};
    int rows;

    printf("Enter the number of rows (max %d): ", MAX_ROWS);
    scanf("%d", &rows);

    if (rows <= 0 || rows > MAX_ROWS) {
        printf("Number of rows should be between 1 and %d.\n", MAX_ROWS);
        return 1;
    }

    generatePascalsTriangle(triangle, rows);
    printPascalsTriangle(triangle, rows);
    return 0;
}
