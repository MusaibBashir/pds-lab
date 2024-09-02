#include<stdio.h>
int canchange(int k, int a, int b, int c) {
    if (k == 0) return 0;
    if (k < 0) return -1;
    
    int minCoins = -1;

    int x = canchange(k - a, a,b,c);
    if (x >= 0 && (minCoins == -1 || x < minCoins)) minCoins = x + 1;

    x = canchange(k - b,a,b,c);
    if (x >= 0 && (minCoins == -1 || x < minCoins)) minCoins = x + 1;

    x = canchange(k - c,a,b,c);
    if (x >= 0 && (minCoins == -1 || x < minCoins)) minCoins = x + 1;

    return minCoins;
}

int main() {
    int k, d,a,b,c;
    printf("Enter  available denominations(3): ");
    scanf("%d%d%d",&a,&b,&c);
    printf("\nEnter total money: ");
    scanf("%d",&k);
    d = canchange(k,a,b,c);
    printf("\nMin coins required: %d\n", d);
    return 0;
}
