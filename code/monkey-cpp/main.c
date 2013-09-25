/*
 *  main.c
 *
 *  Created on: Sep 25, 2013
 *  Author: idiottiger
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "string_tools.h"

int main(int argc, char **argv) {
    int result_size = 0;
    const char* str =
            "hello,go to, hoho, world, kicl,your ass,hoo, go,add, ello,";
    const char** result = string_split_string(str, '#', &result_size);

    if (result) {
        printf("str[%s] \n", str);
        printf("split result:[%d] \n", result_size);
        int i;
        for (i = 0; i < result_size; ++i) {
            printf("%s\n", result[i]);
        }

        for (i = 0; i < result_size; ++i) {
            free((void*) result[i]);
        }
        free((void*) result);
    }

    return 0;
}

