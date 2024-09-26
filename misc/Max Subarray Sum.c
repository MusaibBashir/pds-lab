/*Given an array find the maximum sum of any possible subarray*/

#include <stdio.h>

int max_subarray_sum(int arr[], int n) //Kadane's Algorithm. Time Complexity: O(n)
{
    int max_sum = arr[0], curr_sum = 0;

    for (int i = 0; i < n; i++)
    {
        curr_sum += arr[i];

        if (max_sum < curr_sum)
            max_sum = curr_sum;

        if (curr_sum < 0)
            curr_sum = 0;
    }
    return max_sum;
}

int main()
{
    int arr[] = {-18, -9, 16, -11, 7, 15, -23, 20, -21, 17};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Max subarray sum: %d", max_subarray_sum(arr, n));
    return 0;
}
