#include <iostream>
#include <cstring>
#include <stdarg.h>     
#include "Math.h"

using namespace std;

 int Math::Add(int a, int b)
{
	return a + b;
}
int Math::Add(int a, int b, int c)
{
	return a + b + c;

}
int Math::Add(double a, double b)
{
	return a+b;
}
 int Math::Add(double a, double b, double c)
{
	 return a+b+c;
}
int Math::Mul(int a, int b)
{
	return a * b;
}
 int Math::Mul(int a, int b, int c)
{
	return a * b * c;
}
 int Math::Mul(double a, double b)
{
	 return a*b;
}
 int Math::Mul(double a, double b, double c)
{
	 return a*b*c;
}
 int Math::Add(int count, ...)
 {
	 va_list lista_stiva;
	 int suma = 0;
	 va_start(lista_stiva, count);
	 for (int i = 1; i <= count; i++)
	 {
		 suma = suma + va_arg(lista_stiva, int);
	 }
	 va_end(lista_stiva);
	 return suma;
 }
 char* Math::Add(const char* s1, const char* s2)
 {
	 char* result = new char[strlen(s1) + strlen(s2) + 1];
	 if (!s1 || !s2)
		 return nullptr;
	

	 strcpy_s(result,strlen(s1)+1, s1);
	 strcat_s(result, strlen(s1) + strlen(s2) + 1, s2);
	
	 return result;
 }