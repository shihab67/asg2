#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

int main()
{
	int size[3] = {100000, 1000000, 10000000};
	int i, j, k;
	int results[3][10][3];

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

			std::clock_t start = std::clock();
			sort(array, array + size[k]);
			results[k][i][0] = (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);

			// ascendig order
			for (j = 0; j < size[k]; j++)
			{
				array[j] = j;
			}

			start = std::clock();
			sort(array, array + size[k]);
			results[k][i][1] = (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);

			// inverse order
			for (j = 0; j < size[k]; j++)
			{
				array[j] = size[k] - j;
			}

			start = std::clock();
			sort(array, array + size[k]);
			results[k][i][2] = (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);

			delete[] array;
		}
	}

	for (i = 0; i < 3; i++)
	{
		printf("%-20s%-20s%-20s%-20s\n", "", "Random", "Ascending", "Inverse");
		for (j = 0; j < 10; j++)
		{
			char s0[11];
			char s1[11];
			char s2[11];
			char s3[11];
			sprintf(s0, "%d", j + 1);
			sprintf(s1, "%d", results[i][j][0]);
			sprintf(s2, "%d", results[i][j][1]);
			sprintf(s3, "%d", results[i][j][2]);
			printf("%-20s%-20s%-20s%-20s\n", s0, s1, s2, s3);

			printf("\n");
		}

		printf("\n\n");
	}

	return 0;
}