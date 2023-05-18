#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100
void sort(int *arr, int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int findNextRequest(int *arr, int size, int head_pos) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] > head_pos)
            return i;
    }
    return 0;
}

int main() {
    int num_tracks, track_pos[MAX_SIZE];
    
    printf("Enter the number of tracks: ");
    scanf("%d", &num_tracks);

    printf("Enter the track positions:\n");
    for (int i = 0; i < num_tracks; i++) {
        scanf("%d", &track_pos[i]);
    }

    sort(track_pos, num_tracks);

    int head_pos;

    printf("Enter the initial position of the disk head: ");
    scanf("%d", &head_pos);

    int index, distance, totalDistance = 0;

    printf("\nC-SCAN Disk Scheduling Algorithm\n\n");
    printf("Head movement sequence: ");

    index = findNextRequest(track_pos, num_tracks, head_pos);
    distance = head_pos;
    for (int i = index; i < num_tracks; i++) {
        printf("%d ", track_pos[i]);
        totalDistance += abs(track_pos[i] - distance);
        distance = track_pos[i];
    }
    if (index != 0) {
        printf("%d ", num_tracks - 1);
        totalDistance += num_tracks - 1 - distance;
        distance = num_tracks - 1;
    }
    for (int i = 0; i < index; i++) {
        printf("%d ", track_pos[i]);
        totalDistance += abs(track_pos[i] - distance);
        distance = track_pos[i];
    }

    printf("\n\nAverage head movement: %.2f\n", (float)totalDistance / num_tracks);

    return 0;
}

