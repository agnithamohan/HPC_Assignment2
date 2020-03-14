/* 
Solution:
There's a local variable sum which is used as the reduction variable. This has the be initialised to 0. The parallel section is 
moved from the main function to inside the dotprod function. Without this thread 0 was handling all computations. Tid is made 
private and a and b are shared. The sum calculated within the function is returned to the main functions sum variable. 

*/
/******************************************************************************
* FILE: omp_bug6.c
* DESCRIPTION:
*   This program compiles and runs fine, but produces the wrong result.
*   Compare to omp_orphan.c.
* AUTHOR: Blaise Barney  6/05
* LAST REVISED: 06/30/05
******************************************************************************/
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define VECLEN 100

float a[VECLEN], b[VECLEN];

float dotprod ()
{
int i,tid;
float sum = 0.0;
#pragma omp parallel private(tid) shared(a,b) 
{
tid = omp_get_thread_num();
#pragma omp for reduction(+:sum) 
  for (i=0; i < VECLEN; i++)
    {
    sum = sum + (a[i]*b[i]);
    printf("  tid= %d i=%d\n",tid,i);
    }
}
return sum; 
}


int main (int argc, char *argv[]) {
int i;
float sum;

for (i=0; i < VECLEN; i++)
  a[i] = b[i] = 1.0 * i;
sum = 0.0;


sum =  dotprod();

printf("Sum = %f\n",sum);

}

