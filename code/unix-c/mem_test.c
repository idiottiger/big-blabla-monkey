#include <stdio.h>
#include <unistd.h>


int main(){

	//malloc
	int* int_array = (int*)malloc(sizeof(int)*100);
	if(!int_array){
		printf("malloc error \n");
	}


	//the pass int_array, don't care to free, the system will maintain
	int_array = (int*)realloc(int_array,sizeof(int)*200);
	if(!int_array){
		printf("realloc error \n");
	}


	free(int_array);


	return 0;
}