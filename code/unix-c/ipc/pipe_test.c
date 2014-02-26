#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

//parent process write, the child process read, and vice versa

int main(){

	int fd[2];

	pid_t pid;

	if(pipe(fd) < 0){
		printf("pipe create error \n");
		exit(1);
	}

	if((pid = fork()) < 0){
		printf("fork error \n");
		exit(1);
	}

	if(pid > 0){
		printf("parent process, close read fd\n");
		close(fd[0]);

		//let's write something
		const char* data = "hello pipe world";
		write(fd[1], data,strlen(data)*sizeof(char));

		sleep(2);

		exit(0);

	}else{
		printf("child process, close write \n");
		close(fd[1]);
		printf("start read from pipe \n");
		char rdata[64];
		int read_size = read(fd[0], rdata, 64);

		//@@@ KEY_POINT need set the string end char
		//rdata[read_size]='\0';
		//printf("readed:[%s] \n",rdata);


		//can also write to std output fd
		write(STDOUT_FILENO, rdata, read_size);

		exit(0);
	}

}
