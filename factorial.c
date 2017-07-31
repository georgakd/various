/*
 * factorial.c: This program calculates the factorial of a number
 * 
 * Copyright 2016 Dimitra Georgakaki
 * 
 */


#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <ctype.h>


int factorial(int N){
	
	int fact=1;
	
	for (int i=1;i<N+1;i++){
		
		fact*=i;
		
		}
	
	
	return fact;
	}



int main(int argc,char **argv){

    int numbers, result;
	numbers=atoi(argv[1]);
	result = factorial(numbers);
	printf("The factorial of %d numbers is: %d\n",numbers,result);	
	
	return 0;
	}
