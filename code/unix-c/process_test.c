#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int m_counter;


int main(){

	printf("current info[process_id:%d,parent_process_id:%d]\n",getpid(),getppid());

	m_counter = 20;

	printf("let's fork a new process \n");

	//in parent, it's return the child process id
	//in child, return 0

	//KEY POINT: fork vs vfork, fork will copy all content from parent, vfork don't copy, it will use the parent content
	//what happens if the parent terminates beforethe child? The answer
	//is  that  the initprocess  becomes  the  parent  process  of  any  process  whose  parent
	//terminates. 

	int new_pid = fork();
	if(new_pid == 0){
		m_counter+=2;
		printf("child [process_id:%d,parent_process_id:%d,new_pid:%d]\n",getpid(),getppid(),new_pid);	
		sleep(5);
	}else if(new_pid > 0){
		m_counter+=8;
		printf("parent end[process_id:%d,parent_process_id:%d,new_pid:%d]\n",getpid(),getppid(),new_pid);
	}
	
	printf("new_pid:%d,couter:%d \n",new_pid,m_counter);

	exit(0);
}