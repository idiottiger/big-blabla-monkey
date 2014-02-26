#include <stdio.h>

int accum = 0;
char acc;

int sum(int x, int y);

int main(){


	return 0;
}

int sum(int x,int y){
	int t = x+y;
	accum+=t;
	t+=acc;
	return t;
}