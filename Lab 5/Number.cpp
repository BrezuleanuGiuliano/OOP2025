#include <iostream>
#include "Number.h"
#include <stdlib.h>
#include <cstring>

using namespace std;
Number::Number(const char* value, int base)
{
	this->base = base;
	this->number = new char[strlen(value)];
	int i;
	for ( i = 0; i < strlen(value); i++)
		this->number[i] = value[i];
	this->number[i] = '\0';

}
Number::Number(int numar)
{
	this->base = 10;
	this->number = new char[50];
	int i = 0;
	while (numar)
	{
		number[i] = numar % base + '0';

		numar = numar / base;
		i++;
	}
	number[i] = '\0';
	i--;
	for (int j = 0; j <= i / 2; j++)
		swap(number[j], number[i - j]);
}

/*Number::~Number()
{
	delete[] number;

}*/
void Number::Print()
{
	for (int i = 0; i < strlen(number); i++)
		cout << this->number[i];
	cout << endl;
}

int Number::GetBase()
{
	return this->base;
}

void Number::SwitchBase(int newBase)
{
	int putere = 1,numar=0,numarnou=0,i;
	for (i = strlen(number) - 1; i >= 0; i--)
	{
		if (number[i] <= '9' && number[i] >= '0')
			numar = numar + (number[i] - '0') * putere;
		else
			numar = numar + (number[i] - 'A'+10) * putere;;
		putere = putere * base;

	}
	i = 0;
	while (numar)
	{
		if (numar % newBase<10)
		number[i] = numar % newBase+'0';
		else
			number[i] = numar % newBase-10 + 'A';
		numar = numar / newBase;
		i++;
	}
	number[i] = '\0';
	i--;
	for (int j = 0; j <= i / 2; j++)
		swap(number[j], number[i - j]);
	this->base = newBase;

}

int Number::GetDigitsCount()
{
	return strlen(number);
}
int base10(const char *number, int base)
{
	int putere = 1,numar=0,numarnou=0,i;
	for (i = strlen(number) - 1; i >= 0; i--)
	{
		if (number[i] <= '9' && number[i] >= '0')
			numar = numar + (number[i] - '0') * putere;
		else
			numar = numar + (number[i] - 'A'+10) * putere;;
		putere = putere * base;

	}
	
	return numar;
}
Number operator +(const Number& Num1, const Number& Num2)
{
	
		int newBase = 0;
		if (Num1.base > Num2.base)
			newBase = Num1.base;
		else
			newBase = Num2.base;
		

		
		int numar = base10(Num1.number, Num1.base)+ base10(Num2.number, Num2.base);
		
		int i = 0;
		char number[50];
		while (numar)
		{
			if (numar % newBase < 10)
				number[i] = numar % newBase + '0';
			else
				number[i] = numar % newBase - 10 + 'A';
			numar = numar / newBase;
			i++;
		}
		number[i] = '\0';
		i--;
		for (int j = 0; j <= i / 2; j++)
			swap(number[j], number[i - j]);
		return Number(number, newBase);

}
Number operator -(const Number& Num1, const Number& Num2)
{

	int newBase = 0;
	if (Num1.base > Num2.base)
		newBase = Num1.base;
	else
		newBase = Num2.base;

	int numar = abs(base10(Num1.number, Num1.base) - base10(Num2.number, Num2.base));

	int i = 0;
	char number[50];
	while (numar)
	{
		if (numar % newBase < 10)
			number[i] = numar % newBase + '0';
		else
			number[i] = numar % newBase - 10 + 'A';
		numar = numar / newBase;
		i++;
	}
	number[i] = '\0';
	i--;
	for (int j = 0; j <= i / 2; j++)
		swap(number[j], number[i - j]);

	return Number(number, newBase);

}
bool  Number::operator >(const Number& Num1)
{
	if (base10(this->number, this->base) > base10(Num1.number, Num1.base))
		return true;
	return false;
}
bool  Number::operator >=(const Number& Num1)
{
	if (base10(this->number, this->base) >= base10(Num1.number, Num1.base))
		return true;
	return false;
}
bool  Number::operator <(const Number& Num1)
{
	if (base10(this->number, this->base) < base10(Num1.number, Num1.base))
		return true;
	return false;
}
bool  Number::operator <=(const Number& Num1)
{
	if (base10(this->number, this->base) <= base10(Num1.number, Num1.base))
		return true;
	return false;
}
bool  Number::operator ==(const Number& Num1)
{
	if (base10(this->number, this->base) == base10(Num1.number, Num1.base))
		return true;
	return false;
}
bool  Number::operator !=(const Number& Num1)
{
	if (base10(this->number, this->base) != base10(Num1.number, Num1.base))
		return true;
	return false;
}
char Number::operator[](int index)
{
	return this->number[index];

}
Number& Number:: operator--()
{
	int i;
	for ( i = 0; i < strlen(number)-1; i++)
	{
		number[i] = number[i + 1];
	}
	number[i] = '\0';
	return *this;
}
Number Number::operator--(int)
{
	Number temp = *this;

	this->number[strlen(temp.number) - 1] = '\0';

	return temp;


}
Number::Number(const Number& Num1)
{
	this->base = Num1.base;
	 
	this->number = new char[strlen(Num1.number)+1];
	int i;
	for (i = 0; i < strlen(Num1.number); i++)
		this->number[i] = Num1.number[i];
	number[i] = '\0';

}
Number::Number(Number&& Num1)
{
	this->base = Num1.base;
	this->number = Num1.number;
	Num1.base = 0;
	Num1.number=nullptr;
}
Number Number::operator =(const Number& Num1)
{
	
	this->base = Num1.base;
	this->number = new char[strlen(Num1.number) + 1];
	int i;
	for (i = 0; i < strlen(Num1.number); i++)
		this->number[i] = Num1.number[i];
	number[i] = '\0';
	
	return *this;
}
Number Number::operator =(const char* number)
{
	this->base = 10;
	this->number = new char[strlen(number) + 1];
	int i;
	for (i = 0; i < strlen(number); i++)
		this->number[i] = number[i];
	this->number[i] = '\0';
	return *this;
}
Number Number::operator =(int numar)
{

	int i = 0;
	while (numar)
	{
		number[i] = numar % base + '0';
		
		numar = numar / base;
		i++;
	}
	number[i] = '\0';
	i--;
	for (int j = 0; j <= i / 2; j++)
		swap(number[j], number[i - j]);
	return *this;

}
Number Number::operator +=(const Number& Num1)
{
	*this = *this + Num1;
	return *this;
}