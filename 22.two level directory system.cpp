#include<stdio.h>
#include<string.h>

struct directory{
    char name[20];
    int n_files;
    char file_names[10][20];
}user[3];

int main(){
    int i, j, flag=0;
    char file[20], dir[20];
    strcpy(user[0].name, "user1");
    user[0].n_files = 3;
    strcpy(user[0].file_names[0], "file1.txt");
    strcpy(user[0].file_names[1], "file2.txt");
    strcpy(user[0].file_names[2], "file3.txt");

    strcpy(user[1].name, "user2");
    user[1].n_files = 2;
    strcpy(user[1].file_names[0], "file4.txt");
    strcpy(user[1].file_names[1], "file5.txt");

    strcpy(user[2].name, "user3");
    user[2].n_files = 2;
    strcpy(user[2].file_names[0], "file6.txt");
    strcpy(user[2].file_names[1], "file7.txt");
    printf("Enter file name: ");
    scanf("%s", file);
    printf("Enter directory name: ");
    scanf("%s", dir);
    for(i=0; i<3; i++){
        if(strcmp(user[i].name, dir)==0){
            flag = 1;
            for(j=0; j<user[i].n_files; j++){
                if(strcmp(user[i].file_names[j], file)==0){
                    printf("File found in %s directory.\n", dir);
                    break;
                }
            }
            if(j==user[i].n_files){
                printf("File not found in %s directory.\n", dir);
            }
            break;
        }
    }
    if(flag==0){
        printf("Directory not found.\n");
    }

    return 0;
}

