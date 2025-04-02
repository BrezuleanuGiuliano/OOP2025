#pragma once
#include "Car.h"

class BMW : public Car{
public:

	BMW() {
		Fuel_Consum = 7.8;
		Fuel_Capacity = 60;
		Average_Speed[0] = 100;
		Average_Speed[1] = 130;
		Average_Speed[2] = 70;
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
		return "BMW";
	};
	

};

