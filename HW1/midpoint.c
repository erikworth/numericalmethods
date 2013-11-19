#include<stdio.h>
#include<math.h>

main()
{
      double f4, fmp, error, x, h;
      x = 1;
      h = 0.01;
      f4 = 120*x;
      fmp = (pow(x+h, 5) + pow(x-h, 5) - 2*pow(x,5))/pow(h,2);
      error = (pow(h,2)/12)*f4;
      
      printf("fmp = %.8f\terror = %.8f", fmp, error);
      getch();
}
