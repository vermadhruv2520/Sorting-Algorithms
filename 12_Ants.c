#include <stdio.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to simulate ant movement and collision
void simulateAnts(int positions[], int directions[], int N, int M, int T) {
    // Simulate for T time steps
    for (int t = 0; t < T; t++) {
        // Move each ant according to its direction
        for (int i = 0; i < M; i++) {
            // Update position: (current + direction + N-1) % N + 1
            // This ensures positions wrap around the circle (1 to N)
            positions[i] = (positions[i] + directions[i] + N - 1) % N + 1;
        }
        
        // Check for collisions between ants
        for (int i = 0; i < M; i++) {
            for (int j = i + 1; j < M; j++) {
                // If two ants are at the same position
                if (positions[i] == positions[j]) {
                    // Swap their directions (they bounce off each other)
                    swap(&directions[i], &directions[j]);
                }
            }
        }
    }
}

int main() {
    // Initialize parameters
    int N = 10;  // Size of the circle
    int M = 4;   // Number of ants
    int T = 5;   // Number of time steps
    
    // Initial positions of ants
    int positions[] = {1, 3, 6, 8};
    // Initial directions of ants (1 for clockwise, -1 for counterclockwise)
    int directions[] = {1, -1, 1, -1};

    // Run the simulation
    simulateAnts(positions, directions, N, M, T);

    // Print final positions of all ants
    for (int i = 0; i < M; i++) {
        printf("%d ", positions[i]);
    }
    
    return 0;
}
