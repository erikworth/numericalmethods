#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int step, t, tmax, x, i, N = 400;
	double xrand, xave[N], x2ave[N];
	double rxave, rx2ave, sum, sum2;
	
	tmax = 100;
	
	srand(time(NULL));
	
	
	for (i = 0; i < N; i++)
	{
		x = 0;
		for (t = 1; t < tmax + 1; t++)
		{
			xrand = (double)rand()/RAND_MAX;
			if (xrand < 0.5) step = -1;
			else step = 1;
	
			x += step;
			printf("%d\t%d\t%d\n", t, x, x*x);
		}
		
		xave[i] = (double) x/tmax;
		x2ave[i] = (double) x*x/tmax;
		
	}
	
	sum = 0, sum2 = 0;
	
	for (i = 0; i < N; i++)
	{
		sum += xave[i];
		sum2 += x2ave[i];
		if ( i == 0)
		{
			rxave = sum;
			rx2ave = sum2;
		}
		else
		{
			rxave = sum/(double)i;
			rx2ave = sum2/(double)i;
		}
		//printf("%f\t%f\n", rxave, rx2ave);
	}
}