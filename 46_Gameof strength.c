#include <stdio.h>
#define MOD 1000000007

// Merge function for Merge Sort
void Merge(int A[], int l, int mid, int h) {
    int i = l, j = mid + 1, k = 0;
    int B[h - l + 1];

    while (i <= mid && j <= h) {
        if (A[i] < A[j]) {
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }

    while (i <= mid) {
        B[k++] = A[i++];
    }

    while (j <= h) {
        B[k++] = A[j++];
    }

    for (i = l, k = 0; i <= h; i++, k++) {
        A[i] = B[k];
    }
}

// Merge Sort function
void MergeSort(int A[], int l, int h) {
    if (l < h) {
        int mid = (l + h) / 2;
        MergeSort(A, l, mid);
        MergeSort(A, mid + 1, h);
        Merge(A, l, mid, h);
    }
}

// Function to calculate Overall Power
long long calculateOverallPower(int A[], int N) {
    MergeSort(A, 0, N - 1); // Sort the array
    
    long long sumAbsDiff = 0, prefixSum = 0;
    int maxStrength = A[N - 1]; // Maximum strength in the array

    for (int i = 0; i < N; i++) {
        sumAbsDiff = (sumAbsDiff + ((long long)i * A[i] - prefixSum + MOD) % MOD) % MOD;
        prefixSum = (prefixSum + A[i]) % MOD;
    }

    long long result = (sumAbsDiff * maxStrength) % MOD;
    return result;
}

int main() {
    int T;
    scanf("%d", &T); // Number of test cases

    while (T--) {
        int N;
        scanf("%d", &N);
        int A[N];

        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }

        printf("%lld\n", calculateOverallPower(A, N));
    }

    return 0;
}
