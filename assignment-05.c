/*Name= Musaib Bin Bashir
Roll No.= 24IM10047
Group No.= 1
PC No= 81
Description= "PDS Lab Section 04, Assignment 5"*/

#include <stdio.h>

int search(int A[], int n, int r)
{
    for (int i = 0; i < n; i++)
        if (A[i] == r)
            return i;
    return -1;
}

void Countdup(int A[], int n)
{
    int printed[n], totalprinted = 0; //so that same line isn't printed again for duplicates we keep track of elements already counted for.
    for (int i = 0; i < n; i++)
    {
        if (search(printed, totalprinted, A[i]) == -1){
        int count = 0;
        for (int j = 0; j < n; j++)
            if (search(A, n, A[j]) == search(A, n, A[i]))
                count++;
        if (count > 1)
            printf("%d appears %d times\n", A[i], count);
        printed[totalprinted++] = A[i];
    }
}
}

int RemDup(int A[], int B[], int n)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (search(B, j, A[i]) == -1)
          B[j++] = A[i];
    }
    return j;
}

int recSearch(int A[], int start, int n, int r)
{
    if (n == 0)
        return -1;
    if (A[0] == r)
        return start;
    recSearch(A + 1, start + 1, n - 1, r);
}

int printed[10], totalprinted = 0; //due to being recursive function we have to make this global variable here, else it would remain 0 and array would be reinitialised at each step
void recCountdup(int A[], int n)
{
   if(n==0)
   return;
    if (search(printed, totalprinted, A[0]) == -1)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
            if (search(A, n, A[j]) == search(A, n, A[0]))
                count++;
        if (count > 1)
            printf("%d appears %d times\n", A[0], count);
        printed[totalprinted++] = A[0];
    }
    recCountdup(A + 1, n - 1);
}

int j=0;
void recRemDup(int A[], int C[], int n){
  if(n==0)
    return;
  if(search(C, j, A[0])== -1)
    C[j++]=A[0];
  recRemDup(A+1,C,n-1);
}

int main()
{
    int n, x, y, B[10],C[10];
    do
    {
        printf("Enter a number<11: ");
        scanf("%d", &n);
    } while (n < 1 || n >= 11);
    printf("n: %d\n", n);
    int A[10];
    printf("Enter %d numbers: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    int r;
    printf("Enter target number: ");
    scanf("%d", &r);
    x = search(A, n, r);
    if (x == -1)
        printf("Element not found\n");
    else
        printf("Element found at index %d\n", x);
    printf("Duplicates:\n");
    Countdup(A, n);
    int ele = RemDup(A, B, n);
    printf("B: ");
    for (int i = 0; i < ele; i++)
        printf("%d ", B[i]);
    printf("\n---Recursive Functions---");
    x = recSearch(A, 0, n, r);
    if (x == -1)
        printf("\nElement not found\n");
    else
        printf("\nElement found at index %d\n", x);
    printf("Duplicates:\n");
    recCountdup(A, n);
    recRemDup(A,C,n);
    printf("C: ");
    for (int i = 0; i < j; i++)
        printf("%d ", C[i]); 
    return 0;
}
