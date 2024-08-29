#include <stdio.h>
int lcm(int a, int b)
{
    int i,c;
    c=a>b?a:b;
    for(i=c; i<=a*b; i+=c)
        if(i%(a+b-c)==0)
            return i;
}

int main() {
    int x,y,q;
    printf("Enter a & b : \n");
    scanf("%d%d",&x,&y);
    q= lcm(x, y);
    printf("LCM of %d and %d is %d",x,y,q);
return 0;
}
