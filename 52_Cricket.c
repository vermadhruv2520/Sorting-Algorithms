#include <stdio.h>

// Function to swap two integers
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Partition function for QuickSort
int partition(int A[], int l, int h) {
    int pivot = A[l];  // Choosing first element as pivot
    int i = l, j = h;

    while (i < j) {
        do { i++; } while (i < h && A[i] <= pivot);
        do { j--; } while (A[j] > pivot);

        if (i < j)
            swap(&A[i], &A[j]);
    }

    swap(&A[l], &A[j]);  // Place pivot at correct position
    return j;
}

// QuickSort function
void QuickSort(int A[], int l, int h) {
    if (l < h) {
        int j = partition(A, l, h);
        QuickSort(A, l, j);      // Sort left part
        QuickSort(A, j + 1, h);  // Sort right part
    }
}

// Function to calculate the maximum possible score for Bob
int maxScore(int A[], int B[], int n) {
    QuickSort(A, 0, n);  // Sorting Bob's energy levels
    QuickSort(B, 0, n);  // Sorting James' energy levels

    int score = 0, j = 0; // j keeps track of James' used energy levels

    for (int i = 0; i < n; i++) {
        if (A[i] > B[j]) {  
            score += (A[i] - B[j]); // Bob wins and earns the difference
            j++; // Move to the next lowest energy level of James
        }
    }
    return score;
}

int main() {
    int n;
    scanf("%d", &n); // Input number of matches

    int A[n], B[n];

    // Input energy levels for Bob
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    // Input energy levels for James
    for (int i = 0; i < n; i++)
        scanf("%d", &B[i]);

    // Output the maximum score Bob can achieve
    printf("%d\n", maxScore(A, B, n));

    return 0;
}
