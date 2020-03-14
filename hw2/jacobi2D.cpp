
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream> 
#define _BSD_SOURCE

#include <sys/time.h>

using namespace std; 


void jacobi(double **u, double ** u_new, int N, double h, double h_sq)
{
    printf("Jacobi Method:\n");

    int iter = 1; 
    int tid;
    for(int iter=1 ; iter<=1000; iter++){
        {
        for(int i = 1; i < N-1 ; i++)
            for(int j=1 ; j < N-1 ; j++)
                u_new[i][j] = 0.25 * ((h_sq)+ u[i-1][j] + u[i][j-1] + u[i+1][j] + u[i][j+1]); 

       }
        for(int i = 1; i < N-1 ; i++)
            for(int j=1 ; j < N-1 ; j++)
                u[i][j] = u_new[i][j];
    }    
}

int main(int argc, char **argv)
{
    int N; 
    double h, h_sq; 
    N = 1000; 
    if(argc == 2)
    N = atoi(argv[1]); 
    h = (double)1/(double)(N+1); 
    h_sq = h*h; 


    double **u = (double**) malloc(N*sizeof(double*)); 
    for(int i = 0 ; i < N ; i++)
        u[i] = (double*)calloc(N ,sizeof(double)); 
    
    double **u_new = (double**) malloc(N*sizeof(double*)); 
    for(int i = 0 ; i < N ; i++)
        u_new[i] = (double*)calloc(N ,sizeof(double)); 

    struct timeval start, end;
    gettimeofday(&start, NULL);  
    jacobi(u, u_new, N, h ,  h_sq);  
    gettimeofday(&end, NULL);
 

    double time_taken = ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6;
   
     printf("\n The program took %f seconds to execute\n", time_taken);

    for(int i = 0 ; i < N ; i++)
        free(u[i]); 
    for(int i = 0 ; i < N ; i++)
        free(u_new[i]); 
    free(u); 
    free(u_new); 
    return 0; 
}



	
	
	
	

