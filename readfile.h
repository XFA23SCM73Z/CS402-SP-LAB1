//
// Created by sue on 10/30/23.
//

#ifndef CS402_SP_LAB1_READFILE_H
#define CS402_SP_LAB1_READFILE_H
#include <stdio.h>

int open_file(const char *filename);
int read_int(int *value);
int read_string(char *str, int max_length);
int read_float(float *value);
void close_file();

#endif //CS402_SP_LAB1_READFILE_H
