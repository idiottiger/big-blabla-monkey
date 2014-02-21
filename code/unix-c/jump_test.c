#include <stdio.h>
#include <stdlib.h>

//use jump, need add setjmp.h
#include <setjmp.h>

jmp_buf m_jump_buffer;
int m_value;

void func1();
void func2();
void func3();


int main(){

	m_value = 1;

	printf("let's test the jump function: value:%d\n",m_value);

	int result = -1;

	result = setjmp(m_jump_buffer);
	printf("set jmp result :%d\n",result);

	if(result == 0){
		func1();
	}
	printf("value :%d\n", m_value);
	return 0;
}


void func1(){
	printf("func 1 ...\n");
	func2();
}

void func2(){
	printf("func 2 ...\n");
	func3();
}

void func3(){
	m_value = 20;
	longjmp(m_jump_buffer,10);
	printf("func 3 ...\n");
}