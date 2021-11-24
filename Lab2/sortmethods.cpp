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
void PrintArray(T array[], int n)
{
    for (int i = 0; i < n; i++) 
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int BinarySearch(int array[], int end, int x)
{
    int middle = 0;
    int start = 0;

    while (true)
    {
        middle = (start + end) / 2;

        if (x == array[middle])
        {
            return middle;
        }
        else
        if (x < array[middle])
        {
            end = middle - 1;
        }
        else if (x > array[middle])
        {
            start = middle + 1;
        }

        if (start > end)
        {
            return -1;
        }

    }
}	

int partition(int array[], int left, int right)
{
    int pivot = array[right];

    int index = (left - 1);

    for (int j = left; j < right; j++) 
    {
        if (array[j] <= pivot) 
        {
            index++;
            swap(array[index], array[j]);
        }
    }

    swap(array[index + 1], array[right]);

    return (index + 1);
}

void QuickSort(int array[], int low, int high)
{
    int i = low;
    int j = high;
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
    if (j > low)
    {
        QuickSort(array, low, j);
    }      
    if (i < high)
    {
        QuickSort(array, i, high);
    }      
}

void BubbleSort(int array[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
            }       
        }
    }       
}

bool isSorted(int array[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        if (array[i] > array[i + 1])
        {
            return false;
        }
    }

    return true;
}

void Shuffle(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        swap(array[i], array[rand() % n]);
    }    
}

void BogoSort(int array[], int n)
{
    srand(time(0));

    while (!isSorted(array, n))
    {
        Shuffle(array, n);
    }
}

void CountSort(char array[], int n)
{
    char max = array[0];

    for (int i = 1; i < n; i++)
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

    for (int i = 0; i < n; i++)
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