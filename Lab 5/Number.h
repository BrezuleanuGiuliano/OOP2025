class Number
{
private:
	int base;
	char* number;
	// add data members

public:
	Number(const char* value, int base); // where base is between 2 and 16

	// add operators and copy/move constructor
	Number(const Number& Num1);
	Number(Number&& Num1);
	Number(int);
	//~Number();

	

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
	bool operator >(const Number& Num1);
	bool operator <(const Number& Num1);
	bool operator >=(const Number& Num1);
	bool operator <=(const Number& Num1);
	bool operator ==(const Number& Num1);
	bool operator !=(const Number& Num1);
	char operator [](int index);
	Number& operator--();
	Number operator--(int);
	Number operator =(const Number& Num1);
	Number operator =(int);
	Number operator =(const char* number);
	Number operator +=(const Number& Num1);
	friend Number operator +(const Number& Num1, const Number& Num2);
	friend Number operator -(const Number& Num1, const Number& Num2);
};
