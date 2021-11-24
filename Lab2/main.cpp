#include "sortmethods.h"
#include "arrayprint.h"
#include "arrayprint.cpp"

#include <ctime>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "Russian");  
    unsigned int start_time;
    unsigned int end_time;

    for (int size = 10; size != 1000000; size *= 10)
    {
        cout << "Test for " << size << " elements: " << endl;
        int* a = new int[size];

        double QuickSortTime = 0;
        double BubbleSortTime = 0;

        for (int i = 0; i < 10; i++) //Average of 10 iterations
        {
            srand(i + size);
            for (int j = 0; j < size; j++)
            {
                a[j] = rand() % 100;
            }

            start_time = clock();
            QuickSort(a, 0, size-1);
            end_time = clock();

            QuickSortTime += end_time - start_time;   

            srand(i + size);
            for (int j = 0; j < size; j++)
            {
                a[j] = rand() % 100;
            }

            start_time = clock();
            BubbleSort(a, size);
            end_time = clock();

            BubbleSortTime += end_time - start_time;
        }

        delete[] a;

        cout << fixed << setprecision(5) << "QuickSort: " << (QuickSortTime  / 10) / (double)CLOCKS_PER_SEC << " seconds" << endl;
        cout << fixed << setprecision(5) << "BubbleSort: " << (BubbleSortTime / 10) / (double)CLOCKS_PER_SEC << " seconds" << endl;
  
    }     

    int* b = new int[10];

    for (int j = 0; j < 10; j++)
    {
        b[j] = rand() % 100;
    }

    cout << "\nArray B:\n";
    PrintArray(b, 10);

    start_time = clock();
    BogoSort(b, 10);
    end_time = clock();

    cout << "Array B sorted with bogosort:\n";
    PrintArray(b, 10);
    cout << "Time needed: " << (end_time - start_time) / (double)CLOCKS_PER_SEC << endl;

    int c[] = {-9, -6, -2, -1, 0, 4, 6, 11, 28, 100 };
    cout << "\nArray C:" << endl;
    PrintArray(c, 10);
    cout << "Binary search for 0 in C: " << BinarySearch(c, 10, 0) << endl;



    char ch[] = {'w', 'o', 'w', 'h', 'e', 'l', 'p'};
    cout << "\nChar array:" << endl;
    PrintArray(ch, 7);
    cout << "Counting Sort: " << endl;
    start_time = clock();
    CountSort(ch, 7);
    end_time = clock();
    PrintArray(ch, 7);
    cout << "Time needed: " << (end_time - start_time) / (double)CLOCKS_PER_SEC << endl;

    return 0;
}