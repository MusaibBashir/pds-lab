/*Write an iterative and recursive function to check if a string is a palindrome or not*/

#include <stdio.h>

int rec_check_palindrome(char arr[], int start, int end)
{
    if(start>=end)
        return 1;
    if(arr[start]!=arr[end])
        return 0;
    return (rec_check_palindrome(arr, start+1, end-1));
}

int check_palindrome(char arr[], int n){
    for(int i=0;i<n/2+1;i++)
        if (arr[i]!=arr[n-i-1])
            return 0;
    return 1;
}

int main() {
    char arr[100];
    char c;
    int x,y,n=0;
    printf("Enter word: \n");
    do
    {
        c=getchar();
        if (c!='\n')
            arr[n++]=c;
    } while (c!='\n');
    x=rec_check_palindrome(arr,0,n-1);
    if (x)
        printf("Is palindrome\n");
    else
        printf("Is not a palindrome\n");
    y=check_palindrome(arr,n);
    if (y)
        printf("Is palindrome");
    else
        printf("Is not a palindrome");
    return 0;
}
