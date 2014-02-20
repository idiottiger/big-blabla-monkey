#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include "log.h"


void searchPath(const char* path){
	struct stat buffer;
	int result = stat(path, &buffer);
	if(result == -1){
		error_log("path error");
	}else{
		//check is folder or file
		if(S_ISDIR(buffer.st_mode)){
			DIR* dir = opendir(path);
			if(dir){
				struct dirent* dir_struct = NULL;
				char new_path[1024];
				while((dir_struct = readdir(dir))!=NULL){

					// ** KEY POINT: must ignore the . and .. folder **
					if(strcmp(dir_struct->d_name,".") == 0 || strcmp(dir_struct->d_name,"..") == 0 ){
						continue;
					}
					strcpy(new_path,path);
					strcat(new_path,"/");
					strcat(new_path,dir_struct->d_name);
					searchPath(new_path);
				}
				closedir(dir);
			}else{
				error_log("dir error");
			}
		}else{
			printf("%s \n",path);
		}
	}
}


int main(int argc, char *argv[]){
	if(argc != 2){
		error_log("arg number error");
	}else{
		const char* path = argv[1];
		printf("start search folder:%s \n",path);
		searchPath(path);
	}
	return 0;
}