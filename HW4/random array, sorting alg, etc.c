#include <math.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


main()
{
	double swap, tol, prev, x0, x1;
	int i, a, b, c, n = 20000;
	double rlist[n];
	
	clock_t begin, end;
	double time_spent;
	
	srand(time(NULL));				//seed RNG
	
	for (i = 0; i < n; i++)			//create random array
	{
		rlist[i] = rand()/(double)RAND_MAX;
	}
	
	begin = clock();		 // begin timer
	
	for (a = 0; a < ( n - 1 ); a++)		//bubble sort
    {
    	for (b = 0; b < n - a - 1; b++)
    	{
        	if (rlist[b] > rlist[b+1]) 
        	{
       	 		swap       = rlist[b];
        		rlist[b]   = rlist[b+1];
        		rlist[b+1] = swap;
        	}
    	}
  	}
  	
  	end = clock();			//end timer
  	time_spent = (double)(end - begin) / CLOCKS_PER_SEC; //calculate time spent
  	printf("time spent: %f\n\n", time_spent);
  	
  	for (i = 0; i < n; i++) 		//print first and last 5 elements
	{
		if (i < 5 || i > n - 6)
		{
			printf("%f\n", rlist[i]);
		}
	}
	
	x0 = 0.5*n, x1 = 0.8*n;
	c = (x0 + x1)/2;
	prev = 0;
	tol = 0.0001;
	
	printf("\nx0 \t x1 \t c \t cth element\n");
	
	while ( fabs(c - prev) > tol) 			//bisection method
    {
            
            prev = c;
            if (rlist[c] < 0.7)
            {
                     x0 = c;
            }
            else
            {
                x1 = c;
            }
            c = (x0 + x1)/2;
            printf("%.0f \t %.0f \t %d \t %f \t\n", x0, x1, c, rlist[c]);
            
            
    }
  	
}
