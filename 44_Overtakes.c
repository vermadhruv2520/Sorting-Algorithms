#include <stdio.h>

#define MAX_N 100000

long long overtakes = 0;
int Velocity[MAX_N], Position[MAX_N], ReorderedVelocity[MAX_N], temp[MAX_N];

void Merge(int A[], int l, int mid, int h) {
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= h) {
        if (A[i] <= A[j]) {
            temp[k++] = A[i++];
        } else {
            temp[k++] = A[j++];
            overtakes += (mid - i + 1);  // Counting inversions
        }
    }
    while (i <= mid) temp[k++] = A[i++];
    while (j <= h) temp[k++] = A[j++];
    for (i = l; i <= h; i++) A[i] = temp[i];
}

void MergeSort(int A[], int l, int h) {
    if (l < h) {
        int mid = (l + h) / 2;
        MergeSort(A, l, mid);
        MergeSort(A, mid + 1, h);
        Merge(A, l, mid, h);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) scanf("%d", &Velocity[i]);
    for (int i = 0; i < N; i++) {
        scanf("%d", &Position[i]);
        Position[i]--;  // Convert to 0-based index
    }

    for (int i = 0; i < N; i++) {
        ReorderedVelocity[i] = Velocity[Position[i]];  // Reorder velocities based on positions
    }

    MergeSort(ReorderedVelocity, 0, N - 1);
    
    printf("%lld\n", overtakes);
    
    return 0;
}
