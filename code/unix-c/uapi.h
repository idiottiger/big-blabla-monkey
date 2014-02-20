#ifndef __U_API_H__
#define __U_API_H__

	#include <stdio.h>
	#include <fcntl.h>
	#include <stdlib.h>
	#include <errno.h>

	

	/** create file **/
	int uapi_create_file(const char* path);

#endif