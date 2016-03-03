#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#define MAX_ITERS 100000000
double Rand(double L, double R)  
{  
    return L + (R - L) * rand() * 1.0 / RAND_MAX;  
}  
int main()
{
   long long i,count=0;
   double x,y,pi,start_time,end_time;
	omp_set_num_threads(16);
   time_t t;
   srand((unsigned) time(&t));
	start_time=omp_get_wtime();
   #pragma omp parallel for private(x,y) reduction(+:count)
   for(i=0;i<MAX_ITERS;i++)
   {
    x = Rand(-1, 1);  
	y = Rand(-1, 1);  
	
      if((x*x+y*y)<=1)
         count++;
   } 
   pi = count*4.0/MAX_ITERS;
   end_time=omp_get_wtime();
   printf("Pi:%0.8f\n",pi);
   printf("time%0.8f s\n",(end_time-start_time));
   return 0;
}
