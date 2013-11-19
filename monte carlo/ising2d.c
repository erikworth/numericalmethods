#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define LX 8	
#define LY 8
#define J 1
#define t_equil 500
#define sweeps 5000
#define deltat 20

void metro(double *m, double *T);
void initialize();
double randf();

int spin[LX][LY];	/*lattice of spins*/
double m;	/*magnetization*/

main()
{
 	int h,i,j,x,n;
 	double m_sum,m2_sum,m_ave,m2_ave;
 	double T, sigma2;
 	FILE *fout;
 	fout = fopen("8x8.txt","w");
 	srand(time(NULL)); 	/*seed RNG*/

	fprintf(fout,"T \t m^2 \t\t  m \t\t  sigma \n");
 	for (x = 1; x <= 100; x += 1)
 	{
  		T = 0.2+x/20.0;
  		m_sum = 0;
  		m2_sum = 0;
  		n = 0;
  		initialize();		/* Initialize lattice */
  		
  		for (i = 0; i < t_equil; i++)		
  		{
   			metro(&m, &T);		/* run simulation until equilibrium*/
  		}
  		
  		for (j = 0; j < sweeps/deltat; j++) /* run simulation sweeps/delta times*/
  		{
   			for (h = 1; h <= deltat; h++) /* run simulation for t = deltat*/
   			{
   	 			metro(&m, &T);
   			}
   			n++;
   			m_sum += m; /*add up magnetization and m^2 */
  	 		m2_sum += m*m;
  		}
  		
 		m_ave = m_sum / (double)(sweeps/deltat); /*average m and m^2 */
  		m2_ave = m2_sum / (double)(sweeps/deltat);
  
		sigma2 = (m2_ave-m_ave*m_ave)/(double)(n-1); /* compute sigma^2 */
  
 	 	fprintf(fout,"%f, %.6e, %.6e,  %.6e\n",T, m2_ave,m_ave, sqrt(sigma2));
	}
 	fclose (fout);
}
 
double randf()				/*produces random numbers between 0 and 1 */
{
	return( (double)(rand())/(double)(RAND_MAX+1.0));
}


void initialize()
{
 	int x,y,xp,yp,number_up;
 
 /*initialize the lattice with random spins*/
 	for (x = 0; x< LX; x++)
 	{
  		for (y = 0; y < LY; y++)
  		{
   			if (randf() < 0.5) 
				spin[x][y] = 1;
   			else spin[x][y] = -1;
  		}
 	}
 
 	number_up = 0;
 	for (x = 0; x < LX; x++)
 	{
  		for (y = 0; y < LY; y++)
  		{
   			if (spin[x][y] == 1)  /* count number of up spins*/
			   number_up++;
  		}
 	}

 

 	m = -1+(2.0*number_up/(LX*LY)); /*compute initial m*/
}


void metro(double *m, double *T) /*Metropolitan algorithm*/
{
 	int i, x, y, xdown, xup, ydown, yup, sum;
 	double deltaE;
 
 	for (i = 0; i < LX*LY; i++)
 	{
  		x = randf()*LX;	/* Choose a random coordinate in the lattice */
  		y = randf()*LY;
  
  		xup = (x + 1)%LX;		/*determine neighbor sites, with periodic BCs */
  		xdown = (x + LX - 1)%LX;
  		yup = (y + 1)%LY;
  		ydown = (y + LY - 1)%LY;
 
  /*compute the sum of the spins of sites neighboring coordinate*/
  		sum = spin[xdown][y] + spin[xup][y] + spin[x][yup] + spin[x][ydown];
  
  /*compute change in energy if spin is flipped at coordinate*/
  		deltaE = 2.0*J*spin[x][y]*sum/(*T);
  		if (randf() < exp(-deltaE)) /* decide if flip is accepted*/
  		{
   			*m -= 2.0*spin[x][y]/(LX*LY); /*flip spin and compute m*/
   			spin[x][y] *= -1;
  		}
 	}
}
