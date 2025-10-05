// CodeAlpha_Task2_MatrixOperations.c
#include <stdio.h>

#define SIZE 10

void inputMatrix(int matrix[SIZE][SIZE], int rows, int cols);
void displayMatrix(int matrix[SIZE][SIZE], int rows, int cols);
void addMatrix(int A[SIZE][SIZE], int B[SIZE][SIZE], int result[SIZE][SIZE], int rows, int cols);
void multiplyMatrix(int A[SIZE][SIZE], int B[SIZE][SIZE], int result[SIZE][SIZE], int r1, int c1, int c2);
void transposeMatrix(int A[SIZE][SIZE], int result[SIZE][SIZE], int rows, int cols);

int main() {
    int A[SIZE][SIZE], B[SIZE][SIZE], result[SIZE][SIZE];
    int rows, cols, r1, c1, r2, c2;
    int choice;

    printf("===== MATRIX OPERATIONS =====\n");
    printf("1. Addition\n2. Multiplication\n3. Transpose\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter rows and columns for matrices: ");
            scanf("%d %d", &rows, &cols);
            printf("Enter elements of Matrix A:\n");
            inputMatrix(A, rows, cols);
            printf("Enter elements of Matrix B:\n");
            inputMatrix(B, rows, cols);
            addMatrix(A, B, result, rows, cols);
            printf("Resultant Matrix:\n");
            displayMatrix(result, rows, cols);
            break;

        case 2:
            printf("Enter rows and columns of Matrix A: ");
            scanf("%d %d", &r1, &c1);
            printf("Enter rows and columns of Matrix B: ");
            scanf("%d %d", &r2, &c2);
            if(c1 != r2) {
                printf("Matrix multiplication not possible!\n");
                return 0;
            }
            printf("Enter elements of Matrix A:\n");
            inputMatrix(A, r1, c1);
            printf("Enter elements of Matrix B:\n");
            inputMatrix(B, r2, c2);
            multiplyMatrix(A, B, result, r1, c1, c2);
            printf("Resultant Matrix:\n");
            displayMatrix(result, r1, c2);
            break;

        case 3:
            printf("Enter rows and columns of Matrix: ");
            scanf("%d %d", &rows, &cols);
            printf("Enter elements of Matrix:\n");
            inputMatrix(A, rows, cols);
            transposeMatrix(A, result, rows, cols);
            printf("Transpose of the Matrix:\n");
            displayMatrix(result, cols, rows);
            break;

        default:
            printf("Invalid choice!\n");
    }
    return 0;
}

void inputMatrix(int matrix[SIZE][SIZE], int rows, int cols) {
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            scanf("%d", &matrix[i][j]);
}

void displayMatrix(int matrix[SIZE][SIZE], int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

void addMatrix(int A[SIZE][SIZE], int B[SIZE][SIZE], int result[SIZE][SIZE], int rows, int cols) {
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            result[i][j] = A[i][j] + B[i][j];
}

void multiplyMatrix(int A[SIZE][SIZE], int B[SIZE][SIZE], int result[SIZE][SIZE], int r1, int c1, int c2) {
    for(int i=0; i<r1; i++)
        for(int j=0; j<c2; j++) {
            result[i][j] = 0;
            for(int k=0; k<c1; k++)
                result[i][j] += A[i][k] * B[k][j];
        }
}

void transposeMatrix(int A[SIZE][SIZE], int result[SIZE][SIZE], int rows, int cols) {
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            result[j][i] = A[i][j];
}