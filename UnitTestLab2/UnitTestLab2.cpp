#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab2\sortmethods.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab2
{
	TEST_CLASS(SortingTests)
	{
	public:
		
		TEST_METHOD(QuickSort1)
		{
			int array[] = { 6, -3, 5 , 1, 7 };
			int result[] = { -3, 1, 5, 6, 7 };
			int n = sizeof(array) / sizeof(array[0]);
			QuickSort(array, 0, n-1);

			for (int i = 0; i < n-1; i++)
			{
				Assert::AreEqual(array[i], result[i]);
			}
		}

		TEST_METHOD(QuickSort2)
		{
			int array[] = { -1, -9, -2, -3, 0, 0, -10 };
			int result[] = { -10, -9, -3, -2, -1, 0, 0 };
			int n = sizeof(array) / sizeof(array[0]);

			QuickSort(array,0, n-1);

			for (int i = 0; i < n-1; i++)
			{
				Assert::AreEqual(array[i], result[i]);
			}
		}

		TEST_METHOD(BubleSort1) 
		{
			int array[] = { 6, -3, 5 , 1, 7 };
			int result[] = { -3, 1, 5, 6, 7 };
			int n = sizeof(array) / sizeof(array[0]);

			BubbleSort(array, n);

			for (int i = 0; i < n; i++)
			{
				Assert::AreEqual(array[i], result[i]);
			}
		}

		TEST_METHOD(BubleSort2)
		{
			int array[] = { -1, -9, -2, -3, 0, 0, -10 };
			int result[] = { -10, -9, -3, -2, -1, 0, 0 };
			int n = sizeof(array) / sizeof(array[0]);

			BubbleSort(array, n);

			for (int i = 0; i < n; i++)
			{
				Assert::AreEqual(array[i], result[i]);
			}
		}


		TEST_METHOD(BogoSort1) 
		{
			int array[] = { 6, -3, 5 , 1, 7 };
			int result[] = { -3, 1, 5, 6, 7 };
			int n = sizeof(array) / sizeof(array[0]);

			BogoSort(array, n);

			for (int i = 0; i < n; i++)
			{
				Assert::AreEqual(array[i], result[i]);
			}
		}

		TEST_METHOD(BogoSort2) 
		{
			int array[] = { -1, -9, -2, -3, 0 };
			int result[] = {-9, -3, -2, -1, 0 };
			int n = sizeof(array) / sizeof(array[0]);

			BogoSort(array, n);

			for (int i = 0; i < n; i++)
			{
				Assert::AreEqual(array[i], result[i]);
			}
		}

		TEST_METHOD(CountSort1) 
		{
			char array[] = { 'z', 'x', 'c', 'a', 'c', 'b', 'w', 'f', 'd' };
			char result[] = {'a', 'b', 'c', 'c', 'd', 'f', 'w', 'x', 'z'};
			int n = sizeof(array) / sizeof(array[0]);

			CountSort(array, n);

			for (int i = 0; i < n; i++)
			{
				Assert::AreEqual(array[i], result[i]);
			}
		}

		TEST_METHOD(BinarySearch1)
		{
			int array[] = { -1, -9, -2, -3, 0 };
			int result = 1;
			int n = sizeof(array) / sizeof(array[0]);

			QuickSort(array, 0, n-1);

			Assert::AreEqual(BinarySearch(array, n, -3), result);
		}
		

	};

}
