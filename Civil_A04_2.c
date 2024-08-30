/*Continued Fraction Question*/

#include <stdio.h>

int main() {
    long int a,b,t=0;
    printf("Enter the fraction: ");
    scanf("%d/%d", &a, &b);
    printf("[");
    printf("%d",a/b);
    a=a%b;
    if (a!=0)
    printf(";");
    while (a>1 && b!=0)
    {
        printf("%d", b/a);
        t=a;
        a=b%a;
        b=t;
        if (a>1)
        printf(","); //It would print comma only if there is gonna be a next term
        
    }
    if(!t) //In case we didn't enter loop, e.g 22.7= 3+1/7
        printf("%d",b/a); 
    else if (b!=0 && a==1) //Printing the last term outside loop to adjust comma
        printf(",%d", b);
    printf("]");
    return 0;
}
