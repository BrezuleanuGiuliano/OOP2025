#pragma once
#include "Car.h"

class Fiat : public Car {
public:

	Fiat() {
		Fuel_Consum = 12;
		Fuel_Capacity = 20;
		Average_Speed[0] = 30;
		Average_Speed[1] = 50;
		Average_Speed[2] = 20;
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
		return "Fiat";
	};

};