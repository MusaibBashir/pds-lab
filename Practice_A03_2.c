/*Write a function to read an integer n and find the largest two-digit integer that is part of n. For example for n = 864913 the answer is 91. Test it in the main function*/

#include<stdio.h>
int larg_two(int i)
{
    int temp,dig1=0,dig2=0, max=0, current;
    temp=i;
    dig1=temp%10;
    temp/=10;
    while(temp!=0)
    {
        dig2=dig1;
        dig1=temp%10;
        temp/=10;
        current=(dig1*10)+dig2;
        if (current>max)
        max=current;
    }
    return max;
}
int main()
{
   int n,x;
   scanf("%d",&n);
   x=larg_two(n);
   printf("%d",x);
   return 0;
}
