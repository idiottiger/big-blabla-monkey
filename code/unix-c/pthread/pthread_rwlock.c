#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_rwlock_t m_rwlock;

void lock_init();
void lock_destroy();

void* fun_read_lock1(void*);
void* fun_read_lock2(void*);
void* fun_write_lock3(void*);


//@@KEY_POINT pthread_rwlock_xxx, like: init, destroy, rdlock, wrlock, unlock, tryrdlock, trywrlock

int main(){

	atexit(lock_destroy);

	lock_init();


	pthread_t p1,p2,p3;

	pthread_create(&p1, NULL, fun_read_lock1, NULL);
	pthread_create(&p2, NULL, fun_read_lock2, NULL);
	pthread_create(&p3, NULL, fun_write_lock3, NULL);

	sleep(10);

	return 0;
}

void lock_init(){
	printf("lock init \n");
	pthread_rwlock_init(&m_rwlock, NULL);	
}

void lock_destroy(){
	printf("lock destroy \n");
	pthread_rwlock_destroy(&m_rwlock);
}

void* fun_read_lock1(void* arg){
	pthread_rwlock_rdlock(&m_rwlock);
	printf("fun read_1 lock ... \n");
	sleep(3);
	pthread_rwlock_unlock(&m_rwlock);
	printf("fun read_1 unlock ... \n");
}

void* fun_read_lock2(void* arg){
	pthread_rwlock_rdlock(&m_rwlock);
	printf("fun read_2 lock ... \n");
	sleep(2);
	pthread_rwlock_unlock(&m_rwlock);
	printf("fun read_2 unlock ... \n");
}

void* fun_write_lock3(void* arg){
	sleep(1);
	printf("prepare write lock ... \n");
	pthread_rwlock_wrlock(&m_rwlock);
	printf("fun write lock ... \n");
	sleep(2);
	pthread_rwlock_unlock(&m_rwlock);
	printf("fun write unlock ... \n");
}