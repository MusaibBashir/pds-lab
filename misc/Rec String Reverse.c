/* Write a recursive function to reverse a null-terminated string*/

#include <stdio.h>

void recursive_reverse(char arr[], int size) {
    if(arr[0]=='\0')
    return;
    recursive_reverse(arr+1, size-1);
    printf("%c",arr[0]);
}

int main() {
    char arr[100];
    char ch;
    int count=0;
    do
    {
        ch=getchar();
        if(ch!='\n')
        arr[count++]=ch;
    } while (ch!='\n');
    arr[count]='\0';
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Reversed String: ");
    recursive_reverse(arr, size);
    return 0;
}
