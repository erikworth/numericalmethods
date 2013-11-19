#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>


double f(double x[])
{
	double a;
	
	a = x[0] + x[1] + x[2]+ x[3] + x[4] + x[5] + x[6] + x[7] + x[8] + x[9];
	return pow(a, 2);
}

main()
{
	double x[10], a, b, fav, f2av, err, exact, nsigma;
	int i, j, NPOINT;
	printf ("\n NPOINT = "); 
 	scanf ("%d", &NPOINT); 
 	exact = 155.0/6;
 	b = 1; // set upper limit
 	a = 0; // set lower limit
 	srand(time(NULL)); // initialize RNG
 	fav = 0; f2av = 0;
 	
	for (i = 0; i < NPOINT; i++)
 	{
 		for (j = 0; j < 10; j++)
 		 {
		 	x[j] = a + (b - a) * rand() / RAND_MAX; //random values for xis
		 }
	
		 
		 fav += f(x); // compute f(x)
		 f2av += f(x)*f(x); // compute f(x)^2
 	}
 	
 	fav /= NPOINT; // sample average of f
 	f2av /= NPOINT; // sample average of f^2
 	err = sqrt((f2av - fav*fav) / (NPOINT - 1)); // error bar
 	printf ("\n answer = %10.5f \n", (b - a) * fav);
 	printf (" error bar = %10.5f \n", (b - a) * err);
 	nsigma = (fav - exact) / err; // no of st.devs. from exact
 	printf ("\n answer is %10.3f sigma away from exact value \n", nsigma);
}
