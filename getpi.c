#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITERS 100000000  
double Rand(double L, double R)  
{  
    return L + (R - L) * rand() * 1.0 / RAND_MAX;  
}  
 int main()  
{   
	double start_time,end_time;
    srand(time(NULL)); 
    start_time = clock(); 
    int cnt = 0;
	  int i;
    for(i = 0; i < MAX_ITERS; i++)  
    {  
        double x = Rand(-1, 1);  
        double y = Rand(-1, 1);  
        if(x * x + y * y <= 1)  
            cnt++;  
    }  
	end_time =clock();
    printf("Pi:%f\n",cnt * 4.0 / MAX_ITERS);  
    printf("运算时间为%0.8f s\n",(end_time-start_time)/1000);
    return 0;  
}  
