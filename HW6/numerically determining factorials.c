#include <stdio.h>
#include <math.h>
#define e 2.71828182845904523536028747135266249775724709369995

main()
{
	int N = 50000, i;
	double fact, sum = 0;
	
	for ( i = 1; i < N + 1; ++i)
	{
		sum += log(i);
		
	}
	
	printf("sum = %f\n", sum);
	printf("ans = %f^%f", e, sum);
}
