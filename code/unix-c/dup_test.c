#include <fcntl.h>
#include "log.h"


int main(){

	//open a file
	int fd = open("__temp.txt",O_RDONLY);

	if(fd == -1){
		error_log("open __temp.txt");
	}else{
		//duplicate this fd
		//the eixt-auto-close will not dup, if want so, need use dup2 method
		int new_fd = dup(fd);

		//the offset and permission will share 

		printf("fd[%d], and dup fd[%d]\n", fd, new_fd);

		//let's change the offset
		printf("let's change the fd offset \n");

		off_t offset, new_offset;

		offset = lseek(fd,100,SEEK_SET);

		new_offset = lseek(new_fd,0,SEEK_CUR);

		printf("fd offset[%ld], new fd offset [%ld]\n", offset, new_offset);


		printf("let's test the permission, write method\n");
		const char* content = "write sth.";

		size_t write_size = write(new_fd,content,strlen(content));
		if(write_size == -1){
			error_log("test write");
		}

		close(fd);
		close(new_fd);

	}



	return 0;
}