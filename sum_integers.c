/*
 * sum_integers.c: This program finds the sum of integers in different complexities
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

//O(N) complexity
int sum_int(int N){
	
	int sum=0;
	for(int i=0;i<N;i++){
		
		sum += i+1; //to include in the sum the n-th term
		
		}
	return sum;
	}

//O(N*N) complexity
int sum_int_complex(int N){
	
	int sum=0;
	for(int i=0;i<N;i++){
		for (int j=0;j<i+1;j++)
		sum += 1; //to include in the sum the n-th term
		
		}
	return sum;
	}

//O(1) complexity
int sum_int_simple(int N){
	
	int sum;
	sum = N*(N+1)/2;
	return sum;
	}



int main(int argc, char **argv){
	
	int numbers, result;
	if (argc < 2) 
    {    
      printf("Give an int arg. Example Usage: ./sum 1000\n\n");
      return EXIT_FAILURE;
    }
    else {numbers=atoi(argv[1]);}
	
	//result = sum_int(numbers);
	//result = sum_int_complex(numbers);
	result = sum_int_simple(numbers);
	printf("The sum of %d numbers is: %d\n",numbers,result);
	
	return 0;
	}
