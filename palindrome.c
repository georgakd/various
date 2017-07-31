/*
 * palindrome.c: This program finds the palindrome of a word
 * 
 * Copyright 2016 Dimitra Georgakaki
 * 
 */



#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
		
	int T;  char temp;
    scanf("%d",&T);
    
    if (T<1 || T>10000) {
		
		printf("Abort program...wrong input of number of testcases");
		exit(1);		
	}
    
    for (int i=0;i<T;i++){
	 
	 int c=0;	
     char* s = (char *)malloc(10240 * sizeof(char));
     char* image = (char *)malloc(10240 * sizeof(char));
     scanf("%s",s);
     
      
      if (strlen(s)<2 || strlen(s)>8 ) {
		
		printf("Abort program...wrong input of string length");
		exit(1);		
		}
		
   while (s[c] != '\0')
   {
      int j; 
      if (s[c] >= 'a' && s[c] <= 'z') {
		for (c=0;c<strlen(s);c++){
			
			if (s[c]==s[strlen(s)-1-c])

                printf("%d\t %c\t %c\n",c,s[c],s[strlen(s)-1-c]); 
			
			}
		  
		  }

      c++;
      
      
   }
     free(s);free(image); 
} 
    return 0;
}
