#include<math.h>
#include<stdio.h>

double f(double x)
{
       return exp(-pow(x,2)/2);
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
      double a, b, I1, I1h, I2, prev, EPS;
      int n;
      
      a = 0;
      b = 1;
      n = 2;
      EPS = 1/pow(10,12);
      I2 = 1000;
      prev = 100;
      
      while(fabs(I2-prev) > EPS) // keep doubling no.of intervals
      { 
           prev = I2;
           I1 = simpson(f, a, b, n);
           I1h = simpson(f, a, b, n/2);
           I2 = ((16*I1 - I1h)/15);
           n *= 2; 
                 
      }
       
      printf("\n%f", I2);
      getch();
}


