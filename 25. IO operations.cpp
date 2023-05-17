#include <stdio.h>

int main() {
    int file_size = 100; 
    int block_size = 1; 
    int block_number; 
    int contiguous_iops = 2; 
    int linked_iops = 2; 
    int indexed_iops = 2; 
    block_number = 0;
    contiguous_iops = 1; 
    linked_iops = 2;
    indexed_iops = 2; 
    block_number = file_size / 2;
    contiguous_iops = 2;
    linked_iops = 3; 
    indexed_iops = 3; 
    block_number = file_size;
    contiguous_iops = 1; 
    linked_iops = 2; 
    indexed_iops = 2; 
    printf("Contiguous allocation requires %d I/O operations.\n", contiguous_iops);
    printf("Linked allocation requires %d I/O operations.\n", linked_iops);
    printf("Indexed allocation requires %d I/O operations.\n", indexed_iops);

    return 0;
}

