#include<stdio.h>
#include<math.h>

main()
{
      int i;
      float a,c;
      double b,d;

      for (i = 0; i < 100; i++)
      {
          a = pow(0.5,i);
          b = pow(0.5,i);
          c = 1 - a;
          d = 1 - b;
          printf("a = %.16e\tb = %.16e\tn = %d\n", a,b,i);
          printf("c = %.16e\td = %.16e\n", c,d);
      }
}
