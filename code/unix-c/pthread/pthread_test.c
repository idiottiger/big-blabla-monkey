#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

//@@@ KEY POINTS
//1.pthread_cleanup_push when thread normal return, it run depend on the pthread_cleanup_pop method, if the pop arg is NOT 0, it will invoke, otherwise DOES NOT.
//	if thread exit NOT normally, like invoke: pthread_exit   pthread_cancel, it will invoke
//2.pthread_exit invoke, it's sync invoke, after this method, dont invoke anything
//	pthread_cancel and pthread_detach seems like async method



void* thread_run(void*);
void* thread_run2(void*);

void push1(void*);
void push2(void*);


int main(){

	pthread_t thread_id;

	//pthread_create 4 args:
	//id, atr, fun pointer, args
	int result = pthread_create(&thread_id, NULL, thread_run, NULL);

	if(result == 0){
		printf("create thread ok [id:%lu]\n",(unsigned long)thread_id);
	}else{
		printf("create thread error \n");
	}


	//@@@ KEY POINT: why sleep over, can also get the thread return? 
	// IF THE THREAD STATE IS DETACH, will use join method
	printf("main thread[id:%lu] sleep 3 sec \n",(unsigned long)pthread_self());
	sleep(3);

	void* thread_result = NULL;

	//will wait the thread_id call finish, if has return or use the pthread_exit pass the return, 
	//can set to the pass arg
	result = pthread_join(thread_id, &thread_result);
	if(result ==0 ){
		printf("thread run result:%s \n",(char*)thread_result);
		free(thread_result);
	}else{
		printf("thread join error \n");
	}


	printf("*********************************************************\n");
	printf("test the pthread_cleanup_push or pop \n");
	pthread_create(&thread_id, NULL, thread_run2, NULL);

	sleep(3);

	return 0;
}


void* thread_run(void* arg){
	printf("thread id:%lu, thread run .... \n",(unsigned long)pthread_self());
	//let's return something
	char* value = (char*)malloc(16*sizeof(char));
	strcpy(value,"hello return");
	//return value;
	//also you can use pthread_exit
	pthread_exit(value);
	//pthread_cancel(pthread_self());
}

void* thread_run2(void* arg){
	printf("register push 1\n");
	pthread_cleanup_push(push1,NULL);
	printf("register push 2\n");
	pthread_cleanup_push(push2, NULL);
	printf("register push end \n");
	printf("thread id:%lu, thread run2 .... \n",(unsigned long)pthread_self());

	// @@@@@@@@@@@@@@@@@@@ KEY POINT:
	//if return before pop, push method will not invoke
	//but if pthread_exit and pthread_cancel, the push will invoke, whatever the pop pass the 0 arg
	if(1){
		//return NULL;
		pthread_exit(NULL);
		//pthread_cancel(pthread_self());
	}
	printf("test method invoke after pthread_exit \n");
	pthread_cleanup_pop(0);
	pthread_cleanup_pop(0);

	return NULL;
}

void push1(void* arg){
	printf("thread id:%lu, push1 .... \n",(unsigned long)pthread_self());
}

void push2(void* arg){
	printf("thread id:%lu, push2 .... \n",(unsigned long)pthread_self());
}