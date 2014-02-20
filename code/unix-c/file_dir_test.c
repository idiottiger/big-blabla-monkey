#include <stdio.h>

//stat header file 
#include <sys/stat.h>
#include <fcntl.h>
#include "log.h"


#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int main(){

	//stat for normal files
	//use 'ln -s' create the symbolic link

	//if it's a link, stat will get the reference file by the link
	//use lstat to get the link information

	//so follow st_size are different on the 'stat' and 'lstat'

	struct stat buffer;	
	int result;

	result = lstat("__temp.txt",&buffer);
	if(result == -1){
		error_log("stat __temp.txt");
	}else{
		//can check the file type by S_ISxxx
		//S_ISREG, S_ISDIR, ...
		printf("__temp.txt [mode:%d,uid:%d,gid:%d,size:%ld, is normal file:%d] \n",buffer.st_mode,buffer.st_uid,buffer.st_gid,buffer.st_size,S_ISREG(buffer.st_mode));
	}

	//folder
	result = lstat("__temp",&buffer);
	if(result == -1){
		error_log("stat __temp");
	}else{
		printf("__temp [mode:%d,uid:%d,gid:%d,size:%ld, is DIR:%d] \n",buffer.st_mode,buffer.st_uid,buffer.st_gid,buffer.st_size,S_ISDIR(buffer.st_mode));
	}


	//another versions:
	// fstat   use the fd as the arg
	// fstatat same as fstat, but use for folder
	// function:
	// 	int fstatat(int fd,const char *restrictpathname,struct stat *restrictbuf,intflag);


	//access method to test the permission
	result = access("__temp.txt",X_OK);
	if(result == -1){
		error_log("test exe permission on __temp.txt");
	}else{
		printf("acess __temp.txt exe right\n");
	}


	//umask can disable create file or dir permission

	//enable all permission, default is 666, folder is 777
	umask(0);
	result = creat("__temp1",RWRWRW);

	//disable the other user's read
	umask(S_IROTH);
	creat("__temp2",RWRWRW);

	//chdir change current directory
	char cur_dir_buffer[256];
	getcwd(cur_dir_buffer, 256);

	printf("current directory:%s \n",cur_dir_buffer);
	printf("let's change current dir to /tmp \n");
	chdir("/tmp");

	getcwd(cur_dir_buffer, 256);

	printf("after current directory:%s \n",cur_dir_buffer);

	return 0;
}