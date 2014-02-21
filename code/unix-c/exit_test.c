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
	//_exit,_Exit vs exit
	//if _exit and _Exit WILL DONT INVOKE atexit register, and dont flush std

	atexit(exit_callback1);
	atexit(exit_callback2);

	_exit(0);
}