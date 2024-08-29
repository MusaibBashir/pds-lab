//Write a function relprime(x,y) to test whether two integers x and y are relatively prime. Test it in the main function.

#include <stdio.h>

void relprime(int a, int b) {
    int i, c, flag = 0;
    c = a<b?a:b;

    // Check for 1 as a special case
    if (a == 1 || b == 1) {
        printf("Not co-prime\n");
        return;
    }

    for (i = 2; i <= c; i++) {
        if (a % i == 0 && b % i == 0) {
            printf("Not co-prime\n");
            flag = 1;
            break;
        }
    }
    if (flag == 0) 
        printf("Co-prime\n");
}

int main() {
    int x, y;
    printf("Enter a & b: \n");
    scanf("%d %d", &x, &y);
    relprime(x, y);
    return 0;
}
