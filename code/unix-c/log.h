#ifndef __LOG_H__
#define  __LOG_H__

#include <stdio.h>
#include <errno.h>

void error_log(const char* msg);

void error_log(const char* msg){
	fprintf(stderr,"!ERROR [%s], Reason:[%s] \n",msg,strerror(errno));
}


#endif