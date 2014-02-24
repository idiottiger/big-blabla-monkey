#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


//pthread_cond_t seems like the java wait and notify method

pthread_mutex_t m_mutex;
pthread_cond_t m_cond;

int m_counter;

void init();
void destroy();

void* fun1(void*);
void* fun2(void*);


int main(){

	atexit(destroy);

	init();

	pthread_t p1,p2;
	pthread_create(&p1, NULL, fun1, NULL);
	pthread_create(&p2, NULL, fun2, NULL);


	sleep(20);

	return 0;
}


void init(){
	printf("init \n");
	pthread_mutex_init(&m_mutex, NULL);
	pthread_cond_init(&m_cond, NULL);
	m_counter = 0;
}

void destroy(){
	printf("destroy \n");
	pthread_cond_destroy(&m_cond);	
	pthread_mutex_destroy(&m_mutex);
}

void* fun1(void* arg){
	printf("func1 ...\n");
	pthread_mutex_lock(&m_mutex);
	printf("mutex lock ... \n");
	if(m_counter < 10){
		printf("wait for cond \n");
		pthread_cond_wait(&m_cond, &m_mutex);
		printf("COND OK value:%d \n",m_counter);
	}
	pthread_mutex_unlock(&m_mutex);
}

void* fun2(void* arg){
	sleep(2);
	printf("func2 ...\n");
	while(m_counter < 10)
	{
		m_counter++;
		printf("counter value: %d \n",m_counter);
		sleep(1);
	}

	//diff with java, don't need invoke in the lock block
	pthread_cond_signal(&m_cond);
}