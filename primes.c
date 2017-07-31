/*
 * primes.c: This program finds prime numbers
 * 
 * Copyright 2016 Dimitra Georgakaki
 * 
 */


#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>


int divisors(int N){
	 
	int i=1,result=0;
	
	while (i*i<N){
		
		if (N%i==0) {result+=2;}		
		
		i++;
		}
	if (i*i==N) {result+=1;} 

   return result;
}

int main(int argc, char *argv[]){
    
    int N,result;
    N=atoi(argv[1]);
    result=divisors(N);
    
    if (result == 2)
		printf("The divisors of %d are %d, so it is a prime.\n",N,result);
	else
		printf("The divisors of %d are %d, so it is NOT a prime.\n",N,result);
	return 0;
}
