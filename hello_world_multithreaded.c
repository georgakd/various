/*
 * hello_world_multithreaded.c: This program uses pthreads for hello world
 * 
 * Copyright 2016 Dimitra Georgakaki
 * 
 */



#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


int thread_count; //global, shared by all the threads

void* Hello(void* rank); //thread function

int main(int argc, char *argv[]){
	
	long thread; //in case of 64-bit
	pthread_t* thread_handles;
	
	if (argc < 2) 
    {    
      printf("Give an int for number of threads. Example Usage: ./threads 10\n\n");
      return EXIT_FAILURE;
    }
    else {thread_count=atoi(argv[1]);}	
	
	thread_handles=malloc(thread_count*sizeof(pthread_t));
	
	for(thread=0;thread<thread_count;thread++)
	  pthread_create(&thread_handles[thread],NULL,Hello,(void*)thread);
	
	printf("Hello from main thread\n");
	
	for (thread=0;thread<thread_count;thread++)
	  pthread_join(thread_handles[thread],NULL);
	
	free(thread_handles);
	return 0;
	}

void* Hello(void* rank){
	
	long my_rank = (long)rank;
	printf("Hello from thread number:%ld \n",my_rank);
	
	return NULL;
	}
