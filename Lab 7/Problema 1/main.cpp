#include <iostream>

using namespace std;

float operator"" _Kelvin(unsigned long long int kelvin)
{
    return static_cast<float>(kelvin - 273.15);
}


float operator"" _Fahrenheit(unsigned long long int fahrenheit) 
{
    return static_cast<float>((fahrenheit - 32) * 5.0 / 9.0);
}

int main() 
{

    float a = 300_Kelvin;      
    float b = 120_Fahrenheit;  

    cout << "Temperatura in Celsius din 300K este: " << a << "C" << std::endl;
    cout << "Temperatura in Celsius din 120F este: " << b << "C" << std::endl;

    return 0;
}
