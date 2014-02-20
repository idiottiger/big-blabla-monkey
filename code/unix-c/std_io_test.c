#include <stdio.h>
#include <stdlib.h>
#include "log.h"


int main(){

	FILE* file = fopen("__temp.txt","a+");
	if(file){
		//1. read char one by one
		int data;
		char value[2];
		printf("-------- type 1 ------------------------------------- \n");
		printf("read char one by one \n");
		while((data = getc(file)) != EOF){
			value[0] = (char)data;
			value[1] = '\0';
			printf("%s",value);
		}
		printf("\n");

		//here test the seek, so as we know if a+, before write, the offset will be the file end
		int result = fseek(file,0,SEEK_SET);
		printf("seek back to zero: %d \n",result);

		const char* write_content = "[new write]";
		printf("write sth:[%s]\n",write_content);
		size_t length = strlen(write_content);
		size_t i = 0;
		while(i < length){
			putc(write_content[i],file);
			i++;
		}

		printf("write finish, let's read again \n");
		result = fseek(file,0,SEEK_SET);
		printf("seek back to zero again: %d \n",result);
		//need back to pos 0

		while((data = getc(file)) != EOF){
			value[0] = (char)data;
			value[1] = '\0';
			printf("%s",value);
		}
		printf("\n");

		printf("-------- type 2 ------------------------------------- \n");
		result = fseek(file,0,SEEK_SET);
		printf("read line by line \n");

		char line[256];
		while(fgets(line, 256, file)){
			printf("%s",line);
		}
		printf("\n");

		fputs(write_content,file);

		fclose(file);
	}else{
		error_log("fopen __temp.txt error");
	}


	return 0;
}