#ifndef __U_API_H__
#define __U_API_H__

	#include <stdio.h>
	#include <fcntl.h>
	#include <stdlib.h>
	#include <errno.h>

	

	/** create file **/
	int uapi_is_directory(const char* path);
	int uapi_is_directory(int fd);

#endif