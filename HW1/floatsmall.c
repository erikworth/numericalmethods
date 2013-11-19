#include<stdio.h>
#include<math.h>

main()
{
      int i;
      float a;
      double b;

      for (i = 0; i < 1100; i++)
      {
          a = pow(0.5,i);
          b = pow(0.5,i);
          printf("a = %.16e\tb = %.16e\tn = %d\n", a,b,i);
          }
}
