/*Name= Musaib Bin Bashir
Roll No.= 24IM10047
Group No.= 1
PC No= 81
Description= "PDS Lab Section 04, Assignment 2"*/

#include<stdio.h>
int main()
{
   /*Part A: Read a +ve integer and print it and print the sum of its digits*/
   int a,temp,sum=0;
   printf("Enter Number: ");
   scanf("%d",&a);
   printf("A: %d\n", a);
   temp=a; //a variable which can store the value of a temporarily and gets updated after each digit is removed
   while(temp>0)
   {
       sum+=temp%10;
       temp/=10;
   }
   printf("Sum:%d\n",sum);


    /*Part B*/
   int dig,reva=0;//Here since we are using print and digits are being accessed in reverse order, if we directly use a we would get reverse number e.g 12345 would give 04020, so that's why I first reversed a and then used it
   temp=a;
   while(temp!=0)
   {
       dig=temp%10;
       reva=10*reva+dig;
        temp/=10;
   }
   temp=reva;
   printf("D: ");
   while(temp!=0)
   {
       dig=temp%10;
       if(dig%2==0)
        printf("%d",dig);
       else
       printf("0");
       temp/=10;
   }

 printf("\n\n");//To just make it visually easy to see different sections of output

    
    /*Part C*/
    printf("Multiplication Table:\n");
   int i;
   for(i=1; i<=10; i++)
   {
       printf("\n%d * %d = %d\n", i, a, i*a);
   }

 printf("\n\n");


    /*Part D*/
   printf("Pattern\n");
   int n=0,j;
   temp=a;
   while(temp>0)
   {
       dig=temp%10;
       temp/=10;
       n=dig>n?dig:n; //Getting the max digit of a
   }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=i; j++)
            {
            printf("%d\t", j);
            }
        printf("\n");
    }
 printf("\n\n");
    
    
    /*Part E*/
    int b,count=0;
    do{
        printf("Enter B: ");
        scanf("%d",&b);
        printf("B: %d\n",b);
        count+=1;
    }while(b<=0);
    if (count>1)
        printf("No. of times incorrect input was entered: %d\n", count-1); //Count-1 because one input is correct out of all the inputs given

 printf("\n\n");
    
    
    /*Part F*/
   int revb=0;
   temp=b;
   while(temp!=0)
   {
       dig=temp%10;
       revb=10*revb+dig;
       temp/=10;
   }
   printf("Reverse of B: %d\n", revb);

   
   
    /*Part G*/
   if(a==reva)  //to reduce number of comparisons I've broken the conditions
   {
       if(b==revb)
        printf("Both A and B are Palindromes\n");
       else
        printf("A is a palindrome, whileas B is not\n");
   }
   else if(b==revb)
   printf("B is a palindrome, whileas A is not\n"); //if this bock is executing we already know A is not palindrome, since it is an else-if block
   else
    printf("Neither A nor B is a palindrome\n");


 printf("\n\n");
    
    
    /*Part H*/
   int e,cubesum=0;
   do{
    printf("Enter a 3 digit number: \n");
    scanf("%d",&e);
    printf("E: %d\n", e);
   }while(e<=100 || e>=999);
   temp=e;
   while(temp!=0)
   {
       dig=temp%10;
       cubesum+=(dig*dig*dig);
       temp/=10;
   }
   if(cubesum==e)
    printf("Armstrong Number\n");
   else
    {printf("Not an Armstrong Number\n");}


   int k;
   printf("All 3 digit Armstrong Numbers: ");
   for(k=100;k<=999;k++) //Initialise a loop for all 3 digit numbers to check if they are armstrong numbers
   {
       cubesum=0;
       temp=k;
       while(temp!=0)
    {
       dig=temp%10;
       cubesum+=(dig*dig*dig);
       temp/=10;
    }
   if(cubesum==k)
        printf("%d\t",k);
   }
 
 printf("\n\n");
   
   
   /*Part I*/
   char name;
   int vowa,vowe,vowi,vowo,vowu, totalvow, maxvow,max_vowels_count;
   vowa=vowe=vowi=vowo=vowu=max_vowels_count=0;
   printf("\nEnter a name:");
   getchar(); //This one catches the/n of the output before it, so that the loop doesn't misbehave
   do{
        name=getchar(); //Scanf doesn't work here, so I used getchar, the way it works is for the name we enter it loops over each alphabet until at last it catches \n, because there is no enter pressed before name is completely written, it works here.
        if(name=='a')
            vowa+=1;
        else if (name=='e')
            vowe+=1;
        else if (name=='i')
            vowi+=1;
        else if (name=='o')
            vowo+=1;
        else if (name=='u')
            vowu+=1;
   printf("%c", name);
   }while(name!='\n');
   totalvow=vowa+vowe+vowi+vowo+vowu;
        printf("Total Vowels= %d\n", totalvow);
        //Choosing the max vowel and using if else loop to find which vowel appears max times.
        maxvow=vowa>vowe?vowa:vowe;
        maxvow=maxvow>vowi?maxvow:vowi;
        maxvow=maxvow>vowo?maxvow:vowo;
        maxvow=maxvow>vowu?maxvow:vowu;

    // Counting how many vowels have the maximum count, this done to address the case where multiple vowels appear max times.
    if (vowa == maxvow) 
        max_vowels_count++;
    if (vowe == maxvow) 
        max_vowels_count++;
    if (vowi == maxvow)
        max_vowels_count++;
    if (vowo == maxvow)
        max_vowels_count++;
    if (vowu == maxvow)
        max_vowels_count++;

    // If only one vowel appears max times, we would directly print that
    if (max_vowels_count == 1) {
        if (vowa == maxvow) {
            printf("A is the most appearing vowel and appears %d times in the name\n", maxvow);
        } else if (vowe == maxvow) {
            printf("E is the most appearing vowel and appears %d times in the name\n", maxvow);
        } else if (vowi == maxvow) {
            printf("I is the most appearing vowel and appears %d times in the name\n", maxvow);
        } else if (vowo == maxvow) {
            printf("O is the most appearing vowel and appears %d times in the name\n", maxvow);
        } else {
            printf("U is the most appearing vowel and appears %d times in the name\n", maxvow);
        }
    } else {
        //In case multiple vowels appear maximum times
        printf("The most appearing vowels are: ");
        if (vowa == maxvow)
            printf("A ");
        if (vowe == maxvow) 
            printf("E ");
        if (vowi == maxvow)
            printf("I ");
        if (vowo == maxvow)
            printf("O ");
        if (vowu == maxvow)
            printf("U ");
        printf("and they appear %d times in the name\n", maxvow); //basically it first prints "The most appearing vowels are: ", then prints the respective vowels and then the times they appear.
    }

    return 0;
}
