#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
	int size[3] = {100000, 1000000, 10000000};
	int array[2];
	int i, j, k;
	
	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < size[i]; j++)
		{
			array[j] = rand() % size[i];

			int length = sizeof(array) / sizeof(array[0]);

			clock_t start = clock();
			sort(array, array + length);
			clock_t end = clock();

			cout << "Size: " << size[i] << endl;
			cout << "Time: " << (end - start) / (double)CLOCKS_PER_SEC << endl;
		}
	}

	// cout << "Enter the size of the array: ";
	// cin >> size;

	// for (i = 0; i < size; i++)
	// {
	// 	array[i] = rand() % 100;
	// }

	// cout << "Unsorted array: ";
	// printArray(array, size);

	// clock_t startTime = clock();

	// bubbleSort(array, size);

	// clock_t endTime = clock();

	// cout << "Sorted array: ";
	// printArray(array, size);

	// cout << "Time: " << (endTime - startTime) / (double)CLOCKS_PER_SEC << " seconds" << endl;
}

// void printArray(int array[], int size)
// {
// 	int i;

// 	for (i = 0; i < size; i++)
// 	{
// 		cout << array[i] << " ";
// 	}
// 	cout << endl;
// }




