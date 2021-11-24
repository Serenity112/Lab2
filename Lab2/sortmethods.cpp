#include <iostream>
#include "sortmethods.h"

using namespace std;

void swap(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}

template <typename T>
void PrintArray(T array[], int size)
{
    for (int i = 0; i < size; i++) 
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int BinarySearch(int array[], int size, int x)
{
    int middle = 0;
    int start = 0;

    while (true)
    {
        middle = (start + size) / 2;

        if (x == array[middle])
        {
            return middle;
        }
        else
        if (x < array[middle])
        {
            size = middle - 1;
        }
        else if (x > array[middle])
        {
            start = middle + 1;
        }

        if (start > size)
        {
            return -1;
        }

    }
}	

void QuickSort(int array[], int left, int right)
{
    int i = left;
    int j = right;
    int pivot = array[(i + j) / 2];
    while (i <= j)
    {
        while (array[i] < pivot)
        {
            i++;
        }        
        while (array[j] > pivot)
        {
            j--;
        }            
        if (i <= j)
        {
            swap(array[i], array[j]);
            i++;
            j--;
        }
    }
    if (j > left)
    {
        QuickSort(array, left, j);
    }      
    if (i < right)
    {
        QuickSort(array, i, right);
    }      
}

void BubbleSort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
            }       
        }
    }       
}

bool isSorted(int array[], int size)
{
    for (int i = 0; i < size-1; i++)
    {
        if (array[i] > array[i + 1])
        {
            return false;
        }
    }

    return true;
}

void Shuffle(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        swap(array[i], array[rand() % size]);
    }    
}

void BogoSort(int array[], int size)
{
    srand(time(0));

    while (!isSorted(array, size))
    {
        Shuffle(array, size);
    }
}

void CountSort(char array[], int size)
{
    char max = array[0];

    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    int* count = new int[max + 1];

    for (int i = 0; i < max+1; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        count[(int)array[i]]++;
    }

    int index = 0;
    
     for (int i = 0; i < max+1; i++)
     {
        for (int j = 0; j < count[i]; j++)
        {
           array[index] = i;
           index++;
        }
     } 

    delete[] count;
}