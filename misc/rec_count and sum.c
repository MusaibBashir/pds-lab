/*Write a recursive function to count the digits of a positive integer (do also for sum of digits)*/

#include <stdio.h>

int recursive_len(int num)
{
    int count,x;
    if(num==0)
    return 0;
    count=recursive_len(num/10);
    return count+1;
}

int recursive_sum(int num)
{
    int sum,x;
    if(num==0)
    return 0;
    x=recursive_sum(num/10);
    return x+=(num%10);
}

int main() {
    int num;
    printf("Enter Number: ");
    scanf("%d",&num);
    int len, sum;
    len=recursive_len(num);
    sum=recursive_sum(num);
    printf("No. of digits= %d\n", len);
    printf("Sum of digits= %d", sum);
    return 0;
}
