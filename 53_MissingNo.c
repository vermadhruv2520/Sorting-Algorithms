#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int A[], int l, int h) {
    int pivot = A[l];
    int i = l, j = h;

    do {
        do { i++; } while (A[i] <= pivot);
        do { j--; } while (A[j] > pivot);

        if (i < j)
            swap(&A[i], &A[j]);
    } while (i < j);

    swap(&A[l], &A[j]);
    return j;
}

void QuickSort(int A[], int l, int h) {
    int j;
    if (l < h) {
        j = partition(A, l, h);
        QuickSort(A, l, j);
        QuickSort(A, j + 1, h);
    }
}

// Function to find the maximum missing multiple of 2
int findMaxMissingMultipleOf2(int A[], int n) {
    QuickSort(A, 0, n);  // Sort the array

    int exists[1000001] = {0}; // Array to track existence of numbers (hashing)
    for (int i = 0; i < n; i++) {
        while (A[i] > 0) {
            exists[A[i]] = 1;  // Mark the number as present
            A[i]--; // Decrement the number
        }
    }

    int missing = 2;
    while (exists[missing]) {
        missing += 2; // Find the next missing multiple of 2
    }

    return missing;
}

int main() {
    int T;
    scanf("%d", &T); // Number of test cases

    while (T--) {
        int N;
        scanf("%d", &N);
        int A[N + 1]; // Array to hold numbers (extra space for pivot handling in QuickSort)
        
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }

        // Compute and print the result
        printf("%d\n", findMaxMissingMultipleOf2(A, N));
    }

    return 0;
}
