/*Name= Musaib Bin Bashir
Roll No.= 24IM10047
Group No.= 1
PC No= 81
Description= "PDS Lab Section 04, Assignment 4"*/

#include <stdio.h>

int main()
{
    // part A
    int n;
    do
    {
        printf("Enter a number<11: ");
        scanf("%d", &n);
    } while (n < 1 || n >= 11);
    printf("n: %d\n", n);

    // part B
    int A[10];
    printf("Enter %d numbers: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    printf("A: ");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);

    // part C
    int evensum = 0, oddsum = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] % 2 == 0)
            evensum += A[i];
        else
            oddsum += A[i];
    }
    printf("\nEven Sum: %d and Odd Sum:%d", evensum, oddsum);

    // part D
    int pal = 1;
    for (int i = 0; i < (n + 1) / 2; i++)
        if (A[i] != A[n - i - 1]) // approaching from both ends we will check for inequality, because if number isn't palindrome we can break earlier using this
        {
            printf("\nNot Palindrome\n");
            pal = 0;
            break;
        }
    if (pal)
        printf("\nPalindrome\n");

    // part E
    printf("Circular Shift of A: ");
    int temp;
    temp = A[n - 1]; // I assigned first element to a temporary variable then using for loop shifted elements by 1 index and reassigned value of first element to last index
    for (int i = n-1; i>0; i--)
        A[i] = A[i-1];
    A[0] = temp;
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);

    // part F
    int B[10], flag = 0;
    printf("\nEnter %d numbers: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &B[i]);
    printf("B: ");
    for (int i = 0; i < n; i++)
        printf("%d ", B[i]);

    printf("\nPositions where elements of A are greater then corresponding elements of B: "); // corresponding as in same index
    for (int k = 0; k < n; k++)
    {
        if (A[k] > B[k])
        {
            printf("%d ", k + 1); //+1 because my interpretation of positions is natural numbers, i.e start from 1,2,3.. so I added 1 to index
            flag == 1;
        } // flag is used in case no element is greater
    }
    if (!flag)
        printf(" No such Position");

    // Part G
    int C[20];
    int ele, count = 0, rep; // count is used to store how many elements we have added in C
    for (int i = 0; i < n; i++)
    {
        rep = 0;
        ele = A[i];                     // first take each element in A one by one
        for (int j = 0; j < count; j++) // check if it already exists in C
            if (C[j] == ele)
            {
                rep = 1;
                break;
            }
        if (!rep) // if it does not exist already, then add it to C
        {
            C[count++] = ele;
        }
    }
    for (int p = 0; p < n; p++)
    { // The same logic used for A is used here
        rep = 0;
        ele = B[p];
        for (int q = 0; q < count; q++)
            if (C[q] == ele)
            {
                rep = 1;
                break;
            }
        if (!rep)
        {
            C[count++] = ele;
        }
    }
    printf("\nA union B is: ");
    for (int i = 0; i < count; i++)
        printf("%d ", C[i]);

    return 0;
}
