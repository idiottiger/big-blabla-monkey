#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t m_mutex_locker;
int m_counter;


void mutex_init();
void mutex_release();
void mutexFun1();
void mutexFun2();
void* threadRun1(void *);
void* threadRun2(void *);


int main(){	
	
	atexit(mutex_release);

	pthread_t pid1;
	pthread_t pid2;

	mutex_init();

	int presult;

	presult = pthread_create(&pid1, NULL, threadRun1, NULL);
	//printf("create pid1 thread result:%d",presult);
	pthread_create(&pid2, NULL, threadRun2, NULL);

	sleep(10);

	return 0;
}

void mutex_init(){
	m_counter = 0;
	int result = pthread_mutex_init(&m_mutex_locker,NULL);
	printf("mutext init ... \n");
	if(result != 0){
		exit(1);
	}
}

void mutex_release(){
	pthread_mutex_destroy(&m_mutex_locker);
	printf("mutext destroy ... \n");
}

void mutexFun1(){
	m_counter++;
	printf("mutexFun1: %d\n",m_counter);
}

void mutexFun2(){
	m_counter--;
	printf("mutexFun2: %d\n",m_counter);
}

void* threadRun1(void* arg){
	while(1){
		pthread_mutex_lock(&m_mutex_locker);
		mutexFun1();
		pthread_mutex_unlock(&m_mutex_locker);
		sleep(1);
	}
}


void* threadRun2(void* arg){
	while(1){
		int result = pthread_mutex_trylock(&m_mutex_locker);
		printf("try lock result:%d\n", result);
		if(result==0){
			mutexFun2();
			pthread_mutex_unlock(&m_mutex_locker);
		}
		sleep(2);
	}	
}