/*Name= Musaib Bin Bashir
Roll No.= 24IM10047
Group No.= 1
PC No= 81
Description= "PDS Lab Section 04, Assignment 3"*/

#include<stdio.h>
float eval_f(float x,int n);
int _3rdlardig(int n);
int gcd(int a, int b);
int large_match(int n,int m,int k);
int digit_extract(int n, int r);

int main()
{
//Part a(i) Left Adjusted triangle
int i,j,k,n;
char a='a';
do{
    printf("Enter n: ");
    scanf("%d", &n);
}while(n>=11);
for(i=0; i<n;i++){
    for(j=0; j<=i; j++)
        printf("*");
    printf("\n");
    }
//(ii) Right Adjusted triangle
for(i=1;i<=n;i++)
{
    for(j=1;j<=n-i;j++)
        printf(" ");
    for(k=0; k<i; k++)
        printf("%c",a);
    a++;
    printf("\n");
}
//(iii) Diamond
int x;
x=2*n-1;
for(i=1; i<=n;i++)
{
    for(j=0;j<=n-i;j++)
        printf(" ");
    for(k=1; k<=2*i-1; k++)
        printf("*");
    printf("\n");
}
for(i=n-1;i>0;i--)
{
    for(j=0;j<=n-i;j++)
        printf(" ");
    for(k=1; k<=2*i-1; k++)
        printf("*");
    printf("\n");
}
//(iv) Left Adjusted Triangle Series
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
           if(i <= j){
                int k=i;
                while(k>0){
                    printf("*");
                    k--;
                }
                printf("\t");
           }
           else
            printf("\t");//row completion
        }
        printf("\n");//for new line after completing a row
    }
printf("\n");


//part B
int a1,b1,c1,g1,g2,g3;
printf("Enter 3 numbers: ");
scanf("%d%d%d",&a1,&b1,&c1);
g1=gcd(a1,b1);
g3=gcd(g1,c1);
printf("1st GCD is :%d \n",g3);
if(g3==1)
    printf("2nd GCD: 1\n");
else
{
    for(int num=g3-1; num>0; num--)
        if(g3%num==0)
    {
        printf("2nd GCD is: %d\n", num);
        break;
    }
}

//part c
int p;
do{
printf("Enter a number, should have more then or equal to 3 digits:  ");
scanf("%d",&n);
}while(n<100);
p=_3rdlardig(n);
printf("3rd Largest Digit of %d is : %d",n, p);
printf("\n");

//part d
float t,y;
do{
printf("Enter x(0<x<1) and n: ");
scanf("%f%d",&y,&n);
}while(y<0||y>1);
t=eval_f(y,n);
printf("Sum: %f\n",t);

//part e
int m,max_seq=0,length,curr_seq;
printf("Enter m, n: ");
scanf("%d%d",&m,&n);
length=digit_counter(n);
for(int i=1;i<=length;i++)
{
    curr_seq=large_match(n,m,i);
    printf("Max common subsequence of %d length is %d\n",i, curr_seq);
    if (curr_seq>max_seq)
        max_seq=curr_seq;
}
    
printf("Overall Max Common sub-sequence= %d\n", max_seq);
return 0;

}

float eval_f(float x,int n){
    float sum=1, current_term=1,abs_term;
    int term=0;
    printf("Interim Sum= %f, Term value=%f\n", sum, current_term);
    for(int i=1;i<n;i++)
    {
      current_term=((-1)*((2*(i)+1)*(current_term*x)))/(i+1);
      sum+=current_term;
      printf("Interim Sum= %0.9f, Term value=%0.9f \n", sum, current_term);
    }
    current_term=1;
    int j=1;
    do{
      current_term=(-1)*((2*(j)+1)*(current_term*x))/(j+1);
      if (current_term<0)
            abs_term=-1*current_term;
      else
        abs_term=current_term;
      term++;
      j++;
    }while(abs_term>0.0001);
    printf("S= %d\n",term);
    return sum;

}

int _3rdlardig(int n)
{
    int maxtemp1=0, maxtemp2=0, maxtemp3=0,dig;
    while(n!=0)
    {
       dig=n%10;
       n/=10;
       if(dig>=maxtemp1)
            {maxtemp3=maxtemp2;
            maxtemp2=maxtemp1;
            maxtemp1=dig;}
       else if(dig>=maxtemp2)
            {maxtemp3=maxtemp2;
            maxtemp2=dig;}
       else if(dig>maxtemp3)
            maxtemp3=dig;
    }
    return maxtemp3;
}

int gcd(int a,int b){
int t,d,q;
t=a+b;
a=a>b?a:b;
b=t-a;
if(b==0)
return a;
return gcd(b,a%b);
}

int large_match(int n,int m,int k){
    int z,ms,ns;
    int max=0,curr=0;
    while(n!=0)
    {
        z=m;
        ns=digit_extract(n,k);
        while (z!=0)
        {
            ms=digit_extract(z,k);
            if(ms==ns)
            curr=ns;
            if(curr>max)
            max=curr;
            z/=10;
        }
        n/=10;
    }
return max;
}
int digit_extract(int n, int r){
    int rdig=0,dig=0;
    while(r!=0){
        rdig=rdig*10+n%10;
        n/=10;
        r--;
    }
    while(rdig!=0){
        dig=dig*10+rdig%10;
        rdig/=10;
    }
return dig;
}
int digit_counter(int n){
    int count=0;
    while(n!=0)
    {
        n/=10;
        count++;
    }
return count;
}




