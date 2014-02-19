#include <stdio.h>

//file control options header file
#include <fcntl.h>

#include <errno.h>
#include <dirent.h>
#include <string.h>

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


	//test openat function
	//openat(int fd, const char*  path, int  mode, ...);

	//if it's a folder, can not use the open or open at to open this folder
	// need use ** opendir ** method
	DIR* dir = opendir("__temp");

	//see the doc: http://man7.org/linux/man-pages/man3/dirfd.3.html
	int temp_folder_fd = dirfd(dir);

	printf("temp folder fd: %d\n", temp_folder_fd);

	if(temp_folder_fd == -1){
		fprintf (stderr, "Couldn't open file %s; %s\n","temp_folder_fd", strerror (errno));
	}

	int temp_1_fd = openat(temp_folder_fd,"__temp1.txt",O_RDWR);
	printf("open __temp1.txt under temp folder : %d\n", temp_1_fd);	

	if(temp_folder_fd != -1){
		close(temp_folder_fd);
	}

	if(temp_1_fd != -1){
		close(temp_1_fd);
	}

	closedir(dir);


	//creat file
	printf("let's create a file use 'creat' 'NO E END' function: \n, owner read and write \n");

	//if this existed this file, will trunc the data size to 0
	// creat equlas ** open (... O_CREAT|O_WRONLY|O_TRUNC )
	//int fd3 = creat("__temp.txt",S_IRUSR|S_IWUSR);
	// if use O_APPEND, will don't trunc size to 0

	// *** when use O_APPEND, before write will set offset to the end of file, so lseek doesn't work here***
	int fd3 = open("__temp.txt", O_CREAT| O_RDWR | O_APPEND,S_IRUSR|S_IWUSR);

	printf("create finish fd:%d\n", fd3);

	//if fd is pipe,FIFO, or socket, will return -1
	off_t cur_offset = lseek(fd3,0,SEEK_CUR);

	//the off_t seem like 'long int'
	printf("current temp file seek pos: %ld\n", cur_offset);


	//write something
	const char* value = "add something";

	//seek pos
	cur_offset = lseek(fd3,100,SEEK_SET);
	printf("seek 30 result:%ld \n",cur_offset);

	write(fd3,value,strlen(value));

	if(fd3 != -1){
		close(fd3);
	}

	return 0;
}
