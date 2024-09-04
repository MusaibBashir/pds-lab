/*Write a non-recursive function that takes two strings containing only digits (0, 1, . . . , 9) as input and returns sum of those strings as an integer. 
You must not use any other header file except stdio.h. You may use the following template to implement it.
long int sum_of_two_strings(char str1[], char str2[]) {
// Complete this function
}
Executing the program looks like the following:
Enter string1: 1234
Enter string2: 11
The sum of two strings is 1245
Hint: ASCII value 48 corresponds to the digit 0*/

#include <stdio.h>
long int sum_of_two_strings(char str1[], char str2[]) {
int n1=0,n2=0;
for(int i=0; str1[i]!='\0';i++)
n1=10*n1+((int)str1[i]-'0');
for(int j=0; str2[j]!='\0';j++)
n2=10*n2+((int)str2[j]-'0');
return n1+n2;
}

int main() {
char num1[50],ch,num2[50];
int len=0;
printf("Enter string1: ");
do
{
    ch=getchar();
    if (ch!='\n')
    num1[len++]=ch;
} while (ch!='\n');
num1[len]='\0';
printf("Enter string2: ");
len=0;
do
{
    ch=getchar();
    if (ch!='\n')
    num2[len++]=ch;
} while (ch!='\n');
num2[len]='\0';
long int sum=sum_of_two_strings(num1, num2);
printf("The sum of two strings is %d", sum);

return 0;

}
