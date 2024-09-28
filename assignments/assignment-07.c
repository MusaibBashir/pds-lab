/*Name= Musaib Bin Bashir
Roll No.= 24IM10047
Group No.= 1
PC No= 81
Description= "PDS Lab Section 04, Assignment 7"*/

#include<stdio.h>

void maxMin(int A[],int n) //since we have to return 4 values the best method is to implement a sort, here i implemented a bubble sort
{
int min_idx,temp;
for(int i=0;i<n;i++){
    min_idx=i;
    for(int j=i+1;j<n;j++){
            if(A[i]>A[j]){
            temp=A[j];
            A[j]=A[i];
            A[i]=temp;
    }
    }
    }
}

void maxmin2(int A[], int n, int *max1, int *max2,int *min1, int *min2){
for(int i=0;i<n;i++){
    if(A[i]>*max1)
{
    *max2=*max1;
    *max1=A[i];
}
    else if(A[i]>*max2)
        *max2=A[i];
    else if(A[i]<*min1)
    {
        *min2=*min1;
        *min1=A[i];
    }
    else if(A[i]<*min2)
        *min2=A[i];
}
}

void swapMaxMin(int A[], int n){
int max=0, min=0,temp; //keep two seperate variables to track indexes of max and min values
for(int i=1; i<n; i++)
{
    if(A[i]>A[max]) // if value is larger then the already set max
        max=i; //update index of max
    else if (A[i]<A[min]) // if value is smaller then already set min
        min=i;//update value of min
}
temp=A[max]; //swapping using extra variable temp
A[max]= A[min];
A[min]=temp;
}

void shiftArray(int A[], int n, int k){
int temparray[k];
for(int i=0; i<k;i++)//first we make a temporary array which stores the values which have to come in the front of the array
    temparray[i]=A[n-1-i];
for(int i=0;i<n-k;i++)
    A[n-i-1]=A[(n-k-1)-i];//then we shift remaining array to right
for(int i=0;i<k;i++)
    A[i]=temparray[k-1-i];//then we bring the values from temp array back to main array
}

int main(){
    int n;

    //part a
    do{
        printf("Enter n: ");
        scanf("%d",&n);
    }while(n<1 || n>20);

    int A[n];
    printf("Enter Array A: ");
    for(int i=0;i<n;i++)
        scanf("%d",&A[i]);
    printf("A: ");
    for(int i=0;i<n;i++)
        printf("%d ",A[i]);

    //part b- sir's method.
    int mx1=A[0],mx2=A[0],m1=A[0],m2=A[0];
    int *max1=&mx1,*max2=&mx2,*min1=&m1,*min2=&m2;
    maxmin2(A,n,max1,max2,min1,min2);
    printf("\nLargest Value: %d", mx1);
    printf("\n2nd Largest Value: %d", mx2);
    printf("\nSmallest Value: %d", m1);
    printf("\n2nd Smallest Value: %d", m2);

    //part b-Bubble sort.
    printf("\nUsing Sort")
    maxMin(A,n); //as array is now sorted, we can directly access largest and smallest values
    printf("\nLargest Value: %d", A[n-1]);
    printf("\n2nd Largest Value: %d", A[n-2]);
    printf("\nSmallest Value: %d", A[0]);
    printf("\n2nd Smallest Value: %d", A[1]);

//post this for all questions sorted array will proceed
    //part c
    printf("\nArray before Swapping largest and smallest value: ");
    for(int i=0;i<n;i++)
        printf("%d ",A[i]);
    swapMaxMin(A,n);
    printf("\nArray after Swapping largest and smallest value: ");
    for(int i=0;i<n;i++)
        printf("%d ",A[i]);


    //part d
    int k;
    printf("\nEnter k: ");
    scanf("%d",&k);
    printf("\nArray before Circular right shift: ");
    for(int i=0;i<n;i++)
        printf("%d ",A[i]);
    shiftArray(A,n,k);
    printf("\nArray after Circular right shift: ");
    for(int i=0;i<n;i++)
        printf("%d ",A[i]);



}

