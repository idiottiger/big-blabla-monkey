/*
 *  main.c
 *
 *  Created on: Sep 25, 2013
 *  Author: idiottiger
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

//    if (argc != 2) {
//        printf("the argument number must be 2");
//        exit(1);
//    }
//
//    //use the fseeko and ftello to get the size bigger than int size limit
//    FILE* file = fopen(argv[1], "rb");
//    if (file) {
//        int seek = fseeko(file, 0, SEEK_END);
//        if (seek == 0) {
//            off_t file_length = ftello(file);
//            //print with lld
//            printf("[%s] file length:[%lld]", argv[1], file_length);
//            rewind(file);
//        }
//        fclose(file);
//    }

//temp file
    char path[L_tmpnam];
    tmpnam(path);
    printf("temp file[%s],length[%d]\n", path, strlen(path));



    return 0;
}

