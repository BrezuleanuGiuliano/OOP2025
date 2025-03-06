#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "NumberList.h"

using namespace std;

int CompareByName(NumberList& s1, NumberList& s2)
{
	int ok;
	ok = strcmp(s1.GetName(), s2.GetName());
	if (ok < 0)
		return -1;
	if (ok == 0)
		return 0;
			
	return 1;


}

int CompareMath(NumberList& s1, NumberList& s2)
{
	float ok;
	ok = s1.GetMath() - s2.GetMath();
	if (ok < 0)
		return -1;
	if (ok > 0)
	return 1;

	return 0;
}
int CompareEnglish(NumberList& s1, NumberList& s2)
{
	float ok;
	ok = s1.GetEnglish() - s2.GetEnglish();
	if (ok < 0)
		return -1;
	if (ok > 0)
	return 1;
	else
	return 0;
}
int CompareHistory(NumberList& s1, NumberList& s2)
{
	float ok;
	ok = s1.GetHistory() - s2.GetHistory();
	if (ok < 0)
		return -1;
	if (ok > 0)
	return 1;

	return 0;
}
int CompareAverageGrade(NumberList& s1, NumberList& s2)
{
	float ok;
	ok = s1.AverageGrade() - s2.AverageGrade();
	if (ok < 0)
		return -1;
	if (ok > 0)
	return 1;

	return 0;
}
int main()
{ 
	NumberList s1,s2;
	s1.Init();
	s1.Add(5);
	s1.Add(1);
	s1.Add(6);
	s1.Add(8);
	s1.Add(10);
	s1.Add(9);
	s1.Print();
	s1.Sort();
	s1.Print();
	cout << endl;

	s1.SetName("Giuliano");
	cout << "Student Name: " << s1.GetName() << endl;
	s1.SetMath(5.5f);
	cout << "Mate: " << s1.GetMath() << endl;
	s1.SetEnglish(9.5f);
	cout << "English: " << s1.GetEnglish() << endl;
	s1.SetHistory(7.5f);
	cout << "History: " << s1.GetHistory() << endl;
	cout << "Media: " << s1.AverageGrade()<< endl<<endl;
	


	s2.SetName("Petru");
	cout << "Student Name: " << s2.GetName() << endl;
	s2.SetMath(6.5f);
	cout << "Mate: " << s2.GetMath() << endl;
	s2.SetEnglish(5.5f);
	cout << "English: " << s2.GetEnglish() << endl;
	s2.SetHistory(5.5f);
	cout << "History: " << s2.GetHistory() << endl;
	cout << "Media: " << s2.AverageGrade() << endl<<endl;
	cout << "Comparare dupa nume: " << CompareByName(s1, s2) << endl;
	cout << "Comparare dupa nota la mate: " << CompareMath(s1, s2) << endl;
	cout << "Comparare dupa nota la engleza: " << CompareEnglish(s1, s2) << endl;
	cout << "Comparare dupa la nota istorie: " << CompareHistory(s1, s2) << endl;
	cout << "Comparare dupa media generala: " << CompareAverageGrade(s1, s2) << endl;

}