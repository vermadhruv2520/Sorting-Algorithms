#include <stdio.h>
#include <string.h>

void calculateNiceness(char A[][100], int N, int niceness[]) {
    for (int i = 0; i < N; i++) {
        niceness[i] = 0;  // Initialize niceness value
        for (int j = 0; j < i; j++) { 
            if (strcmp(A[j], A[i]) < 0) {  // Check if A[j] is lexicographically smaller
                niceness[i]++;
            }
        }
    }
}

int main() {
    int N;
    printf("Enter number of strings: ");
    scanf("%d", &N);

    char A[N][100];  // Assuming max length of each string is 100
    int niceness[N]; // Array to store niceness values

    printf("Enter %d strings:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%s", A[i]);
    }

    calculateNiceness(A, N, niceness);

    printf("Niceness values:\n");
    for (int i = 0; i < N; i++) {
        printf("%d\n", niceness[i]);
    }

    return 0;
}
