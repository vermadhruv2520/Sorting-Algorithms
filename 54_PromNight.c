#include <stdio.h>

// Function to swap two integers
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Partition function for QuickSort
int partition(int A[], int l, int h) {
    int pivot = A[l];
    int i = l, j = h;

    do {
        do { i++; } while (A[i] <= pivot && i < h);
        do { j--; } while (A[j] > pivot);
        if (i < j)
            swap(&A[i], &A[j]);
    } while (i < j);

    swap(&A[l], &A[j]);
    return j;
}

// QuickSort function
void QuickSort(int A[], int l, int h) {
    if (l < h) {
        int j = partition(A, l, h);
        QuickSort(A, l, j);
        QuickSort(A, j + 1, h);
    }
}

// Function to determine if all boys can get a partner
void checkPairs(int boys[], int girls[], int M, int N) {
    QuickSort(boys, 0, M);  // Sort boys' heights
    QuickSort(girls, 0, N); // Sort girls' heights

    int i = 0, j = 0; // Pointers for boys and girls

    while (i < M && j < N) {
        if (boys[i] > girls[j]) { // If the boy is taller, pair him
            i++;
            j++;
        } else {
            j++; // Try the next girl
        }
    }

    if (i == M)
        printf("YES\n");
    else
        printf("NO\n");
}

int main() {
    int T;
    scanf("%d", &T); // Read number of test cases

    while (T--) {
        int M, N;
        scanf("%d %d", &M, &N);

        int boys[M], girls[N];

        for (int i = 0; i < M; i++)
            scanf("%d", &boys[i]); // Read boys' heights

        for (int i = 0; i < N; i++)
            scanf("%d", &girls[i]); // Read girls' heights

        checkPairs(boys, girls, M, N);
    }

    return 0;
}
