#include<math.h>
#include<stdio.h>
    
double f(double x)
{
       return exp(-x)*sin(x);
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
       printf ("%12.10f %14.7f \n", h, I); 
       return I;
}

  
main()
{
      int n = 2;
      double a = 0,
             b = 2, 
             prev = 100, 
             result = 1000,
             EPS = 0.00000001;
      
      printf("h                 result\n");
      while(fabs(result-prev) > EPS) // keep doubling no.of intervals
      { 
                 prev = result; 
                 result = simpson(f, a, b, n); 
                 n *= 2; 
                 
      }
      getch();
}



