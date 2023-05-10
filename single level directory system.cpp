#include<stdio.h>
#include<string.h>

#define MAX_FILES 100

struct file {
    char name[20];
};

struct directory {
    char name[20];
    struct file files[MAX_FILES];
    int num_files;
};

int main() {
    struct directory dir;
    int i;

     
    strcpy(dir.name, "CSE");
    dir.num_files = 0;

     
    strcpy(dir.files[0].name, "A");
    dir.num_files++;

    strcpy(dir.files[1].name, "B");
    dir.num_files++;

    strcpy(dir.files[2].name, "C");
    dir.num_files++;

     
    printf("Directory: %s\n", dir.name);
    printf("Files:\n");
    for(i=0; i<dir.num_files; i++) {
        printf("- %s\n", dir.files[i].name);
    }

    return 0;
}
