#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    DIR *dp;
    struct dirent *dirp;

    if (argc != 2) {
        fprintf(stderr, "usage: %s directory_name\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((dp = opendir(argv[1])) == NULL) {
        perror("can't open directory");
        exit(EXIT_FAILURE);
    }

    while ((dirp = readdir(dp)) != NULL) {
        printf("%s\n", dirp->d_name);
    }

    closedir(dp);
    return 0;
}

