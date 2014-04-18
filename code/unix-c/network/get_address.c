#include "net.h"

int main(){	

	struct addrinfo hint;
	struct addrinfo *results;

	memset(&hint, 0, sizeof(hint));
	hint.ai_family = AF_UNSPEC;

	int result_code = getaddrinfo("localhost", "1234", &hint,& results);

	if(result_code!=0){
		fprintf(stderr, "get addr info error: %s\n", gai_strerror(result_code));
	}else{
		struct addrinfo 
	}

	return 0;
}