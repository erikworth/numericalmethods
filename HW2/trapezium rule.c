#include <math.h>
#include <stdio.h>

double f(double x)
{
       return 1/(1+x);
}

double trap (double f(double), double a, double b, int n)
{
       double h, sum;
       int i;
       h = (b - a) / n; // set stepsize
       sum = 0.5 * (f(a) + f(b)); // end points with factor 1/2
       for (i = 1; i < n; i++)
       { 
           sum += f(a + i * h);
       }       
       return h * sum; // return answer
}
main()
{
      double x, a, b, h, exact, ans, trap();
      int i, n, iter, max;
      exact = log((double) 2); // exact answer
      max = 12; // set no. of iterations
      b = 1.0; // set upper limit
      a = 0; // set lower limit
      printf ("     h            ans          (exact-ans)/h^2 \n");
      n = 1;
      for (iter = 0; iter < max; iter++) // keep doubling no. of intervals
          {
                h = (b - a)/n;
                ans = trap(f, a, b, n);
                n *= 2; // double n for next iteration
                printf ("%12.5f %12.5f %12.5f \n", h, ans, (ans - exact)/(h*h));
          }
          getch();
}
