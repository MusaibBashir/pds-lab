/*Name= Musaib Bin Bashir
Roll No.= 24IM10047
Group No.= 1
PC No= 81
Description= "PDS Lab Section 04, Assignment 6"*/

#include<stdio.h>

int removeDuplicates(char A[], char B[], int n){
int j=0,found;
for(int i=0; i<n;i++)
{
    found=0; //first we assume element is not in B
    for(int k=0; k<j;k++)
        if(B[k]==A[i]) //if we find the element already present in B, we update found
        {
        found=1;
        break;
    }
       if(!found) // if we haven't found the element in B then we add it
            B[j++]=A[i];
}
  B[j]='\0'; //Strings have to be null terminated
  return j; //j is the total length of B
}

int isEqual(char A[], char B[], int n1, int n2)
{
    if(n1!=n2) //if length is not equal then strings can't be equal
        return 0;
    for(int i=0;i<n1;i++)
        if(A[i]!=B[i]) //checking for inequality is simpler, as 1 inequality is enough to prove not equal to case
        return 0;
    return 1;

}

int can_be_made_with_rep(char A[],char B[], int n1, int n2)
{
    int element;
    for(int i=0; i<n1;i++){
        element=0;
        for(int j=0; j<n2;j++) // since rep is allowed we just need to find if a given element of A exists in B
            if(B[j]==A[i]){
              element=1;
                break;
            }
        if (!element) // if not return 0
            return 0;
    }
      return 1;

}

int can_be_made_without_rep(char A[],char B[], int n1, int n2)
{
    if(n1!=n2)
        return 0;
    char Bcopy[n2]; // we made a copy of B because in case of no rep, we need to also have an element for each element, so that we are not getting the equality for one element in B we update it
    for(int i=0;i<n2;i++)
        Bcopy[i]=B[i];
    int element;
    for(int i=0; i<n1;i++){
        element=0;
        for(int j=0; j<n2;j++) //e.g A=[a,b,b,c] and B= [a,b,c] updating B to 0 after first b of A search would make element=0 for next b of A, that's why copy of array is used
            if(Bcopy[j]==A[i]){
              element=1;
                Bcopy[j]='0';
                break;
            }
        if (!element)
            return 0;
    }
      return 1;

}

int main(){
    char s1[20],s2[20];
    printf("Enter S1: ");
    scanf("%s",&s1);
    printf("Enter S2: ");
    scanf("%s",&s2);
    int n1,n2;
    for(n1=0;s1[n1]!='\0';n1++);
    for(n2=0;s2[n2]!='\0';n2++);
    printf("\nS1: ");
    for(int i=0;i<n1;i++)
        printf("%c",s1[i]);
    printf("\nS2: ");
    for(int i=0;i<n2;i++)
        printf("%c",s2[i]);
    for(int i=0;i<n1;i++)
        if((s1[i]<'a' || s1[i]>'z')) //here ascii values of a and z would be used
    {
        for(int j=i;j<n1-1;j++) // if found then we left shift each element
            s1[j]=s1[j+1];
        s1[n1-1]='\0';//also left shift the null terminator
        n1--;//decrease size by 1
        i--;// iterator is decreased by 1 because our next element is left shifted by 1
    }
    printf("\nAfter keeping only lowercase S1: ");
    for(int i=0;i<n1;i++)
        printf("%c",s1[i]);

    for(int i=0;i<n2;i++)
        if((s2[i]<'a' || s2[i]>'z'))
    {
        for(int j=i;j<n2-1;j++)
            s2[j]=s2[j+1];
        s2[n2-1]='\0';
        n2--;
        i--;
    }
        printf("\nAfter keeping only lowercase S2: ");
    for(int i=0;i<n2;i++)
        printf("%c",s2[i]);

        printf("\nVowels in S1: ");
        for(int i=0;i<n1;i++){
            if(s1[i]=='a' ||s1[i]=='e' ||s1[i]=='i' ||s1[i]=='o' ||s1[i]=='u')
            printf("%c ",s1[i]);
        }
        printf("\nVowels in S2: ");
        for(int i=0;i<n2;i++){
            if(s2[i]=='a' ||s2[i]=='e' ||s2[i]=='i' ||s2[i]=='o' ||s2[i]=='u')
            printf("%c ",s2[i]);
        }
        printf("\nConsonants in S1: ");
        for(int i=0;i<n1;i++){
            if(!(s1[i]=='a' ||s1[i]=='e' ||s1[i]=='i' ||s1[i]=='o' ||s1[i]=='u'))
            printf("%c ",s1[i]);
        }
        printf("\nConsonants in S2: ");
        for(int i=0;i<n2;i++){
            if(!(s2[i]=='a' ||s2[i]=='e' ||s2[i]=='i' ||s2[i]=='o' ||s2[i]=='u'))
            printf("%c ",s2[i]);
        }

        //With repetition
        int x= can_be_made_with_rep(s1,s2,n1,n2);
        if(x)
            printf("\nString S1 can be made by S2 with repetition");
        else
            printf("\nString S1 can not be made by S2 with repetition");

        //Without repetition
         x= can_be_made_without_rep(s1,s2,n1,n2);
        if(x)
            printf("\nString S1 can be made by S2 without repetition");
        else
            printf("\nString S1 can not be made by S2 without repetition");

        char s3[40],s4[40];
        for(int i=0;i<n1;i++) //first we copy s1 to s3
            s3[i]=s1[i];
        for(int i=0;i<n2;i++) // then copy s4
            s3[n1+i]=s2[i];
        s3[n1+n2]='\0';
        for(int i=0;i<n2;i++)//here we copy first s2 to s4
            s4[i]=s2[i];
        for(int i=0;i<n1;i++)// then s1
            s4[n2+i]=s1[i];
        s4[n1+n2]='\0';

        printf("\nS3: ");
        for(int i=0; i<n1+n2;i++)
            printf("%c",s3[i]);
        printf("\nS4: ");
        for(int i=0; i<n1+n2;i++)
            printf("%c",s4[i]);

        char s5[40],s6[40];
        int n5,n6;
        n5=removeDuplicates(s3,s5,n1+n2);
        n6=removeDuplicates(s4,s6,n1+n2);
        printf("\nS5: ");
        for(int i=0;i<n5;i++)
        printf("%c",s5[i]);
        printf("\nS6: ");
        for(int i=0;i<n6;i++)
        printf("%c",s6[i]);

        int p=isEqual(s5,s6,n5,n6);
        if(p)
            printf("\nStrings are equal");
        else
            printf("\nStrings are not equal");
}

