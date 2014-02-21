#include <stdio.h>
#include <stdlib.h>

int main(){

	//set the env
	int result = setenv("ENV_1_KEY","hello dog",1);
	if(result!=0){
		printf("env ENV_1_KEY set error");
	}else{
		char* value = getenv("ENV_1_KEY");
		printf("key:%s - > value:%s \n","ENV_1_KEY",value);

		printf("let's disable the key \n");
		unsetenv("ENV_1_KEY");
		value = 0;
		value = getenv("ENV_1_KEY");
		if(value){
			printf("after disable key:%s - > value:%s \n","ENV_1_KEY",value);
		}else{
			printf("can not get the env\n");
		}

		//test putenv method
		//the putenv need use key=value this format
		const char* data = "ENV_2_KEY=good_money";
		result = putenv(data);
		if(result!=0){
			printf("env ENV_2_KEY set error");
		}else{
			value = getenv("ENV_2_KEY");
			if(value){
				printf("key:%s -> value:%s","ENV_2_KEY \n",value);
			}
		}
	}

	return 0;
}