// The Cyclic Coordinate Method
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define eps 0.001 
struct point{   //Each point has two coordinates since our objective function takes a point in 2D
	double coor1; 
	double coor2;
};
double objf(point A){  //Objective function takes a point and returns a value 
	double value = 2 * (A.coor1)* (A.coor2) + 2 * (A.coor2) - (A.coor1)*(A.coor1) - 2 * (A.coor2)*(A.coor2);
	return value;
};
double lambdafind1(point B) { //Finds the lambda1 value in x1 direction that maximizes the improvement in objective value, lambda1 real
	double lambda1;
	lambda1 = B.coor2 - B.coor1; //The first derivative of objf(Ycoor1.coor1+lambda,Ycoor1.coor2) at lambda1 is zero and 2nd derivative is -2, so it maximizes the improvement in objective value
	return lambda1;
};
double lambdafind2(point C) { //Similarly, looks for the lambda2 value that maximizes the improvement in objective value in x2 direction, again real however it uses lambdafind1 data in main
	double lambda2;
	lambda2 = (C.coor1 - 2 * C.coor2 + 1) / 2; //The first derivative of objf(Ycoor2.coor1,Ycoor2.coor2+lambda) at lambda2 is zero and 2nd derivative is -4, so it maximizes
	return lambda2;
};

int main()
{
	point Xcoor, Xcoortemp;
	point Ycoor1, Ycoor2;
	int k = 0;
	Xcoor.coor1 = 0;  //We start our investigation from origin
	Xcoor.coor2 = 0;
	do {
		Ycoor1.coor1 = Xcoor.coor1; //Ycoor1 is the starting point to find lambda values
		Ycoor1.coor2 = Xcoor.coor2;
		Ycoor2.coor1 = Ycoor1.coor1 + lambdafind1(Ycoor1); //Ycoor2 is updated version of Xcoor, so that it's improved  in x1 direction
		Ycoor2.coor2 = Ycoor1.coor2;
		Ycoor2.coor2 = Ycoor1.coor2 + lambdafind2(Ycoor2); //This time, updated in x2 direction
		Xcoortemp.coor1 = Xcoor.coor1; //Xcoortemp will hold the previous coordinates to check the distance at the beginning of each while loop
		Xcoortemp.coor2 = Xcoor.coor2;
		Xcoor.coor1 = Ycoor2.coor1; //Xcoor updated in both directions
		Xcoor.coor2 = Ycoor2.coor2;
		k++; //One iteration ended
		cout << "k:   " << k << endl;  //We report information at each iteration
		cout << "Xcoor at kth iteration:   " << "(" << Xcoor.coor1 << ", " << Xcoor.coor2 << ")"<<endl;
		cout << "f(Xcoor):   " << objf(Xcoor) << endl;
		cout << "Ycoor1 at kth iteration:   " << "(" << Ycoor1.coor1 << "," << Ycoor1.coor2 << ")" << endl;
		cout << "lambda1 at kth iteration:   " << lambdafind1(Ycoor1) <<endl;
		cout << "lambda2 at kth iteration:   "  << lambdafind2(Ycoor2) << endl;
		cout << "Ycoor2 at kth iteration:   " << "(" << Ycoor2.coor1 << "," << Ycoor2.coor2 << ")" << endl;
		cout << endl;
	} while (((Xcoor.coor1 - Xcoortemp.coor1)*(Xcoor.coor1 - Xcoortemp.coor1) + (Xcoor.coor2 - Xcoortemp.coor2)*(Xcoor.coor2 - Xcoortemp.coor2)) >= eps*eps); //When the following improved point is less than eps far away, we stop. So we assume the current Xcoor to be our local max
	getchar();
	return 0;
	
}

