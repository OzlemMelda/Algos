//#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <iomanip> 
#include <math.h>
using namespace std;

double fnc(double &F, double &x)
{
	F = x*x*x*cos(x)*sin(x) + 3 * x*x*sin(x) - 3 * x; //calculates the value of the function
	return F;
}


int main()
{
	double precision = 0.00001,  a =-10, b =-7 , c, e,intlength1,intlength2,temp1,temp2; // We chose a and b points by looking at the graph and checking where the function is unimodal and also includes a local minimum point
	double F;
	
	int k = 1;

	cout << "Iteration" << '\t' << "a" << '\t' << "   b  " << '\t' << "    x  " << '\t' << "    f(x)" << '\t' << "   |x(k+1)-x(k)|/|x(k)-x(k-1)|" << '\t' <<"-log|x(k+1) - x(k)| + log|x(k) - x(k-1)|"<< endl;
	cout << "__________________________________________________________________________________________________" << endl;
	
	while (fabs(a - b)> precision) 
	{
		
		c = (a+b)/2.0;
		intlength1=fabs(a-b);
		fnc(F,c);
		e = c+precision;
		temp1=a;
		temp2=b;
		if(fnc(F,e)<=fnc(F,c)){
			a=c;
		}else{
			b=c;
		}
		intlength2=fabs(a-b);
		cout << fixed;
		cout << setprecision(5);
		cout << "   " << k << "         " << temp1 << "     " << temp2 << "       " << c << "         " << F << "               " << intlength2/intlength1 << "               "<< -log10(intlength2/intlength1)<<endl; //we calculated the ratio of the two successive interval lengths to see the convergence ratio
		
		
		
		k++;
	}
	cout << "__________________________________________________________________________________________________" << endl;
	cout << endl << "                                      x* = " << c << endl;
	fnc(F, c);
	cout << "                                   F(x*) = " << F << endl;

	return 0;
}
