/*Matrix Addition, Multiplication(square and non square), Transpose*/
#include <stdio.h>
void printMatrix(int A[][50], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }
}

void matrixSum(int A[][50], int B[][50], int C[][50], int m, int n)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void matrixProduct(int A[][50], int B[][50], int C[][50], int m, int n, int p)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

void matrixTranspose(int A[][50], int m, int n)
{
    int t;
    for (int i = 0; i < m; i++)
        for (int j = i + 1; j < n; j++)
        {
            t = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = t;
        }
}

int main()
{
    int m = 3, n = 3, p = 3;
    int A[50][50], B[50][50], C[50][50];
    printf("Enter Matrix A: ");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);
    printf("A: \n");
    printMatrix(A, m, n);
    printf("\nEnter Matrix B: ");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++)
            scanf("%d", &B[i][j]);
    printf("B: \n");
    printMatrix(B, n, p);
    matrixSum(A, B, C, m, n);
    printf("\nMatrix Sum (A+B): \n");
    printMatrix(C, m, n);
    printf("\nMatrix Product(A*B): \n");
    matrixProduct(A, B, C, m, n, p);
    printMatrix(C, m, p);
    matrixTranspose(A, m, n);
    printf("\nA Transpose: \n");
    printMatrix(A, m, n);
    return 0;
}
