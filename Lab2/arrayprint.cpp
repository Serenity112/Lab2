#include "arrayprint.h"
#include <iostream>
using namespace std;

template <typename  T>
void PrintArray(T array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}