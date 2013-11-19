#include<math.h>
#include<stdio.h>
#include<conio.h>

double f(double x)
{
       return cos(x) + x/5;;
}

main()
{
      double a, b, c, tol, prev;
      
      printf("Enter a value for a:\n");
      scanf("%lf", &a);
      printf("Enter a value for b:\n");
      scanf("%lf", &b);
      printf("\na\t\t b\t\t c\t\t f(c)\n");
      
      c = (a + b)/2;
      prev = 100;
      tol = 0.0001;
      
      printf("%f \t %f \t %f \t %f \t\n", a, b, c, f(c));
      
      while ( fabs(c - prev) > tol)
     {
            
            prev = c;
            if (f(c)*f(a) < 0)
            {
                     b = c;
            }
            else
            {
                a = c;
            }
            c = (a + b)/2;
            printf("%f \t %f \t %f \t %f \t\n", a, b, c, f(c));
            
            
      }
}
