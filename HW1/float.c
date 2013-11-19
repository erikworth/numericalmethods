#include<stdio.h>

main()
{
      int i;
      float a;
      double b;

      for (i = 0; i < 1100; i++)
      {
          a = pow(2,i);
          b = pow(2,i);
          printf("a = %.16e\tb = %.16e\tn = %d\n", a,b,i);
          }
}
