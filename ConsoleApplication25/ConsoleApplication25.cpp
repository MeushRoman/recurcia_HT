// ConsoleApplication25.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>

using namespace std;

int a[10];

int arr(int a[], int size) {
	if (size < 0) return size;

	a[size] = 1 + rand() % 10;
	arr(a, size - 1);
}


//1. 	Написать функцию, определяющую среднее арифметическое элементов передаваемого ей массива.
float sr, sum = 0;

void sra(int a[], int size) {
	
	if (size < 0) return;
	
	sum += a[size];

	
	sra(a, size - 1);
	sr = sum / 10;
}
//2.	Написать функцию, определяющую количество положительных, отрицательных и нулевых элементов передаваемого ей массива.
void func(int a[], int size, int& n, int& o, int& p) {


	if (size == 0) return;

	if (a[size] < 0) o++; else if (a[size] > 0) p++; else n++;

	func(a, size - 1, n, o, p);
}



//3.	Написать функцию, определяющую минимум и максимум (значение и номер) элементов передаваемого ей массива.


void funcMM(int a[], int size, int& min, int& max, int& iMin, int& iMax) {
	if (size == 0) return;
	
	if (a[size] < min) { min = a[size]; iMin = size; }
	if (a[size] > max) { max = a[size]; iMax = size; }

	funcMM(a, size - 1, min, max, iMin, iMax);
}


int main()
{
	srand(time(NULL));


	//1.
	arr(a, 10);
	
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	sra(a, 10);
	//cout << sum << endl;
	cout << "1. " << sr << endl << endl;



	//2.
	cout << "2. " ;
	int n = 0, o = 0, p = 0;
	int b[] = { -1,2,-3, 1, 2, 0, 0, 0, 0 };
	for (int i = 0; i < 9; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;
	func(b, 9, n, o, p);
	cout << "> " << p << endl;
	cout << "< " << o << endl;
	cout << "0 " << n << endl << endl;
	

	//3.
	cout << "3. ";
	int ar[15];
	
	arr(ar, 14);
	for (int i = 0; i < 15; i++)
	{
		cout << ar[i] << " ";
	}
	cout << endl << endl;
	int min = INT_MAX, max = INT_MIN, iMin = 0, iMax = 0;
	funcMM(ar, 14, min, max, iMin, iMax);
	cout << "min = " << "a[" << iMin << "] = " << min << endl;
	cout << "max = " << "a[" << iMax << "] = " << max << endl << endl;

    return 0;
}

