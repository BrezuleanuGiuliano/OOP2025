#include "Circuit.h"

void Circuit::SetLength(int lungime)
{
	lungime_circuit = lungime;
}
void Circuit::SetWeather(int vreme)
{
	this->vreme = vreme;
}
void Circuit::AddCar(Car* masina)
{
	nr_masini++;
	Masini[nr_masini].Masina = masina;
}
void Circuit::Race()
{
	for (int i = 1; i <= nr_masini; i++)
	{
		if (Masini[i].Masina->Get_Fuel_Capacity() / Masini[i].Masina->Get_Fuel_Consum() * 100 < lungime_circuit)
			Masini[i].DNF = 1;
		else
			Masini[i].DNF = 0;
		if (Masini[i].DNF == 0)
			Masini[i].timp = lungime_circuit / Masini[i].Masina->Get_Average_Speed(vreme);
		else
			Masini[i].timp = - 1;
	}
	for (int i = 1; i < nr_masini; i++)
		for (int j = i + 1; j <= nr_masini; j++)
		{
			if (Masini[i].timp > Masini[j].timp)
			{
				Masini[0] = Masini[i];
				Masini[i] = Masini[j];
				Masini[j] = Masini[0];

			}
		}
		
}
void Circuit::ShowFinalRanks()
{
	cout << "TOP:" << endl;
	int pozitie = 1;
	for (int i = 1; i <= nr_masini; i++)
	{
		if (Masini[i].DNF == 0)
		{
			cout << "Pozitia " << pozitie << ": " << Masini[i].Masina->GetName() << endl;
			pozitie++;
		}
	}
	cout << endl;
}
void Circuit::ShowWhoDidNotFinish()
{
	cout << endl << "Nu au terminat cursa: " << endl;
	for (int i = 1; i <= nr_masini; i++)
	{
		if (Masini[i].DNF == 1)
		{
			cout << Masini[i].Masina->GetName() <<" (DNF)" << endl;;
		}
	}
	cout << endl;
}