#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "log.h"

struct student{
	int id;
	char name[64];
	float score;
};


int main(){

	FILE* file = 0;
	file = fopen("__temp3","a+");
	if(file){
		struct student s;
		s.id = 100;
		strcpy(s.name,"ZhangShan");
		s.score = 96.5f;

		printf("write struct student to the file \n");

		if(fwrite(&s,sizeof(s),1,file) != 1){
			error_log("write error");
		}

		//seek to start and read it
		//int result = fseek(file,0,SEEK_SET);

		//back to the start pos
		rewind(file);
		printf("let's read \n");

		struct student s2;
		if(fread(&s2,sizeof(s2),1,file)!=1){
			error_log("read error");
		}else{
			printf("read student[id:%d,name:%s,score:%f] \n",s2.id,s2.name,s2.score);
		}
		fclose(file);
	}else{
		error_log("__temp3 error");
	}


	//temp function
	char temp_name[64];
	tmpnam(temp_name);

	printf("random temp name: %s",temp_name);	

	FILE* tf = tmpfile();

	return 0;
}