#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	
	int i, j, N = 10000, M = 100000;
	double x[N], X[M], X1, X2, X3, X4, X5, X6;
	
	srand(time(NULL));
	
	X1 = 0, X2 = 0, X3 = 0, X4 = 0, X5 = 0, X6 = 0;
	
	for (j = 0; j < M; j++)
	{
		for (i = 0; i < N; i++)
		{
			x[i] = rand()/(double)RAND_MAX;
			X[j] += x[i] - 0.5;
		}
	
	
		X[j] *= sqrt(12.0/N);
		X1 = X1 + X[j];
		X2 = X2 + X[j]*X[j];
		X3 = X3 + pow(X[j],3);
		X4 = X4 + pow(X[j],4);
		X5 = X5 + pow(X[j], 5);
		X6 = X6 + pow(X[j], 6);
	}
	
	
	X1 = X1/M;
	X2 = X2/M;
	X3 = X3/M;
	X4 = X4/M;
	X5 = X5/M;
	X6 = X6/M;
	printf("X1 = %f\n", X1);
	printf("X2 = %f\n", X2);
	printf("X3 = %f\n", X3);
	printf("X4 = %f\n", X4);
	printf("X5 = %f\n", X5);
	printf("X6 = %f\n", X6);

}
