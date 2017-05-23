// ConsoleApplication8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "calculations.h"

using namespace std;


int main()
{
	double top[2];
	double bot[2];
	double mid[2];

	//create object
	calculations data;

	//enter top data
	cout << "Enter dry top ";
	cin >> top[0];

	cout << "Enter wet top ";
	cin >> top[1];

	//enter middle data
	cout << "Enter dry middle ";
	cin >> mid[0];

	cout << "Enter wet middle ";
	cin >> mid[1];

	//enter bottom data
	cout << "Enter dry bottom ";
	cin >> bot[0];

	cout << "Enter wet bottom ";
	cin >> bot[1];

	data.cal(top, mid, bot);

	system("pause");
    return 0;
}

