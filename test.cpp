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

			// random order
			for (j = 0; j < size[k]; j++)
			{
				array[j] = rand() % size[k];
			}

			auto start = chrono::steady_clock::now();
			sort(array, array + size[k]);
			auto end = chrono::steady_clock::now();

			cout << "Random Order:" << endl;
			cout << "Size: " << size[k] << endl;
			cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " milliseconds" << endl;

			// ascendig order
			for (j = 0; j < size[k]; j++)
			{
				array[j] = j;
			}

			start = chrono::steady_clock::now();
			sort(array, array + size[k]);
			end = chrono::steady_clock::now();

			cout << "Ascending Order:" << endl;
			cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " milliseconds" << endl;

			// inverse order
			for (j = 0; j < size[k]; j++)
			{
				array[j] = size[k] - j;
			}

			start = chrono::steady_clock::now();
			sort(array, array + size[k]);
			end = chrono::steady_clock::now();

			cout << "Inverse Order:" << endl;
			cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " milliseconds" << endl;

			delete[] array;
		}
	}

	return 0;
}