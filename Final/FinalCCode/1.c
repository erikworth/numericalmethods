#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>


double f(double x[])
{
	
	return 1/(1 + x[0]*x[0] + x[1]*x[1] + x[2]*x[2] + x[3]*x[3] + x[4]*x[4] 
			+ x[5]*x[5]);

}

main()
{
	double x[6], a, b, fav, f2av, err;
	int i, j, N = 1000;
 	b = 2.0; // set upper limit
 	a = 0.0; // set lower limit
 	srand(time(NULL)); // initialize RNG
 	fav = 0; f2av = 0;
 	
	for (i = 0; i < N; i++)
 	{
 		for (j = 0; j < 6; j++)
 		{
 			x[j] = a + (b - a) * rand() / (RAND_MAX + 1); //random values for xis
 		}
 		
 		fav += f(x);
 		f2av += f(x)*f(x);
 	}
 	
 	fav /= N; // sample average of f
 	f2av /= N; // sample average of f^2
 	err = sqrt((f2av - fav*fav) / (N - 1)); // error bar
 	printf ("\n answer = %10.5f \n",pow((b - a),6) * fav);
 	printf (" error bar = %10.5f \n", pow((b - a),6) * err);
}
