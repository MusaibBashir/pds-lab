/*Question 1: Write a C program to print the following pattern of numbers by giving the number of
rows N as input in the range 1 <= N <= 30. User is supposed to enter the number of rows as
positive odd integer within the specified range. In case of wrong entry, the program should
prompt the user about the error and suggest him/her to enter the correct input. The
program should not exit in case of invalid input.
e.x: N=5
    1 
  2 3 2
3 4 5 4 3
  2 3 2
    1
*/

#include <stdio.h>

int main() {
    int i,j,k,n,x=0;
    do
    {
        printf("Enter n, Should be odd: ");
        scanf("%d",&n);
    } while (n%2==0|| n>30 || n<1);
    
    printf("Pattern: \n");

    k=(n-1)/2; 
    for(i=1; i<=((n+1)/2);i++) //This loop is to print the increasing row part, e.g for n=5 it would print {(1),(2,3,2),(3,4,5,4,3)
        {
            for (j=0; j<=k-i; j++)
                printf("  "); // Space to align with upcoming rows
            x++; //because each row has to start with last+1
            for (j=x; j <x+i; j++) //This loop prints the increasing column part, e.g for n=5 it would print {(1),(2,3),(3,4,5)}
                printf("%d ",j); 
            for (j=i+x-2; j>=x; j--) //This loop prints the decreasing column part, e.g for n=5 it would print {(),(2),(4,3)}
                printf("%d ",j);  
            printf("\n");  
        }
    for(i=k; i>0;i--) //This loop is to print the decreasing row part, e.g for n=5 it would print {(2,3,2),(1)}
        {
            for (j=0; j<=k-i; j++)
                printf("  "); //Rest same logic as above
            x--; //now we have to do last-1
            for (j=x; j <x+i; j++)
                printf("%d ",j);
            for (j=i+x-2; j>=x; j--)
                printf("%d ",j);  
            printf("\n");  
        }
    
    return 0;
}
