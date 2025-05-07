#include <stdio.h>
#define MOD 1000000007  // Modulo value to keep numbers manageable

// Function to merge two sorted subarrays
void Merge(int A[], int l, int mid, int h) {
    int i = l, j = mid + 1, k = 0;
    int B[h - l + 1];  // Temporary array to store merged result

    // Compare and merge elements from both subarrays
    while (i <= mid && j <= h) {
        if (A[i] < A[j]) {
            B[k++] = A[i++];  // Take element from left subarray
        } else {
            B[k++] = A[j++];  // Take element from right subarray
        }
    }

    // Copy remaining elements from left subarray
    while (i <= mid) {
        B[k++] = A[i++];
    }

    // Copy remaining elements from right subarray
    while (j <= h) {
        B[k++] = A[j++];
    }

    // Copy merged elements back to original array
    for (i = l, k = 0; i <= h; i++, k++) {
        A[i] = B[k];
    }
}

// Function to perform merge sort
void MergeSort(int A[], int l, int h) {
    if (l < h) {  // Base case: if there's more than one element
        int mid = (l + h) / 2;  // Find middle point
        MergeSort(A, l, mid);    // Sort left half
        MergeSort(A, mid + 1, h);  // Sort right half
        Merge(A, l, mid, h);     // Merge the sorted halves
    }
}

// Function to calculate the overall power of the array
long long calculateOverallPower(int A[], int N) {
    MergeSort(A, 0, N - 1);  // First sort the array
    
    long long sumAbsDiff = 0, prefixSum = 0;  // Initialize variables for calculations
    int maxStrength = A[N - 1];  // Maximum strength is the last element after sorting

    // Calculate sum of absolute differences and prefix sum
    for (int i = 0; i < N; i++) {
        // Add the difference between current element and prefix sum
        sumAbsDiff = (sumAbsDiff + ((long long)i * A[i] - prefixSum + MOD) % MOD) % MOD;
        // Update prefix sum
        prefixSum = (prefixSum + A[i]) % MOD;
    }

    // Calculate final result by multiplying with maximum strength
    long long result = (sumAbsDiff * maxStrength) % MOD;
    return result;
}

int main() {
    int T;  // Number of test cases
    scanf("%d", &T);

    // Process each test case
    while (T--) {
        int N;  // Number of elements
        scanf("%d", &N);
        int A[N];  // Array to store strengths

        // Input the strengths
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }

        // Calculate and print the overall power
        printf("%lld\n", calculateOverallPower(A, N));
    }

    return 0;
}
