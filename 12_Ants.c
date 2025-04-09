#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void simulateAnts(int positions[], int directions[], int N, int M, int T) {
    for (int t = 0; t < T; t++) {
        for (int i = 0; i < M; i++) {
            positions[i] = (positions[i] + directions[i] + N - 1) % N + 1;
        }
        for (int i = 0; i < M; i++) {
            for (int j = i + 1; j < M; j++) {
                if (positions[i] == positions[j]) {
                    swap(&directions[i], &directions[j]);
                }
            }
        }
    }
}

int main() {
    int N = 10, M = 4, T = 5;
    int positions[] = {1, 3, 6, 8};
    int directions[] = {1, -1, 1, -1};

    simulateAnts(positions, directions, N, M, T);

    for (int i = 0; i < M; i++) {
        printf("%d ", positions[i]);
    }
    
    return 0;
}
