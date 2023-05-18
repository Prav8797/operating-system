#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    int n, head, i, j, sum = 0, d, temp, tracks[MAX], visited[MAX], order[MAX];

    printf("Enter the number of tracks: ");
    scanf("%d", &n);

    printf("Enter the track positions: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &tracks[i]);
        visited[i] = 0;
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (tracks[i] > tracks[j]) {
                temp = tracks[i];
                tracks[i] = tracks[j];
                tracks[j] = temp;
            }
        }
    }
    if (head < tracks[0]) {
        d = 1;  
    } else {
        d = -1; 
    }
    int k = 0;
    for (i = 0; i < n; i++) {
        if (tracks[i] == head) {
            order[k++] = i;
            visited[i] = 1;
            break;
        }
    }

    if (d == 1) {
        for (i = k; i < n; i++) {
            for (j = i; j < n; j++) {
                if (visited[j] == 0) {
                    order[k++] = j;
                    visited[j] = 1;
                }
            }
        }
        for (i = n - 1; i >= 0; i--) {
            if (visited[i] == 0) {
                order[k++] = i;
            }
        }
    } else {
        for (i = k; i >= 0; i--) {
            for (j = i; j >= 0; j--) {
                if (visited[j] == 0) {
                    order[k++] = j;
                    visited[j] = 1;
                }
            }
        }
        for (i = 0; i < n; i++) {
            if (visited[i] == 0) {
                order[k++] = i;
            }
        }
    }
    sum = abs(head - tracks[order[0]]);
    for (i = 1; i < n; i++) {
        sum += abs(tracks[order[i]] - tracks[order[i-1]]);
    }
    printf("Order of track accesses: ");
    for (i = 0; i < n; i++) {
        printf("%d ", tracks[order[i]]);
    }
    printf("\n");

    printf("Average head movement: %0.2f\n", (float) sum / n);

    return 0;
}

