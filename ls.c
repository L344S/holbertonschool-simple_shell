#include "shell.h"
void listFilesInDirectory(const char *path) {
    DIR *dir;
    struct dirent *entry;

    /** Open the specified directory */
    dir = opendir(path);

    /** Check if the directory is opened successfully */
    if (dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    /** Read and print information about each entry in the directory */
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    /** Close the directory */
    closedir(dir);
}
