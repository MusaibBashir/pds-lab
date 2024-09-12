#include <stdio.h>

void printer(int A[], int count) {
    for (int i = 0; i < count; i++) {
        if (i % 2 == 1)
            printf("%c ", A[i]);
        else
            printf("%d ", A[i]);
    }
    printf("\n");
}

void group(int A[], int x) {
    A[2*x] = (A[2*x] * 10) + A[2*x+2];
    A[2*x+2] = 0;
}

void degroup(int A[], int x) {
    A[2*x+2] = A[2*x] % 10;
    A[2*x] /= 10;
}

void check(int A[], int count) {
    int sum = A[0];
    for (int i = 1; i < count; i += 2) {
        if (A[i] == 43)
            sum += A[i + 1];
        else
            sum -= A[i + 1];
    }

    if (sum == 100) {
        printer(A, count);
    }
}

void permOperators(int arr[], int index, int count) {
    if (index >= count) {
        check(arr, count);
        return;
    }

    arr[index] = 43;
    permOperators(arr, index + 2, count);

    arr[index] = 45;
    permOperators(arr, index + 2, count);
}

void permGroup(int arr[], int index, int count) {
    if (index >= (count / 2)) {
        check(arr, count);
        return;
    }
    permGroup(arr, index + 1, count);

    group(arr, index);
    permGroup(arr, index + 1, count);
    degroup(arr, index); 
}

void permreplace_group(int arr[], int index, int count) {
    if (index >= (count / 2)) {
        permOperators(arr,1, count);
        return;
    }

    permreplace_group(arr, index + 1, count);
    group(arr, index);
    permreplace_group(arr, index + 1, count);
    degroup(arr, index);
}

int main() {
    int numbers[17], count = 0,option;

    printf("Enter 9 numbers: ");
    do {
        scanf("%d", &numbers[count++]);
        numbers[count++]=43;
        }while (count<16);
        scanf("%d", &numbers[count++]);

    printf("Menu:\n1) Group\n2) Replace\n3) Quit\n");
    scanf("%d", &option);

    switch (option) {
        case 1:
            permGroup(numbers,1,count);
            break;
        case 2:
            permreplace_group(numbers,1,count);
            break;
        case 3:
            break;
        default:
            printf("Invalid option.\n");
    }

    return 0;
}
