#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Merge(int A[], int l, int mid, int h) {
    int i = l, j = mid + 1, k = 0;
    int B[100];

    while (i <= mid && j <= h) {
        if (A[i] > A[j]) {  // Sorting in descending order for max impact
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }

    while (i <= mid) B[k++] = A[i++];
    while (j <= h) B[k++] = A[j++];

    for (i = l, k = 0; i <= h; i++, k++) A[i] = B[k];
}

void MergeSort(int A[], int l, int h) {
    if (l < h) {
        int mid = (l + h) / 2;
        MergeSort(A, l, mid);
        MergeSort(A, mid + 1, h);
        Merge(A, l, mid, h);
    }
}

int minMovesToBalance(char str[], int N) {
    int firstHalfSum = 0, secondHalfSum = 0;
    int diff, moves = 0;
    int changes[100], changeCount = 0;

    for (int i = 0; i < N; i++) {
        firstHalfSum += str[i] - '0';
        secondHalfSum += str[N + i] - '0';
    }

    diff = abs(firstHalfSum - secondHalfSum);
    if (diff == 0) return 0;  // Already balanced

    for (int i = 0; i < N; i++) {
        changes[changeCount++] = 9 - (str[i] - '0');  // Max increase in first half
        changes[changeCount++] = (str[N + i] - '0');  // Max decrease in second half
    }

    // Sort changes in descending order to use the largest changes first
    MergeSort(changes, 0, changeCount - 1);

    for (int i = 0; i < changeCount && diff > 0; i++) {
        diff -= changes[i];
        moves++;
    }

    return moves;
}

int main() {
    char str[100];
    printf("Enter the 2N digit string: ");
    scanf("%s", str);

    int len = strlen(str);
    if (len % 2 != 0) {
        printf("Invalid input: The length of the string must be even.\n");
        return 1;
    }

    int N = len / 2;
    printf("Minimum moves required: %d\n", minMovesToBalance(str, N));

    return 0;
}
