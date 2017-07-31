/*
 * digits.c: This program counts the digits of a number
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


int digits(int N){
	
	int result = 0;
	
	while (N>0){
		
	N = N /10;
	result+=1;		
	
	}

return result;	
}

int main(int argc, char *argv[]){

    int number,num_digits;
	number=atoi(argv[1]);
	num_digits=digits(number);

    printf("The number of digits for number %d is: %d\n",number,num_digits);
	return 0;
}
