#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

void getCofactor(float mat[SIZE][SIZE], float temp[SIZE][SIZE], int p, int q, int n);
float determinant(float mat[SIZE][SIZE], int n);
void adjoint(float mat[SIZE][SIZE], float adj[SIZE][SIZE]);
int inverse(float mat[SIZE][SIZE], float inv[SIZE][SIZE]);

void printMatrix(float mat[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            printf("%f ", mat[i][j]);
        printf("\n");
    }
}

int main() {
    float mat[SIZE][SIZE] = {
        {6, 1, 1},
        {4, -2, 5},
        {2, 8, 7}
    };

    float inv[SIZE][SIZE]; // To store the inverse matrix

    printf("Input matrix is:\n");
    printMatrix(mat);

    if (inverse(mat, inv)) {
        printf("\nThe inverse matrix is:\n");
        printMatrix(inv);
    } else {
        printf("Inverse doesn't exist\n");
    }

    return 0;
}

// Function to get cofactor of mat[p][q] in temp[][]. n is the current dimension of mat[][]
void getCofactor(float mat[SIZE][SIZE], float temp[SIZE][SIZE], int p, int q, int n) {
    int i = 0, j = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp[i][j++] = mat[row][col];
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

// Recursive function for finding determinant of matrix. n is current dimension of mat[][]
float determinant(float mat[SIZE][SIZE], int n) {
    float det = 0;
    if (n == 1)
        return mat[0][0];

    float temp[SIZE][SIZE];
    int sign = 1;

    for (int f = 0; f < n; f++) {
        getCofactor(mat, temp, 0, f, n);
        det += sign * mat[0][f] * determinant(temp, n - 1);
        sign = -sign;
    }
    return det;
}

// Function to calculate adjoint of mat[SIZE][SIZE] in adj[SIZE][SIZE].
void adjoint(float mat[SIZE][SIZE], float adj[SIZE][SIZE]) {
    if (SIZE == 1) {
        adj[0][0] = 1;
        return;
    }

    int sign = 1;
    float temp[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            getCofactor(mat, temp, i, j, SIZE);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj[j][i] = (sign) * (determinant(temp, SIZE - 1));
        }
    }
}

// Function to calculate and store inverse, returns 1 if successful, 0 if not
int inverse(float mat[SIZE][SIZE], float inv[SIZE][SIZE]) {
    float det = determinant(mat, SIZE);
    if (det == 0) {
        printf("Singular matrix, can't find its inverse");
        return 0;
    }

    float adj[SIZE][SIZE];
    adjoint(mat, adj);

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            inv[i][j] = adj[i][j] / det;

    return 1;
}
