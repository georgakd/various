/*
 * fnmatch.c: This program is actually a grep for an exact pattern in a file
 * usage: fnmatch --pattern test filename (test is the pattern to be matched and filename the input file)
 * 
 * Copyright 2016 Dimitra Georgakaki
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define MAX_NAME 256 //255 for a linux file name plus the \0 character

void fnmatch(char* file_arg, char* test_pattern) {

    FILE* fp;
    int i,j,k,c,line_number,flag;
    char* line;

//*************First part: Read file line by line*********************//
    
    fp=fopen(file_arg, "r");   
    if (fp == NULL) 
    {
      fprintf(stderr, "Can't open input file!\n");
      exit(EXIT_FAILURE);
    }
    
    i = 0; // in order to have the length of each line
    line_number = 0; //in order to have each line_number 
    while(1) 
    { 
	  c = fgetc(fp);
      if(feof(fp))
      {
         break ;
      }	
	  i=i+1;	  	
	  if(c==10)  // 10 corresponds to '\n'
	  { 
		    line_number++;
            //printf("[%d]\n",i-1);   // ignore '\n'
            fseek(fp,-i,SEEK_CUR);  
            line=(char*)malloc((i+1)*sizeof(char)); //add '\n'
            fgets(line,i+1,fp);
//*****************Second part: Match pattern*************************// 
   if (i!=1){ //check for null lines
      for(j=0;j<=strlen(line)-strlen(test_pattern);j++) 
      {			
		 flag = j;
		  		
		for (k=0;k< strlen(test_pattern);k++) 
		{
			if (test_pattern[k] == line[flag]) 
			{
			  flag++;
			}
			else 
			{
			  break;
			}		
	    } //end for k
	    
	    if (k==strlen(test_pattern)) 
	    {printf("pattern found in line: %d\t%s",line_number,line);}
	  
     } // end for j
   }      
//*****************Second part: Match pattern*************************//             
            free(line);
            i=0;                   
        }
   
    } //end of while for file reading      
    fclose( fp );    
}
	
int main(int argc, char *argv[]) {
	
	const char *errmsg = "usage: fnmatch --pattern test filename\n";
	
	if(argc!=4)
	{
		fprintf(stderr, errmsg);
		exit(EXIT_FAILURE);
    }	
	
	if (strcmp(argv[1],"--pattern") != 0)
	{
      printf("Please enter the keyword --pattern and try again.\n");
      exit(EXIT_FAILURE);
    }
	
    fnmatch(argv[3],argv[2]);

	return EXIT_SUCCESS;
}	

