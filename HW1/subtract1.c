#include<stdio.h>
#include<math.h>

main()
{
      float phi[50];
      double gm,phid[50],phim[50];
      int i;
      
      gm = (sqrt((double)5) - 1)/2;
      phi[0] = 1;
      phid[0] = 1;
      phi[1] = gm;
      phid[1] = gm;
      for (i = 2; i < 51; i++)
      {
          phi[i] = phi[i-2] - phi[i-1];
          phid[i] = phid[i-2] - phid[i-1];
          printf("n = %d\t phi = %e\t phid = %e\n", i, phi[i], phid[i]);
      }

}
