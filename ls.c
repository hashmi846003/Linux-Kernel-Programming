#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char *argv[]) {
    DIR *dp;
    struct dirent *dirp;
    struct stat statbuf;
    char path[1024];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s directory_name\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    dp = opendir(argv[1]);
    if (dp == NULL) {
        perror("Can't open directory");
        exit(EXIT_FAILURE);
    }

    while ((dirp = readdir(dp)) != NULL) {
        snprintf(path, sizeof(path), "%s/%s", argv[1], dirp->d_name);
        if (stat(path, &statbuf) == 0 && S_ISDIR(statbuf.st_mode)) {
            printf("%s\n", dirp->d_name);
        }
    }

    closedir(dp);
    return 0;
}

