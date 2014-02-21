#include <stdio.h>
#include <unistd.h>
#include "log.h"

void exit_callback1(){
	printf("callback 1 \n");
}
void exit_callback2(){
	printf("callback 2 \n");
}

int main(){
	long rfun_nums;
	rfun_nums = sysconf(_SC_ATEXIT_MAX);
	printf("exit register fun max number is: %ld\n", rfun_nums);

	//register exit callback

	//reverse order
	atexit(exit_callback1);
	atexit(exit_callback2);

	exit(EXIT_FAILURE);
}