#include <stdio.h>
#include <math.h>


double deriv(double x)		/* determine F(x) */
{
    return -x*x*x;
}

void advance_vel(double x, double *v, double h2)
{
    *v += h2*deriv(x);	
				           
}

double energy(double x, double v)	
{
    return 0.5*v*v + 0.25*pow(x,4);
}

static double e0;

void output(double x, double v, double t, double h)
{
    if (t > 0) 
		advance_vel(x, &v, -0.5*h);

    printf("%f %f %f %f\n", t, x, v, fabs(energy(x, v) - e0));
}

void leapfrog(double *x, double *v, double *t, double h)
{
    *x += h * (*v);
    *v += h * deriv(*x);
    *t += h;
}
	

main()
{
    /* initial conditions: */

    double t = 0, x = 0.1, v = 0, T = 74;
    double t_max = T, h = 0.02*T;
    double maxdev = 0;
    

	printf("t        x        v         Energy - E0\n");
    e0 = energy(x, v);  /* exact energy */
    output(x, v, t, h);
    advance_vel(x, &v, 0.5*h);
    

    while (t < t_max) 
	{
		
		leapfrog(&x, &v, &t, h);
		output(x, v, t, h);
		if(fabs(e0-energy(x,v))>maxdev)
		{
			maxdev = fabs(e0-energy(x,v));
		}
		
		
		

	}
	printf("t_max = %f\n", t_max);
    printf("maxdev = %e", maxdev);
    
}
