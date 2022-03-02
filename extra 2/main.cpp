#include <stdio.h>
#include <stdlib.h>

int ackermann(int m, int n){
	if(m==0){
		return n+1;
	}
	if (m>0&&n==0){
		return ackermann(m-1,1);
	}
	if(m>0&&n>0){
		return ackermann(m-1,ackermann(m,n-1));
	}
	
}


int main(int argc, char *argv[]) {
	int res=0;
	res = ackermann(2,1);
	printf("resultado e %d",res);

	return 0;
}
