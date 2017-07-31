/*
 * bsearch.c: This program uses binary search algorithm to search for a key in a spreadsheet-like file (e.g csv).
 * First column represents the key and it must not be dublicate.
 * usage: bsearch --key test filename (where test is the key to search and filename the file)
 * 
 * Copyright 2016 Dimitra Georgakaki
 * 
 */
 
 
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>


void bsearch_custom(char* test_key, int lines, char *master, int *map, int max_first_tok) {
    
    char *myword;
    int first,last,middle,i,j;
    first = 1;
    last = lines;
    
    myword=(char*)malloc((max_first_tok+1)*sizeof(char));
    
    middle = floor((first+last)/2);
    
    while (first <= last) { //divide a
        
        myword[0]='\0';
        j=-1;
        for(i=map[middle-1];i<map[middle-1+1];++i){
			j=j+1;
			myword[j]=master[i];}
		    myword[j+1]='\0';

        if  (strcmp(myword, test_key) < 0)
            
            first = middle + 1;
        else if (strcmp(myword, test_key) == 0) {
            
            //must check for multiple occurences to the right and to the left of the pattern found
            int right=middle+1;
            int left=middle-1;
            while(right<=last)
            {                
                myword[0]='\0';j=-1;for(i=map[right-1];i<map[right-1+1];++i){j=j+1;myword[j]=master[i];}myword[j+1]='\0';
                
                if((strcmp(myword, test_key) == 0))
                    
                    printf("%s found at location %d.\n", test_key, right);
                else//to terminate the loop
                    break;
                right++;//increment to check terms further right
            }
            while(left>=0)//for left side
            {
                myword[0]='\0';j=-1;for(i=map[left];i<map[left-1+1];++i){j=j+1;myword[j]=master[i];}myword[j+1]='\0';

                if((strcmp(myword, test_key) == 0))
                    
                    printf("%s found at location %d.\n", test_key, left);
                else//to terminate the loop
                    break;
                left-=1;//decrement to check terms further left
            }
            //must check for multiple occurences//
            printf("%s found at location %d.\n", test_key, middle);
            break;
        }
        else
            last = middle - 1;
        
        middle = floor((first+last)/2);
        
        
    } //end while
    if (first > last)
        printf("Not found! %s is not present in the list.\n", test_key);
    
    free(myword);
    
}

void read_file(char* file_arg, char* test_key) {
    
    FILE* fp;
    int i,j,k,c,line_number,column_number;
    char *line;
    char* ptr;
    int first_tok; // stores the position of the first token per line
    int max_first_tok=0;
    char *master=NULL; //stores as a 1D array the first token of each line, passed into bsearch
    int *map=NULL; //stores an indexing of the number of characters of each of the tokens of array master 
    
    //*************First part: Read file line by line*********************//
    
    fp=fopen(file_arg, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Can't open input file!\n");
        exit(EXIT_FAILURE);
    }
    
    i = 0; // in order to have the length of each line
    line_number = 0; //in order to have each line_number
    column_number = 0; //in order to have each column_number
    first_tok=0;

    while(1)
    {
       c = fgetc(fp);
        if(feof(fp))
        {
            break ;
        }
        i=i+1;
        if (c==44) // 44 corresponds to comma
        {
            column_number++;
            if(first_tok==0)first_tok=i-1; // first line first token
        }
        
        // find max token (regarding the number of characters)
        if(first_tok>max_first_tok)max_first_tok=first_tok;
        
        if(c==10)  // 10 corresponds to '\n'
        {
            
            line_number++;
            fseek(fp,-i,SEEK_CUR);
            line=(char*)malloc((i+1)*sizeof(char));
            
            fgets(line,i+1,fp);           
            ptr=strtok(line,","); //first token of each line

            if(master==NULL) //first entry of the dynamically created array
            {
                master=(char*)malloc((first_tok+1)*sizeof(char));
                for(j=0;j<first_tok+1-1;++j)master[j]=ptr[j];
                master[first_tok+1-1]='\0';
                map=(int*)malloc(line_number*sizeof(int));
                map[line_number-1]=0;
                
            }
            else
            {
                k=strlen(master); //rest of entries of the dynamically created array
                master=(char*)realloc(master,(k+first_tok+1)*sizeof(char));
                for(j=k;j<k+first_tok+1-1;++j)master[j]=ptr[j-k];
                master[k+first_tok+1-1]='\0';
                map=(int*)realloc(map,line_number*sizeof(int));
                map[line_number-1]=k;
                
            }          
            
            for (j=1;j<=column_number;++j){
                ptr=strtok(NULL,",");
            }
            
            free(line);
            
            i=0;
            first_tok=0;
            column_number=0; //after the new line count the columns again
        }
        
    } //end of while for file reading

    
    fclose( fp );
        
    map=(int*)realloc(map,(line_number+1)*sizeof(int));
    map[line_number]=(int)strlen(master);
        
    bsearch_custom(test_key,line_number,master,map,max_first_tok);
    

    free(master);free(map);    
}


int main(int argc, char *argv[]) {
    
    const char *errmsg = "usage: bsearch --key test filename\n";
    
    if(argc!=4)
    {
        fprintf(stderr, errmsg);
        exit(EXIT_FAILURE);
    }
    
    if (strcmp(argv[1],"--key") != 0)
    {
        printf("Please enter the keyword --key and try again.\n");
        exit(EXIT_FAILURE);
    }
    
    read_file(argv[3],argv[2]);
    
    return EXIT_SUCCESS;
}
