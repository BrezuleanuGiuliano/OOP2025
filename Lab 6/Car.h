#pragma once
#include <iostream>
using namespace std;

class Car
{
protected:

	double Fuel_Consum, Fuel_Capacity, Average_Speed[3];
public:

	virtual float Get_Fuel_Capacity()=0;
	virtual float Get_Fuel_Consum()=0;
	virtual float Get_Average_Speed(int Vreme)=0;
	virtual const char* GetName()=0;



};

