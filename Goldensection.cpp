//#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <iomanip> 

using namespace std;

double fnc(double &F, double &x)
{
	F = x*x*x*cos(x)*sin(x) + 3 * x*x*sin(x) - 3 * x;
	return F;
}


int main()
{
	double precision = 0.0001,  a =2, b =7, oneovergama=0.618,x,y, fx,fy,intlength1,intlength2; // We chose a and b points by looking at the graph and checking where the function is unimodal and also includes a local minimum point
	double F;
	
	int k = 0;

	cout << "Iteration" << '\t' << "a" << '\t' << "   b  " << '\t' << "       x   " << '\t' << "    y   " << "   f(x)   " << '\t' << "    f(y)  " << '\t' <<  "   |x(k+1)-x(k)|/|x(k)-x(k-1)|" << '\t' <<"-log|x(k+1) - x(k)| + log|x(k) - x(k-1)|"<< endl;
	cout << "__________________________________________________________________________________________________" << endl;
	

	cout << fixed;
	cout << setprecision(5);
	
	x=b-oneovergama*fabs(b-a);
	y=a+oneovergama*fabs(b-a);
	fx=fnc(F,x);
	fy=fnc(F,y);
cout << "   " << k << "         " << a << "     " << b << "       " << x << "         " << y << "               " << fnc(F,x) << "       " << fnc(F,y) <<"       " << "   N/A"<< "               "<< "    N/A"<<endl;
k++;
	while (fabs(a - b)> precision) 
	{
		intlength1=fabs(a-b);
		if(fx>fy){
			a=x;
			x=y;
			fx=fy;
			y=a+oneovergama*fabs(b-a);
			fy=fnc(F,y);
		}else{
			b=y;
			y=x;
			fy=fx;
			x=b-oneovergama*fabs(b-a);
			fx=fnc(F,x);
		}
		intlength2=fabs(b-a);
		cout << fixed;
		cout << setprecision(5);
		cout << "   " << k << "         " << a << "     " << b << "       " << x << "         " << y << "               " << fnc(F,x) << "       " << fnc(F,y) <<"       " << intlength2/intlength1<< "               "<< -log10(intlength2/intlength1)<<endl;// We chose a and b points by looking at the graph and checking where the function is unimodal and also includes a local minimum point
		k++;
	}
	cout << "__________________________________________________________________________________________________" << endl;
	cout << endl << "                                      x* = " << min(x,y) << endl;
	
	cout << "                                   F(x*) = " << min(fx,fy) << endl;

	return 0;
}
