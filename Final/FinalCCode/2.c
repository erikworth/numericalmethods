#include<math.h>
#include<stdio.h>

double f(double x)
{
       return exp(-x*x + x*x*x);
}

double simpson(double f(double), double a, double b, int n)
{
       double I, h;
       int j, m;
       
       I = f(a) + f(b);
       h = (b - a)/n; 
       for (j = 1; j < n/2; j++)
       {
           I += 2.0*f(a + 2*j*h) + 4.0*f(a + 2*(j-1)*h);
       }
       I += 4.0*f(b-h);
       I *= h/3.0;
       printf ("%1.6e\t %12.10f %14.10f \n",(double)n, h, I); 
       return I;
}
main()
{
      int n = 2;
      double a = 0,
             b = 1, 
             prev = 100, 
             result = 1000,
             EPS = pow(10,-10);
      
      printf("n\t\t  h     \t   result\n");
      while(fabs(result-prev) > EPS) // keep doubling no.of intervals
      { 
                 prev = result; 
                 result = simpson(f, a, b, n); 
                 n *= 2; 
                 
      }
      printf("\nFinal answer: %14.10f", result);
}
