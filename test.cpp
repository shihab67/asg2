#include <iostream>
#include <chrono>
#include <algorithm>
using namespace std;

int main()
{
	int size[3] = {100000, 1000000, 10000000};
	int i, j, k;
	cout << sizeof(size) / sizeof(size[0]) << endl;

	for (i = 0; i < 10; i++)
	{
		for (k = 0; k < sizeof(size) / sizeof(size[0]); k++)
		{
			int *array = new int[size[k]];
			cout << k << endl;

			for (j = 0; j < size[k]; j++)
			{
				array[j] = rand() % size[k];
				// 			int length = sizeof(array) / sizeof(array[0]);
			}

			auto start = chrono::steady_clock::now();
			sort(array, array + size[k]);
			auto end = chrono::steady_clock::now();
			// 			for (int l = 0 ; l < size[k] ; l++) {
			//                 cout << array[l] << endl;
			// 			}
			delete[] array;

			cout << "Size: " << size[k] << endl;
			cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " milliseconds" << endl;
		}
	}
	return 0;
}