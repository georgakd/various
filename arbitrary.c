/*
 * arbitrary.c
 * 
 * Copyright 2016 Dimitra Georgakaki <dgeorgakaki@192.168.2.3>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define C_MAX_LENGTH 1000

FILE *fp;

int main(int argc, char **argv)
{

//*********** Calc the length of the input array *********************//
    char buffer[C_MAX_LENGTH]; 
	int length;
	
	fp=fopen("data.dat", "r");
	if (fp == NULL) 
	{
         printf("I couldn't open .dat for reading.\n");
         return EXIT_FAILURE;
    }
    
    length = 0;
    if( fp != NULL ) 
    {
        while( fgets(buffer,C_MAX_LENGTH,fp ) != NULL ) {
            length++;            
        }
        rewind( fp );
    }    
        
//********** Read the file and store into a double array *************//
    double *x_array, *y_array;
    x_array = (double *)malloc(length * sizeof(double));
    y_array = (double *)malloc(length * sizeof(double));
    
    
    int i = 0;
    fp=fopen("data.dat", "r");
	if(fp != NULL) {
        while(!feof(fp)) {
			fgets(buffer,C_MAX_LENGTH,fp ); 
            sscanf(buffer, "%lf\t%lf", &x_array[i], &y_array[i]);
            i++;
        }
        for(int i = 0; i < length; i++) {
            printf("%.12lf\t%.12lf\n", x_array[i],y_array[i]);
        }
	}			        
    fclose( fp );
    
    
    
    free(x_array);
    free(y_array);   
    
    
//*************** Linear interpolation *******************************//

    int k,kfound;
    double x,y;
    double step = 0.001; 
    
    /*Give me a random x 
      Check at which interval this x lies:*/
      
    srand((unsigned)time(NULL));
    x = ((double)rand()/(double)RAND_MAX);
    
    for (k=0;k<length;k++)   
     {
		 if (x >= k*step && x <= (k+1)*step)
		     kfound = k+1;
		 }
   
    //**Calculate y**//
    
      y = y_array[kfound] + (y_array[kfound+1]-y_array[kfound])*((x-x_array[kfound])/(x_array[kfound+1]-x_array[kfound]));
      printf("%d %g %g\n", kfound, x, y);
    
	return 0;
}