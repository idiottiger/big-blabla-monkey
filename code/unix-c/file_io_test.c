#include <stdio.h>

//file control options header file
#include <fcntl.h>


int main(){

	//open a file
	int fd = open("file_io_test.c",O_RDONLY);
	printf("just open file_io_test fd:%d \n",fd);
	
	printf("let's open it again \n");
	int fd2 = open("file_io_test.c",O_RDONLY);
	printf("second time open file_io_test fd:%d \n",fd2);

	if(fd != -1){
		close(fd);
	}

	if(fd2 != -1){
		close(fd2);
	}


	//creat file
	printf("let's create a file use 'creat' 'NO E END' function: \n");
	int fd3 = creat("__temp.txt",O_RDWR);
	//after create the temp txt, no permission list, so if invoke ls -l, result like follow:
	// ---------- 1 user user    0 Feb 18 01:59 temp.txt

	printf("create finish fd:%d\n", fd3);

	if(fd3 != -1){
		close(fd3);
	}

	return 0;
}