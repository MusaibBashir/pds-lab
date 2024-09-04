/*Write a recursive function to convert a decimal number to binary*/

#include <stdio.h>

void binary(int n)
{
    if(n==0){
        printf("0");
        return;
    }
    binary(n/2);
    printf("%d",n%2);
}

int main() {
    int n;
    printf("Enter Number: ");
    scanf("%d",&n);
    printf("%d in Binary is: ", n);
    binary(n);
    return 0;
}
