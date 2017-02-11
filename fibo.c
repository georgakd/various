#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <ctype.h>


int fibo(int N){
	
	
	
	if (N==0){return 0;}
	if (N==1){return 1;}
	
	//int a = 0;
	//int b = 1;
	//int c;
	//while (a<=N){
		
	//c=a+b;
	//a=b;
	//b=c;		
	//}

return (fibo(N-1)+fibo(N-2));	
}

int main(int argc, char *argv[]){

    int iterations,result,sum=0;
	iterations=atoi(argv[1]);
	
	for (int i=0;i<iterations;i++){
	result=fibo(i);
	printf("%d ",fibo(i));
	sum=sum+result;
}
    printf("The fibonacci series sum is: %d\n",sum);
	return 0;
}
