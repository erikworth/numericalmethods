#include<stdio.h>
#include<math.h>

main()
{
	FILE *ifp;
	char *mode = "r";
	int n = 200;
	double y[n], err[n];
	int i, x[n];
	
	double A, a, B, b, D, sigmaa, sigmab,
		   sumx, sumy, sumxy, sumxx, chi2, nu;
			

	ifp = fopen("D:/users/erik/documents/115/hw4/data.txt", mode);

	if (ifp == NULL) 
	{
  		fprintf(stderr, "Can't open input file in.list!\n");
  		exit(1);
	}
	
	sumx = 0, sumy = 0, sumxy = 0, sumxx = 0;
	
	for (i = 0; i < n; i++)
	{
		fscanf(ifp, "%d %lf %lf\n", &x[i], &y[i], &err[i]);
		printf("%d %f %f\n", x[i], y[i], err[i]);
		sumx += x[i];
    	sumy += y[i];
    	sumxy += x[i]*y[i];
    	sumxx += x[i]*x[i];
    	A += x[i]/(err[i]*err[i]);
    	B +=  1/(err[i]*err[i]);
    	D +=  x[i]*x[i]/(err[i]*err[i]);
	}
	fclose(ifp);
	printf("%f %f %f %f\n", sumx, sumy, sumxy, sumxx);
	
	a = ( sumx*sumy - n*sumxy ) / ( sumx*sumx - n*sumxx );
    b = ( sumy - a*sumx ) / n;
	
	sigmaa = sqrt(B/(B*D - A*A));
	sigmab = sqrt(D/(B*D - A*A));
	
	printf("\n");
  	printf("y = %fx + %f\n", a, b);
  	printf("error in a: %f\n", sigmaa);
  	printf("error in b: %f\n", sigmab);
  	
  	chi2 = 0; nu = n-1;
  	for (i = 0; i < n; i++)
  	{
  		chi2 += pow((y[i] - a*x[i] + b)/2,2);
  	}
  	printf("chi squared = %f\n", chi2);
  	printf("chi squared per degree of freedom: %f\n", chi2/nu);


		
}
