#include <stdio.h>
int isBinary(long long int n)
{
    int dig;
    while (n != 0)
    {
        dig = n % 10;
        if (dig == 0 || dig == 1)
            n /= 10;
        else
            return 0;
    }
    return 1;
}

long long int bitwise_nand(long long int b1, long long int b2)
{
    long long int revsum = 0, d1, d2, bitop, sum = 0;
    while (b1 != 0 && b2 != 0)
    {
        d1 = b1 % 10;
        d2 = b2 % 10;
        bitop = (d1 + d2) < 2 ? 1 : 0;
        revsum = revsum * 10 + bitop;
        b1 /= 10;
        b2 /= 10;
    }
    while (revsum != 0)
    {
        d1 = revsum % 10;
        sum = sum * 10 + d1;
        revsum /= 10;
    }

    return sum;
}

int main()
{
    long long int b1;
    long long int b2;
    long long int x;
    do
    {
        printf("Enter 1st binary: ");
        scanf("%lld", &b1);
    } while (!isBinary(b1));
    do
    {
        printf("Enter 2nd binary: ");
        scanf("%lld", &b2);
    } while (!isBinary(b2));

    x = bitwise_nand(b1, b2);
    printf("%lld", x);
    return 0;
}
