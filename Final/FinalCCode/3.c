#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdio.h>

main()
{
	double r, xave, x2ave, err, err2;
	int i, N = 1000;
	double x[N];
	
	srand(time(NULL));
	
	for(i = 0; i < N; i++)
	{
		r = rand()/(double)(RAND_MAX + 1);
		x[i] = sqrt(-2*log(r));
		xave += x[i];
		x2ave += x[i]*x[i];
	}	
	xave /= N;
	x2ave /= N;
	err = sqrt((x2ave - xave*xave) / (N - 1));
	err2 = (N-1)*(x2ave - xave*xave)/N;
	printf("xave = %f +/- %f\nx2ave = %f +/- %f\n", xave, err, x2ave, err2);
}
	
