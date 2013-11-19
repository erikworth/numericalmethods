#include<stdio.h>
#include<math.h>

main()
{
      double phi, phin;
      int i;
      
      phi = (sqrt((double)5) - 1)/2;
      phin = 1;
      
      for (i = 0; i < 51; i++)
      {
          phin *= phi;
          printf("n = %d\tphin = %e\n", i, phin);
      }
      
}
