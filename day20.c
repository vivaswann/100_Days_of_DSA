/*Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the count of subarrays having sum zero

Example:
Input:
6
1 -1 2 -2 3 -3

Output:
6

Explanation: A subarray is a continuous part of the array. For the input array 1 -1 2 -2 3 -3, 
the following subarrays have sum zero: [1, -1], [2, -2], [3, -3], [1, -1, 2, -2], [2, -2, 3, -3], 
and [1, -1, 2, -2, 3, -3]. Since there are 6 such subarrays, the output is 6.*/

#include <stdio.h>
#include <stdlib.h>

#define MAXN 100000
#define OFFSET 100000   // shift for negative prefix sums

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int freq[2 * OFFSET + 1];
    
    for(int i = 0; i <= 2 * OFFSET; i++)
        freq[i] = 0;

    int prefixSum = 0;
    int count = 0;

    freq[OFFSET] = 1;

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        int index = prefixSum + OFFSET;

        if(freq[index] > 0)
            count += freq[index];

        freq[index]++;
    }

    printf("%d\n", count);

    free(arr);
    return 0;
}
