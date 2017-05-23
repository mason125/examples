#include "stdafx.h"
#include "calculations.h"
#include <iostream>
#include <iomanip>
using namespace std;

calculations::calculations()
{
}

void calculations::cal(double top[], double middle[], double bottom[])
{
	//calculations
	//dry = [0] wet = [1]
	double cal_top = (top[1] / top[0]) * 8.33;
	double cal_mid = (middle[1] / middle[0]) * 8.33;
	double cal_bot = (bottom[1] / bottom[0]) * 8.33; 

	cout << fixed << showpoint;
	cout << setprecision(2);
	cout << "Top: " << cal_top << endl;
	cout << "Middle: " << cal_mid << endl;
	cout << "Bottom: " << cal_bot << endl;
}
calculations::~calculations()
{
}
