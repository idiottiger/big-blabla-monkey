/*
 *  main.c
 *
 *  Created on: Sep 25, 2013
 *  Author: idiottiger
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

    if (argc != 2) {
        printf("the argument number must be 2");
        exit(1);
    }

    FILE* file = fopen(argv[1], "rb");
    if (file) {
        int seek = fseeko(file, 0, SEEK_END);
        if (seek == 0) {
            off_t file_length = ftello(file);
            printf("[%s] file length:[%lld]", argv[1], file_length);
            rewind(file);
        }
        fclose(file);
    }

    return 0;
}

