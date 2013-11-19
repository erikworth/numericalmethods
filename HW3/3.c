#include<stdio.h>
#include<math.h>

double f(double x)
{
	return tanh(2*x);
}

main()
{
	int i,
		max = 40;
	double x[max],
		   tol = pow(10,-12);
		   
	printf("Enter a value for X0:");
	scanf("%lf", &x[0]);
	printf("Enter a value for X1:");
	scanf("%lf", &x[1]);


	printf("\nXn\t\t\tf(Xn)\t\t\tn\n");
	
	for (i=2;i < max; i++)
	{
		x[i] = x[i-1] - f(x[i-1])*(x[i-1]-x[i-2])/(f(x[i-1]) - f(x[i-2]));
		printf("%.12f\t\t%.12f\t\t%d\n", x[i], f(x[i]),i);
		if (fabs(x[i]-x[i-1]) < tol) break;
		
	}
	
}
