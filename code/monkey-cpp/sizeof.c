#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char value[] = "12345";
	printf("size of value:%d,length:%d\n", sizeof(value),strlen(value));
	char* vp = value;
	printf("size of value 2:%d\n", sizeof(vp));
	int array[] = {1,2,3,4,5};
	printf("size of array:%d\n", sizeof(array));
	void* p = malloc(100);
	printf("size of p is:%d\n", sizeof(p));
	return 0;
}