#include "NumberList.h"
#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

void NumberList::Init()
{
	this->count = 0;

}

bool NumberList::Add(int x)
{
	
	if (count < 9)
	{
		
		this->numbers[count] = x;
		this->count++;
		return true;
	}
	else
		return false;


}

void NumberList::Sort()
{
	for(int i=0;i<this->count;i++)
		for (int j = i+1; j <this->count; j++)
			if (this->numbers[i] > this->numbers[j])
			{
				int k = this->numbers[i];
				this->numbers[i] = this->numbers[j];
				this->numbers[j] = k;
			}
	cout <<endl<< "Am sortat vectorul"<<endl<<endl;

}
void NumberList::Print()
{
	cout << "Vectorul de numere este: ";
	for (int i = 0; i <this->count; i++)
		cout<<this->numbers[i]<<' ';
	cout << endl;

}
void NumberList::SetName(const char s[30])
{
	int i;
	for ( i = 0; i < strlen(s); i++)
		this->NameStudent[i] = s[i];
	this->NameStudent[i] = '\0';
}
const char* NumberList::GetName()
{
	return NameStudent;
}
void NumberList::SetMath(float x)
{
	this->Math = x;

}
float NumberList::GetMath()
{
	return this->Math;
}
void NumberList::SetEnglish(float x)
{
	this->English = x;

}
float NumberList::GetEnglish()
{
	return this->English;
}

void NumberList::SetHistory(float x)
{
	this->History = x;

}
float NumberList::GetHistory()
{
	return this->History;
}
float NumberList::AverageGrade()
{
	return (Math + English + History) / 3;
}
