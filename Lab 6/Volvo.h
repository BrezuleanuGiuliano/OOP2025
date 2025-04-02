#pragma once
#include "Car.h"

class Volvo : public Car
{
public:

	Volvo() {
		Fuel_Consum = 10.8;
		Fuel_Capacity = 40;
		Average_Speed[0] = 90;
		Average_Speed[1] = 100;
		Average_Speed[2] = 50;
	};
	float Get_Fuel_Capacity()override
	{
		return Fuel_Capacity;
	};
	float Get_Fuel_Consum() override
	{
		return Fuel_Consum;
	};
	float Get_Average_Speed(int Vreme) override
	{
		return Average_Speed[Vreme];
	};
	const char* GetName() override
	{
		return "Volvo";
	};

};