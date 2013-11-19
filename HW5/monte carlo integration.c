#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>


double f(double x) // define function to be integrated
{
	return log(x);
}

main()
{
	double x, a, b, fav, f2av, err, exact, nsigma;
	int i, N = 10000;
	
 	exact = log(4) - 1;
 	b = 10034; // set upper limit
 	a = 1.0; // set lower limit
 	srand(time(NULL)); // initialize RNG
 	printf (" \tx \t  f(x)   f^2(x)\n");
 	fav = 0; f2av = 0;
 	
	for (i = 0; i < N; i++)
 	{
		x = a + (b - a) * rand() / RAND_MAX; //random value for x
		fav += f(x); // compute f(x)
		f2av += f(x)*f(x); // compute f(x)^2
		printf ("%10.5f %10.5f %10.5f \n", x, f(x), f(x)*f(x));
 	}
 	
 	fav /= N; // sample average of f
 	f2av /= N; // sample average of f^2
 	printf ("\n averages %10.5f %10.5f \n", fav, f2av);
 	err = sqrt((f2av - fav*fav) / (N - 1)); // error bar
 	printf ("\n answer = %10.5f \n", (b - a) * fav);
 	printf (" error bar = %10.5f \n", (b - a) * err);
 	nsigma = (fav - exact) / err; // no of st.devs. from exact
 	printf ("\n answer is %10.3f sigma away from exact value \n", nsigma);
}
