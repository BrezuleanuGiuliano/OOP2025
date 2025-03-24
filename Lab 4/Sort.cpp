#include <iostream>
#include "Sort.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdarg.h>

using namespace std;

Sort::Sort(int Nr_elem, int min, int max)
{
	srand((unsigned)time(0));
	this->list = new int[Nr_elem];
	for (int i = 0; i < Nr_elem; i++)
	{
		this->list[i] = min + rand() % (max - min + 1);
		
	}
	this->Nr_elem = Nr_elem;


}
Sort::Sort()
{
	this->list = new int[10] {2,5,3,7,8,92,36,4,8,12};
	this->Nr_elem = 10;
}
Sort::Sort(int* v, int Nr_elem)
{
	this->list = new int[Nr_elem];
	this->Nr_elem = Nr_elem;

	for (int i = 0; i < Nr_elem; i++)
		this->list[i] = v[i];
		
}

Sort::Sort(int count,...)
{
	this->list = new int[count];
	this->Nr_elem = count;
	va_list lista_stiva;
	va_start(lista_stiva, count);
	for (int i = 0; i < count; i++)
	{
		this->list[i] = va_arg(lista_stiva, int);
	}
	va_end(lista_stiva);
	

}

Sort::Sort(const char* s)
{
	int nr_elem=1;

	for (int i = 0; i < strlen(s); i++)
		if (s[i] == ',')
			nr_elem++;
	this->Nr_elem = nr_elem;
	nr_elem = 0;
	this->list = new int[Nr_elem];


	for (int i = 0; i < strlen(s); i++)
	{
		int nractual = 0;
		while ('0' <= s[i] && s[i] <= '9')
		{
			nractual = nractual * 10 + s[i] - '0';
			i++;
		}
		list[nr_elem] = nractual;
		nr_elem++;
	}
}
void Sort::InsertSort(bool ascendent)
{
	for (int i = 1; i < Nr_elem; ++i) {
		int key = list[i];
		int j = i - 1;

		
			while (j >= 0 && (!ascendent && list[j] < key) || (ascendent && list[j] > key))//Selectam in acelasi tim asc/desc
			{
			list[j + 1] = list[j];
			j = j - 1;
			}
		list[j + 1] = key;

		
	}
}

int Sort::Partition(int left, int right, bool ascendent) {
	int pivot = list[right]; 
	int i = left - 1; 

	for (int j = left; j < right; j++) {
		if ((ascendent && list[j] < pivot) || (!ascendent && list[j] > pivot)) {
			i++;
			swap(list[i], list[j]);
		}
	}
	swap(list[i + 1], list[right]); 
	return i + 1;
}


void Sort::QuickSortHelper(int left, int right, bool ascendent) {
	if (left < right) {
		int pivotIndex = Partition(left, right, ascendent);
		QuickSortHelper(left, pivotIndex - 1, ascendent);
		QuickSortHelper(pivotIndex + 1, right, ascendent);
	}
}


void Sort::QuickSort(bool ascendent) {
	QuickSortHelper(0, Nr_elem - 1, ascendent);
}

void Sort::BubbleSort(bool ascendent) 
{
	int n = this->Nr_elem;
	bool swapped;

	for (int i = 0; i < n - 1; i++) {
		swapped = false;
		for (int j = 0; j < n - i - 1; j++) {
			if ((ascendent && list[j] > list[j+1]) || (!ascendent && list[j] <list[j+1])) {
				swap(list[j], list[j + 1]);
				swapped = true;
			}
		}

		
		if (!swapped)
			break;
	}
}

void Sort:: Print()
{
	for (int i = 0; i < Nr_elem; i++)
		cout << list[i]<<' ';
}
int Sort:: GetElementsCount()
{
	return this->Nr_elem;
}
int  Sort::GetElementFromIndex(int index)
{
	if(0<=index&&index<=Nr_elem)
	return this->list[index];
	else
	{
		cout << "Nu te afli in lista";
		return -1;
	}
}
