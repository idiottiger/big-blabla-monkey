/*
 *  jump_test.c
 *
 *  Created on: Sep 29, 2013
 *  Author: idiottiger
 *
 */

#include <stdio.h>
#include <setjmp.h>

int main(int argc, char **argv) {

    int skip = 0;

    int i = 10;
    printf("before jump:i=%d\n", i);

    jmp_buf point;
    //set jump position
    setjmp(point);

    printf("after point: i=%d\n", i);
    if (skip) {
        return 0;
    }
    printf("let's do something \n");
    i = 20;
    printf("modify the i value to:%d\n", i);

    skip = 1;
    longjmp(point, 1);
}
