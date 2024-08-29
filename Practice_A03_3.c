//Write a function to compute the sin(x) series for n terms. Call it in the main function. Make sure it runs for large n
#include <stdio.h>
float sin_to_r_terms(int x, int r)
{
    float sum=0, newterm;
    sum=newterm=x;
    int parity=1;
    for(int i=1; i<=r;i++)
    {
        newterm=(-1)*((newterm*x*x)/((2*i+1)*(2*i))); 
        sum+=newterm;
    }
    return sum;
}

int main() {
    float q;
    int x,n;
    printf("Enter the value of x in radian for which sin(x) is to be calculated: \n");
    scanf("%d",&x);
    printf("Enter the number of terms: \n");
    scanf("%d",&n);
    q= sin_to_r_terms(x, n);
    printf("%0.12f",q);
return 0;
}
