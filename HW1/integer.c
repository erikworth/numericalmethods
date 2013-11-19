#include<stdio.h>

main()
{
      int i,n;
      i = 0;
      
      printf("i\t\tn\n");
      for (n = 1; n < 33; n++)
      {
          i = 2*i + 1;
          printf("%d\t\t%d\n", i, n);
      }
}
