#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BLOCK_SIZE 8192  // 8 KB
#define POINTERS_PER_BLOCK (BLOCK_SIZE / sizeof(int))
int block_bitmap[8589934592 / BLOCK_SIZE];
int is_block_free(int block_num) {
    return block_bitmap[block_num] == 0;
}
void allocate_block(int block_num) {
    block_bitmap[block_num] = 1;
}
int find_next_contiguous_blocks(int current_block, int num_blocks) {
    int contiguous_blocks = 0;
    int i;

    for (i = current_block + 1; i < 8589934592 / BLOCK_SIZE; i++) {
        if (is_block_free(i)) {
            contiguous_blocks++;
        } else {
            contiguous_blocks = 0;
        }

        if (contiguous_blocks == num_blocks) {
            return i - num_blocks + 1;
        }
    }

    return -1; 
}
long long find_max_file_size() {
    int direct_blocks = 12;
    int single_indirect_blocks = POINTERS_PER_BLOCK;
    int double_indirect_blocks = pow(POINTERS_PER_BLOCK, 2);
    int triple_indirect_blocks = pow(POINTERS_PER_BLOCK, 3);
    
    int max_file_blocks = direct_blocks +
                          single_indirect_blocks +
                          double_indirect_blocks +
                          triple_indirect_blocks;
    
    long long max_file_size = max_file_blocks * BLOCK_SIZE;
    
    return max_file_size;
}

int main() {
    long long max_file_size = find_max_file_size();
    printf("Maximum file size: %lld bytes\n", max_file_size);
    int start_block = 0;
    int num_blocks = 20;
    int i;

    for (i = 0; i < num_blocks; i++) {
        if (!is_block_free(start_block + i)) {
            start_block = find_next_contiguous_blocks(start_block + i, num_blocks - i);
            if (start_block == -1) {
                printf("Could not allocate contiguous blocks\n");
                return 1;
            }
        }

        allocate_block(start_block + i);
    }

    printf("Allocated blocks: ");
    for (i = 0; i < num_blocks; i++) {
        printf("%d ", start_block + i);
    }
    printf("\n");
    
    return 0;
}

