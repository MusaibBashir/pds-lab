/*Read an integer n and using the '* character, print (a) a square of size n (b) an isosceles triangle of size n (c) a rectangle of size n by 2n (two kinds)*/

#include <stdio.h>

int main() {
    int n,i,j;

    printf("Enter an integer: ");
    scanf("%d", &n);

    // (a) Print a square of size n
    printf("\nSquare of size %d:\n", n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("* ");
        }
        printf("\n");
    }

    // (b) Print an isosceles triangle of size n
    printf("\nIsosceles triangle of size %d:\n", n);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }

    // (c) Print a rectangle of size n by 2n (case 1)
    printf("\nRectangle of size %d by %d:\n", n, 2 * n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < 2 * n; j++) {
            printf("* ");
        }
        printf("\n");
    }
    //case 2
     printf("\nRectangle of size %d by %d:\n", 2 * n,n);
    for (i = 0; i < 2*n; i++) {
        for (j = 0; j < n; j++) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}
