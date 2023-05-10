#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int frames[MAX], page_faults = 0, hit = 0, n, m;

void optimal(int page[], int size) {
    int i, j, k, flag1, flag2, max, page_to_replace;
    for (i = 0; i < size; i++) {
        flag1 = flag2 = 0;
        for (j = 0; j < n; j++) {
            if (frames[j] == page[i]) {
                hit++;
                flag1 = flag2 = 1;
                break;
            }
        }
        if (flag1 == 0) {
            for (j = 0; j < n; j++) {
                if (frames[j] == -1) {
                    page_faults++;
                    frames[j] = page[i];
                    flag2 = 1;
                    break;
                }
            }
        }
        if (flag2 == 0) {
            max = -1;
            for (j = 0; j < n; j++) {
                flag1 = 0;
                for (k = i + 1; k < size; k++) {
                    if (frames[j] == page[k]) {
                        flag1 = 1;
                        if (k > max) {
                            max = k;
                            page_to_replace = j;
                        }
                        break;
                    }
                }
                if (flag1 == 0) {
                    page_faults++;
                    frames[j] = page[i];
                    flag2 = 1;
                    break;
                }
            }
            if (flag2 == 0) {
                page_faults++;
                frames[page_to_replace] = page[i];
            }
        }
        printf("\n");
        for (j = 0; j < n; j++) {
            printf("%d\t", frames[j]);
        }
    }
}

int main() {
    int page[MAX];
    int i, j;
    printf("Enter the number of page frames: ");
    scanf("%d", &n);
    printf("Enter the number of pages: ");
    scanf("%d", &m);
    printf("Enter the page reference sequence: ");
    for (i = 0; i < m; i++) {
        scanf("%d", &page[i]);
    }
    for (i = 0; i < n; i++) {
        frames[i] = -1;
    }
    printf("\n\nPage Frames:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", i);
    }
    printf("\n");
    optimal(page, m);
    printf("\n\nTotal Page Faults: %d\n", page_faults);
    printf("Total Hits: %d\n", hit);
    printf("Hit Ratio: %f\n", (float) hit / (float) m);
    printf("Miss Ratio: %f\n", 1 - ((float) hit / (float) m));
    return 0;
}
