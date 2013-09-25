/*
 * string_tools.c
 *
 *  Created on: Sep 24, 2013
 *      Author: idiot2ger
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "string_tools.h"

const char** string_split_string(const char* str, char splite,
                                 int* resultArraySize) {
    //check the string
    if (str == NULL) {
        return NULL;
    }

    int default_malloc_size = 8;
    int malloc_size = default_malloc_size;
    int result_index = 0, str_index = 0, previous_index = 0;
    const char* p = str;
    char c;

    char** result = NULL;
    while ((c = *p++) != 0
            || (!c && previous_index != str_index && previous_index != 0)) {

        //have length
        if ((c == splite && str_index - previous_index > 0) || !c) {
            if (!result) {
                result = (char**) malloc(sizeof(char*) * malloc_size);
                if (!result) {
                    exit(1);
                }
            }

            //check the length
            if (result_index >= malloc_size) {
                int new_malloc_size = default_malloc_size + malloc_size;
                char** new_result = realloc(result,
                                            sizeof(char*) * new_malloc_size);
                if (!new_result) {
                    exit(1);
                }

                result = new_result;
                malloc_size = new_malloc_size;
            }

            //get the string
            int part_size = str_index - previous_index;
            char* value = malloc(sizeof(char) * part_size + 1);
            if (!value) {
                exit(1);
            }

            strncpy(value, str + previous_index, part_size);

            //need set the end '\0'
            value[part_size] = '\0';

            previous_index = str_index + 1;

            result[result_index++] = value;

            //if last, will break
            if (!c) {
                break;
            }
        }

        str_index++;

    }

    *resultArraySize = result_index;

    return (const char**) result;
}
