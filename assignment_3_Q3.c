#include <stdio.h>

int main() {
    int nr, dr;

    printf("Enter the numerator and denominator: ");
    scanf("%d %d", &nr, &dr);

    int q, r, i = 0,j, rep = 0, rep_start = -1;
    int ques[30] = {0};
    int rem[30] = {0};

    printf("%d.", nr / dr);

    nr %= dr;

    while (1) {
        q = nr * 10 / dr;
        r = nr * 10 % dr;

        ques[i] = q;
        rem[i] = r;

        for (j = 0; j < i; j++) {
            if (ques[j] == q && rem[j] == r) {
                rep = 1;
                rep_start = j;
                break;
            }
        }

        if (rep) {
            break;
        }

        nr = r;
        i++;
    }

    for (j = 0; j < rep_start; j++) {
        printf("%d", ques[j]);
    }

    if (rep) {
        printf("(");
        for (j = rep_start; j < i; j++) {
            printf("%d", ques[j]);
        }
        printf(")");
    }

}
