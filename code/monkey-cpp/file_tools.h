/*
 *  file_tools.h
 *
 *  Created on: Sep 25, 2013
 *  Author: idiottiger
 *
 */

#ifndef FILE_TOOLS_H_
#define FILE_TOOLS_H_

#include <stdio.h>

int file_copy_file_content(const char* src, const char* dest);

int file_copy_file_content(const char* src, size_t copy_offset,
                           size_t copy_length, const char* dest,
                           size_t dest_offset);

int file_copy_file_content(FILE* srcFile, FILE* destFile);

char* file_get_file_content(const char* path);
char* file_get_file_content(const char* path, size_t read_offset,
                            size_t read_size);
char* file_get_file_content(FILE* file);

off_t file_get_file_length(const char* path);

#endif /* FILE_TOOLS_H_ */
