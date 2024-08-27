#include <stdio.h>

int main() {
    int a,b,p, q, i = 0, t, k, x, l,flag=0;
    int ques[30];
    int rem[30];

    printf("type the no is the form of p by q: ");
    scanf("%d%d", &p,&q);

    while (1) {
        a = p / q;
        b = p % q;
        ques[i]=a;
        rem[i]=b;
        

        for (t = 0; t < i; t++) {
            if (ques[t] == a && rem[t] == b)
             {
                flag=1;
                break;
            }
        }
        if(flag)
            break;
        else
            i++;
            p = (b) * 10;
    }

    printf("%d.", ques[0]);

    for (x = 0; x < t; x++) {
        printf("%d", ques[x]);
    }

    printf("(");

    for (l = t; l <= i; l++) {
        printf("%d", ques[l]);
    }

    printf(")");

    return 0;
}
