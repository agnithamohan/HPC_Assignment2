#ifdef _OPENMP
#include <omp.h>
#endif 

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define _BSD_SOURCE
#include <sys/time.h>

void gaussSeidel(double **u, double ** u_r, double** u_b, int N, double h, double h_sq, int nT)
{
    printf("Gauss Seidel Method:\n");

    for(int iter = 0; iter <= 1000 ; iter++)
    {
        //Calculating red points 
        #ifdef _OPENMP
        #pragma omp  parallel for schedule(static,10)  num_threads(nT)
        #endif
        for(int i = 1; i< N-1 ; i++)
        {
            if(i%2!=0){
                for(int j = 1; j < N - 1 ; j+=2) 
                    u_r[i][j] = 0.25 * ( h_sq + u[i-1][j] + u[i][j-1] + u[i+1][j] + u[i][j+1]); 
            }
            else {
                for(int j = 2; j < N - 1 ; j+=2) 
                    u_r[i][j] = 0.25 * ( h_sq + u[i-1][j] + u[i][j-1] + u[i+1][j] + u[i][j+1]); 
            }
        }

        //Calculating black points 
        #ifdef _OPENMP
        #pragma omp  parallel for schedule(static,10)  num_threads(nT)
        #endif
        for(int i = 1; i< N-1 ; i++)
        {
            if(i%2==0){
                for(int j = 1; j < N - 1 ; j+=2) 
                    u_b[i][j] = 0.25 * ( h_sq + u_r[i-1][j] + u_r[i][j-1] + u_r[i+1][j] + u_r[i][j+1]); 
            }
            else {
                for(int j = 2; j < N - 1 ; j+=2) 
                    u_b[i][j] = 0.25 * ( h_sq + u_r[i-1][j] + u_r[i][j-1] + u_r[i+1][j] + u_r[i][j+1]); 
            }
        }

        #ifdef _OPENMP
        #pragma omp  parallel for schedule(static,10)  num_threads(nT)
        #endif
        for(int i =  1 ; i < N-1 ; i++)
            for (int j = 1 ; j < N-1 ; j++)
            {
                if(i%2 != 0 ) 
                {
                    if(j%2 != 0 )
                        u[i][j] = u_r[i][j]; 
                    else 
                        u[i][j] = u_b[i][j];

                }
                else 
                {
                    if(j%2 != 0 )
                        u[i][j] = u_b[i][j]; 
                    else 
                        u[i][j] = u_r[i][j];
                }
            }
    }
}


int main(int argc, char **argv)
{

     
    int N, nT; 
    N = 1000;
    nT=8;

    double h, h_sq; 
    if(argc==3)
    {N = atoi(argv[1]); 
    nT = atoi(argv[2]); }
    h = (double)1/(double)(N+1); 
    h_sq = h*h; 


    double **u = (double**) malloc(N*sizeof(double*)); 
    for(int i = 0 ; i < N ; i++)
        u[i] = (double*)calloc(N ,sizeof(double)); 
    
    double **u_r = (double**) malloc(N*sizeof(double*)); 
    for(int i = 0 ; i < N ; i++)
        u_r[i] = (double*)calloc(N ,sizeof(double)); 
    
    double **u_b = (double**) malloc(N*sizeof(double*)); 
    for(int i = 0 ; i < N ; i++)
        u_b[i] = (double*)calloc(N ,sizeof(double)); 
    
    
    struct timeval start, end;
    gettimeofday(&start, NULL);
    gaussSeidel(u, u_r, u_b, N, h ,  h_sq, nT);  
    gettimeofday(&end, NULL);
   

    double delta = ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6;
	printf("Method took %f seconds to execute \n", delta);

    
    

    for(int i = 0 ; i < N ; i++)
        free(u[i]); 
    for(int i = 0 ; i < N ; i++)
        free(u_b[i]); 
    for(int i = 0 ; i < N ; i++)
        free(u_r[i]); 
    
    
    free(u); 
    free(u_r); 
    free(u_b);
    return 0; 
}





