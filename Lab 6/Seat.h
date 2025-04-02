#pragma once
#include "Car.h"

class Seat : public Car {
public:

	Seat() {
		Fuel_Consum = 4;
		Fuel_Capacity = 40;
		Average_Speed[0] = 50;
		Average_Speed[1] = 60;
		Average_Speed[2] = 30;
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
		return "Seat";
	};

};