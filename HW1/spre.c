#include<stdio.h>
#include<math.h>

main()
{
      int p,n,a,b;
      float supf, sdf;
      double supd, sdd;
      
      for (p = 2; p < 8; p++)
      {
          n = pow(10,p);
          
          for (a = 0; a < n + 1; a++)
          {
              supd += a;
              supf += a;
          }
          
          for (b = n; b > 1; b--)
          {
              sdd += b;
              sdf += b;
          }
          
          printf("Sup relative difference = %.2e\n", (supd - supf)/supd);
          printf("Sdown relative difference = %.2e\n\n", (sdd - sdf)/sdd);
      }
}
