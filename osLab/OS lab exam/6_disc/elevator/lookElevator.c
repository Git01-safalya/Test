#include <stdio.h>
#include <stdlib.h>

void look(int requests[], int head, int size) {
    int totalSeek = 0;
    int i, j, temp, distance, currentPosition, previousPosition;

    printf("Sequence of head movement: ");

    // Sort the requests in ascending order
    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (requests[i] > requests[j]) {
                temp = requests[i];
                requests[i] = requests[j];
                requests[j] = temp;
            }
        }
    }

    // Finding the index of the current head position
    for (i = 0; i < size; i++) {
        if (requests[i] >= head) {
            currentPosition = i;
            previousPosition = i - 1;
            break;
        }
    }

    // Look to the right
    for (i = currentPosition; i < size; i++) {
        printf("%d ", requests[i]);
        distance = abs(requests[i] - head);
        totalSeek += distance;
        head = requests[i];
    }

    // Look to the left
    for (i = previousPosition; i >= 0; i--) {
        printf("%d ", requests[i]);
        distance = abs(requests[i] - head);
        totalSeek += distance;
        head = requests[i];
    }

    printf("\nTotal seek time: %d\n", totalSeek);
}

int main() {
    int requests[] = {82,170,43,140,24,16,190};
    int head = 50;
    int size = sizeof(requests) / sizeof(requests[0]);

    look(requests, head, size);

    return 0;
}
