#pragma once
#include <iostream>
#include "Car.h"
using namespace std;

class Circuit
{
	private:
		int lungime_circuit,vreme,nr_masini=0;
		struct {
			Car* Masina;
			int pozitie;
			bool DNF;
			double timp;
		}Masini[10];

		
	
	public:
		void SetLength(int);
		void SetWeather(int);
		void AddCar(Car* masina);
		void Race();
		void ShowFinalRanks();
		void ShowWhoDidNotFinish();

};

