/*Write a recursive function to search for an element in an array*/

#include <stdio.h>

int recursive_search(int arr[], int size, int target) {
    if (size == 0) {
        return -1; // Element not found
    }

    if (arr[0] == target) {
        return 0; // Element found at index 0
    }

    int result = recursive_search(arr + 1, size - 1, target);
    if (result != -1) {
        return result + 1; // Adjust index if found in subarray
    }

    return -1; // Element not found
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 3;

    int index = recursive_search(arr, size, target);

    if (index != -1) {
        printf("Element found at index %d\n", index);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
