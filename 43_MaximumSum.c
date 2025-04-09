#include <stdio.h>
#include <stdlib.h>

// Function to merge two halves
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    // Copy data to temp arrays
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr
    i = 0; j = 0; k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements
    while (i < n1) {
        arr[k] = L[i];
        i++; k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++; k++;
    }
}

// Function to implement Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        // Recursively sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to find the maximum sum of minimums in pairs
int maxSumOfMinimums(int arr[], int size) {
    mergeSort(arr, 0, size - 1); // Step 1: Sort the array

    int sum = 0;
    for (int i = 0; i < size; i += 2) {
        sum += arr[i]; // Step 2: Sum every first element of the adjacent pairs
    }
    return sum;
}

int main() {
    int N;
    scanf("%d", &N);
    
    int size = 2 * N;
    int arr[size];

    // Reading input values
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Compute and print the result
    printf("%d\n", maxSumOfMinimums(arr, size));

    return 0;
}
