/*Find the number of times a certain pattern matches in a string*/
#include <stdio.h>

int pattern_match(char A[], char B[], int n, int m)
{
    int flag, count = 0;
    for (int i = 0; i < n; i++)
    {
        flag = 1;
        for (int j = 0; j < m; j++)
            if (A[i + j] != B[j])
                flag = 0;

        if (flag == 1)
            count++;
    }
    return count;
}

int main()
{
    char A[100], B[50];
    printf("Enter main string: ");
    scanf("%s", A);
    printf("Enter pattern: ");
    scanf("%s", B);
    int x, n, m;
    for (n = 0; A[n] != '\0'; n++);
    for (m = 0; B[m] != '\0'; m++);
    x = pattern_match(A, B, n, m);
    printf("Number of Pattern Matches: %d", x);
    return 0;
}
