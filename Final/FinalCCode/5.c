#include <math.h>
#include <stdio.h>

void rk4 (double t, double x[], void derivs(double, double[], double[]),
double h, int M)
{
	double k1[M], k2[M], k3[M], k4[M], xp[M], h6;
	int i;
	h6 = h / 6;
	derivs(t, x, k1); //compute k1[i] (= derivs at (t, x))
	for (i=0; i < M; i++) xp[i] = x[i] + 0.5 * h * k1[i];
	derivs(t+0.5*h, xp, k2); //compute k2[i] (= derivs at (t+0.5*h, x+0.5*h*k1))
	for (i=0; i < M; i++) xp[i] = x[i] + 0.5 * h * k2[i];
	derivs(t+0.5*h, xp, k3); //compute k3[i] (= derivs at (t+0.5*h, x+0.5*h*k2))
	for (i=0; i < M; i++) xp[i] = x[i] + h * k3[i];
	derivs(t+h, xp, k4); //compute k4[i] (= derivs at (t+h, x+h*k3))
	for (i=0; i < M; i++) x[i] += h6*(k1[i] + 2*k2[i] + 2*k3[i] + k4[i]);
}


void derivs(double t, double x[], double dxdt[])
{
dxdt[0] = sin(x[0] - x[1]);
dxdt[1] = -2*x[1] + x[0]*x[0];
}

main()
{
int M = 2;
double x[M], t, h, xold;
extern void derivs();
h = 0.005;


x[0] = 1; x[1] = 1; t = 0; // initial conditions

while (t < 2 - h)
{
	xold = x[0];
	rk4(t, x, derivs, h, M); // Call RK4
	t = t + h;
}

printf("x1 = %f\tx2 = %f", x[0], x[1]);

}
