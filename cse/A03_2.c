/*In number theory, a perfect number is a positive integer, where sum of its positive
divisors (excluding the number itself) is equal to the number itself. For example, 28 is a
perfect number where sum of its 1+2+4+7+14 = 28. [30 Marks]
Write a program in C consisting two user defined functions to print all perfect numbers in a
given range provided by the user through keyboard. Through main(), the user-defined
functions will be called for performing the task. The user-defined functions are given below:
a) Write a function checkPerfect(int x) that returns 1 if x is a perfect number else returns 0.
b) Write a function ListPerfectNumbers(int, int) that prints all the perfect numbers in the
range provided by the user.
The program should alert the user in case if the user provides an invalid input. The program
should not exit in case of invalid input. 
Example :
Input the range : 100 10000
The perfect numbers between 100 and 10000 are : 496 8128
Input the range : 100 -10000
Input Range is incorrect. Enter the correct range
The perfect numbers between 100 and 10000 are : 496 8128*/

#include <stdio.h>
int checkPerfect(int x){
    int i, sum=1;
    for (i=2; i<x; i++)
        if(x%i==0)
            sum+=i;
    if(sum==x)
    return 1;
    else
    return 0;
}
void ListPerfectNumbers(int a, int b){
    int j;
    for(j=a;j<=b;j++)
    if(checkPerfect(j))
    printf("%d ",j);
}

int main() {
    int p,q;
    printf("Enter Range: ");
    do
    {
        scanf("%d%d",&p,&q);
        if (p<0 || q<0)
        printf("\nEnter Correct Range: ");
    } while (p<0 || q<0);
    
    printf("\nThe perfect numbers between %d and %d are: ", p,q);
    ListPerfectNumbers(p,q);
    return 0;
}
