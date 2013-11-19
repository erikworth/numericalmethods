#include<stdio.h>
#include<math.h>

double f(double x)
{
       return x - sqrt(2);
}

double f1(double x)
{
	return 1;
}

main()
{
	double Xn, X0,
		   tol = pow(10,-14),
		   prev = 100;
		   
	int N = 0;
	
	printf("Enter a value for X0:\n");
	scanf("%lf", &X0);
	printf("X0 = %f\n\n", X0);
	printf("Xn \t\t\tf(Xn)\n");
	
	Xn = X0 - f(X0)/f1(X0);
		   
	while(fabs(Xn - prev) > tol )
	{
		prev = Xn;
		Xn = Xn - f(Xn)/f1(Xn);
		printf("%.14f\t%.14f\n",Xn, f(Xn));
	}
	
}
