#include<stdio.h>
#include<math.h>
#define pi 3.14159265358979323846


void rk2 (double t, double x[], void derivs(double, double[], double[]),
double h, int M) 
{
	double k1[M], k2[M], xp[M];
	int i;
 	derivs(t, x, k1); 
	for (i=0; i < M; i++) xp[i] = x[i] + h * k1[i]; 
 	derivs(t+h, xp, k2); 
	for (i=0; i < M; i++) x[i] += 0.5 * h * (k1[i] + k2[i]); 
}


void derivs(double t, double x[], double dxdt[])
{
 	dxdt[0] = 1 + x[0]*x[0];
}

main()
{
	int M = 1; 
	double t, x[M], h, tn, t0, exact; 
	void derivs(); 
	int n, i;
 	
	t0 = 0; tn = pi/4; 


 	exact = tan(tn);
 	printf ("h        Yapprox             Error\n");
	for (n=5; n < 1000; n=n*2)
	{
		h = (tn - t0) / n;
	
		x[0] = 0; 
		t = 0;
		for (i = 0; i < n; i++)
 		{
			rk2(t, x, derivs, h, M); 
			t += h; 
 		}
 		printf ("%0.6f %10.16f %10.16f\n", h, x[0], exact-x[0]);
 	}
}
