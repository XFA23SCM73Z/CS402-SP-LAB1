#include "readfile.h"

static FILE *fp = NULL;

int open_file(const char *filename) {
    fp = fopen(filename, "r");
    if (fp == 0) {
        perror("Error opening file");
        return -1;
    }
    return 0;
}

int read_int(int *value) {
    int result = fscanf(fp, "%d", value);
    if (result == 1) {
        // If fscanf successfully read an integer, print it
        //    printf("Read integer: %d\n", *value);
    } else {
        // If fscanf failed to read an integer, print an error message
        printf("Failed to read an integer.\n");
    }
    return result;
}



int read_string(char *str, int max_length) {
    int result = fscanf(fp, "%63s", str); // Ensure to not read more than the buffer can handle
    if (result == 1) {
//        printf("Debug read_string: %s\n", str); // Debug print
    } else {
//Debug read_string: Failed to read string.\n");
    }
    return result != 1; // Return 0 on success, non-zero otherwise
}

int read_float(float *value) {
    return fscanf(fp, "%f", value);
}

void close_file() {
    if (fp) {
        fclose(fp);
        fp = NULL;
    }
}
