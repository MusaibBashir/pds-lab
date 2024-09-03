/*Write a recursive function to check if a string is a palindrome or not*/

#include <stdio.h>

int check_palindrome(char arr[], int start, int end)
{
    if(start>=end)
    return 1;
    if(arr[start]!=arr[end])
    return 0;
    return (check_palindrome(arr, start+1, end-1));
    

}

int main() {
    char arr[100];
    char c;
    int x,n=0;
    printf("Enter word: \n");
    do
    {
        c=getchar();
        if (c!='\n')
            arr[n++]=c;
    } while (c!='\n');
    x=check_palindrome(arr,0,n-1);
    if (x)
    printf("Is palindrome");
    else
    printf("Is not a palindrome");
    return 0;
}
