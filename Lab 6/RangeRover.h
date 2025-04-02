#pragma once
#include "Car.h"

class RangeRover : public Car {
public:

	RangeRover() {
		Fuel_Consum = 7.8;
		Fuel_Capacity = 80;
		Average_Speed[0] = 100;
		Average_Speed[1] = 100;
		Average_Speed[2] = 100;
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
		return "Range Rover";
	};

};