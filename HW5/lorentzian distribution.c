#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define pi 3.14159265358979323846

int main()
{
	int sum, i, N = 100000;
	double u, x[N];
	
	srand(time(NULL));
	
	for (i = 0; i < N; i++)
	{
		u = rand()/(double)RAND_MAX;
		x[i] = tan(pi*(u - 0.5));
		if (fabs(x[i]) < 1) sum++;
	}
	
	printf("The fraction of x with |x| < 1 is %f\n", (double)sum/N);
}
