#include<stdio.h>
#include<math.h>

main()
{
      int p,n,a,b;
      double supd, sdd;
      
      for (p = 2; p < 8; p++)
      {
          n = pow(10,p);
          
          for (a = 0; a < n + 1; a++)
          {
              supd += a;
              }
          
          for (b = n; b > 1; b--)
          {
              sdd += b;
          }
          
          printf("Sup = %.16e\tSdown = %.16e\t p = %d\n", supd, sdd, p);
          printf("Relative difference = %.2e\n", (supd - sdd)/supd);
          }
      }
