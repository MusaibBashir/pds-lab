#include <stdio.h>

void printstate(int groups[], int g) {
    for (int i = 0; i < g; i++) {
        printf("%d ", groups[i]);
    }
    printf("\n");
}

int grouping(int n, int g, int groups[], int index) {
    if (g == 1) {
        groups[index] = n;
        printstate(groups, index + 1);
        return 1;
    }
    
    int count = 0;
    for (int i = 1; i <= n - g + 1; i++) {
        groups[index] = i;
        count += grouping(n - i, g - 1, groups, index + 1);
    }
    
    return count;
}

int main() {
    int n, g;
    printf("Enter the number of elements (n): ");
    scanf("%d", &n);
    printf("Enter the number of groups (g): ");
    scanf("%d", &g);

    if (g > n) {
        printf("Number of groups cannot exceed number of elements!\n");
        return 1;
    }

    int groups[g];
    int num_distributions = grouping(n, g, groups, 0);
    printf("Total number of distributions: %d\n", num_distributions);

    return 0;
}
