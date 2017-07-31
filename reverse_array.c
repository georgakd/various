/*
 * reverse_array.c: This program reverses an array
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



void reverse_array(int length, int *array_1, int *array_2){
	 

printf("The length is: %d\n",length);

for (int i=0;i<length;i++)
{
	//array_2[i] = array_1[length-i-1];
	*(array_2+i) = *(array_1+length-i-1);
	printf("The reverse is %d %d\n",i,*(array_2+i));
	
	}

}

int main(int argc, char *argv[]){
    
    int N;
    N=atoi(argv[1]);
    int * ar1 = (int *) malloc (N*sizeof (int));
    int * ar2 = (int *) malloc (N*sizeof (int));
    
    for (int i=0;i<N;i++)
    {
        printf("enter the integer number %d\n", i);
        //scanf("%d", &ar1[i]);
        scanf("%d", ar1+i);
    }
    
    reverse_array(N,ar1,ar2);

    
    free(ar1);free(ar2); 
	return 0;
}
