#include<stdio.h>
#include<math.h>

double f(double x)
{
       return pow(x,3) - 5*x + 3;
}

double f1(double x)
{
	return 3*pow(x,2) - 5;
}

main()
{
	double Xn, X0,
		   tol = pow(10,-12),
		   prev = 100;
		   
	int N = 0;
	
	printf("Enter a value for X0:\n");
	scanf("%lf", &X0);
	printf("X0 = %f\n\n", X0);
	printf("Xn \t\tf(Xn)\n");
	
	Xn = X0 - f(X0)/f1(X0);
		   
	while(fabs(Xn - prev) > tol )
	{
		prev = Xn;
		Xn = Xn - f(Xn)/f1(Xn);
		printf("%.12f\t%.12f\n",Xn, f(Xn));
	}
	
}
