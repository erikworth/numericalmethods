#include<stdio.h>
#include<math.h>

main()
{
      int p,n,a,b;
      float supf, sdf;
      
      for (p = 2; p < 8; p++)
      {
          n = pow(10,p);
          
          for (a = 0; a < n + 1; a++)
          {
              supf += a;
          }
          
          for (b = n; b > 1; b--)
          {
              sdf += b;
          }
          
          printf("Sup = %.16e\tSdown = %.16e\t p = %d\n", supf, sdf, p);
      }
}
