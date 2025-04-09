#include <stdio.h>
#include <stdlib.h>

long long calculate_beautifulness(int arr[], int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += abs(arr[i] - (i + 1));
    }
    return sum;
}

void Merge(int A[], int l, int mid, int h) {
    int i = l, j = mid + 1, k = 0;
    int B[100];

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

void MergeSort(int A[], int n) {
    int p, l, mid, h;
    for (p = 2; p <= n; p = p * 2) {
        for (int i = 0; i + p - 1 < n; i = i + p) {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            Merge(A, l, mid, h);
        }
    }
    if (p / 2 < n) {
        Merge(A, 0, p / 2 - 1, n - 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n], sorted[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sorted[i] = arr[i];
    }
    
    long long initial_beautifulness = calculate_beautifulness(arr, n);
    
    MergeSort(sorted, n);
    
    long long max_beautifulness = initial_beautifulness;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            
            long long new_beautifulness = calculate_beautifulness(arr, n);
            if (new_beautifulness > max_beautifulness) {
                max_beautifulness = new_beautifulness;
            }
            
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    printf("%lld\n", max_beautifulness);
    return 0;
}
