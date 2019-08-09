#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;


typedef struct { // x and y coordinates of points (x or gra)
	double x;
	double y;
} point;

point gradient(point arrx) { // gradient vector arrx
	

	point gra;
	gra.x = 2 * arrx.y - 2 * arrx.x;
	gra.y = 2 * arrx.x + 2 - 4 * arrx.y;
	
	return gra;
}

double calculate_t(point arrx, point gra) { // find specific value of t at each iteration. t is found by taking first derivative of objective function and equating it to zero. Then, t is setted to one side of the equation and other variables are setted to other side.
	
	double t;
	double a = arrx.x;
	double b = arrx.y;
	double c = gra.x;
	double d = gra.y;
	
	t = (4*b*d+2*a*c-2*a*d-2*c*b-2*d) / (2*(2*c*d-c*c-2*d*d));
	return t;
}

point update_arrx(point arrx, point gra, double t) { // update point arrx
	
	arrx.x = arrx.x + t*gra.x;
	arrx.y = arrx.y + t*gra.y;
	return arrx;
}

double norm_gradient(point gra) { // l = length of gradient
	double l = sqrt(gra.x * gra.x + gra.y * gra.y);
	return l;
}

void main() {

	point x;
	x.x = 0; // initial point
	x.y = 0;

	point gra = gradient(x); 
	double length = 1000000000; // norm of gradient. Setted to big number to get it while loop.
	
	cout << "Initiliziation" << endl; // initial situation is reported
	cout << "x : (" << x.x << "," << x.y << ")" << endl;
	cout << "gradient : (" << gra.x << "," << gra.y << ")" << endl<<endl;

	int k = 1; // k is iteration number
	while (length>0.001) {  //epsilon = 0.001. 

		double t = calculate_t(x, gra); 
		x = update_arrx(x, gra, t);
		double f = 2 * x.x*x.y + 2 * x.y - x.x*x.x - 2 * x.y*x.y; // function f(x)
		gra = gradient(x);
		length = norm_gradient(gra);

		cout << "k : " << k << endl;  //We report information at each iteration
		cout << "x : (" << x.x << "," << x.y << ")" << endl;
		cout << "f(x) : " << f << endl;
		cout << "gradient : (" << gra.x << "," << gra.y << ")" << endl;
		cout << "norm gradient : " << length << endl;
		cout << "t : " << t << endl << endl;

		k++;
	}
	
	getchar();
}