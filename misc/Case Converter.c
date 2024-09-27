/*Convert string to uppercase and lowercase using pointers*/

#include <stdio.h>

void lower_to_upper(char *s)
{
    while (*s)
    {
        *s = (*s >= 'a' && *s <= 'z') ? *s - ('a' - 'A') : *s;
        s++;
    }
}

void upper_to_lower(char *s)
{
    while (*s)
    {
        *s = (*s >= 'A' && *s <= 'Z') ? *s + ('a' - 'A') : *s;
        s++;
    }
}

int main()
{
    char A[100];
    printf("Enter main string: ");
    scanf("%s", A);
    char *s = A;
    int n;
    for (n = 0; A[n] != '\0'; n++);
    lower_to_upper(s);
    for (int i = 0; i < n; i++)
        printf("%c", A[i]);
    printf("\n");
    upper_to_lower(s);
    for (int i = 0; i < n; i++)
        printf("%c", A[i]);
    return 0;
}
