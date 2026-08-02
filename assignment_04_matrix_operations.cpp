// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


void readMatrix(int mat[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

void displayMatrix(int mat[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << mat[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int mat[10][10], int rows, int cols, int result[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = mat[i][j];
        }
    }
}

void addMatrices(int a[10][10], int b[10][10], int rows, int cols, int result[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrices(int a[10][10], int b[10][10], int m, int n, int p, int result[10][10]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    // ---------------- PART A: Transpose ----------------
    int matA[10][10], transposed[10][10], rowsA, colsA;
    cout << "PART A: Transpose a Matrix\n";
    cout << "Enter number of rows: ";
    cin >> rowsA;
    cout << "Enter number of columns: ";
    cin >> colsA;
    readMatrix(matA, rowsA, colsA);

    transposeMatrix(matA, rowsA, colsA, transposed);

    cout << "\nOriginal Matrix:\n";
    displayMatrix(matA, rowsA, colsA);
    cout << "Transposed Matrix:\n";
    displayMatrix(transposed, colsA, rowsA);

    // ---------------- PART B: Addition ----------------
    int matB1[10][10], matB2[10][10], sumResult[10][10], rowsB, colsB;
    cout << "\nPART B: Add Two Matrices\n";
    cout << "Enter number of rows: ";
    cin >> rowsB;
    cout << "Enter number of columns: ";
    cin >> colsB;

    cout << "Enter Matrix 1:\n";
    readMatrix(matB1, rowsB, colsB);
    cout << "Enter Matrix 2:\n";
    readMatrix(matB2, rowsB, colsB);

    addMatrices(matB1, matB2, rowsB, colsB, sumResult);

    cout << "\nSum of Matrices:\n";
    displayMatrix(sumResult, rowsB, colsB);

    // ---------------- PART C: Multiplication ----------------
    int matC1[10][10], matC2[10][10], productResult[10][10], m, n, n2, p;
    cout << "\nPART C: Multiply Two Matrices\n";
    cout << "Enter rows of Matrix A (M): ";
    cin >> m;
    cout << "Enter columns of Matrix A (N): ";
    cin >> n;
    cout << "Enter Matrix A:\n";
    readMatrix(matC1, m, n);

    cout << "Enter rows of Matrix B (must equal N = " << n << "): ";
    cin >> n2;
    cout << "Enter columns of Matrix B (P): ";
    cin >> p;
    cout << "Enter Matrix B:\n";
    readMatrix(matC2, n2, p);

    multiplyMatrices(matC1, matC2, m, n, p, productResult);

    cout << "\nProduct Matrix (A x B):\n";
    displayMatrix(productResult, m, p);

    return 0;
}