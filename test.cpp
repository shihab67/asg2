#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

int main()
{
    //Initializing an array to store 3 different array sizes
	int size[3] = {100000, 1000000, 10000000};
	int i, j, k;
	
	//Initializing a three dimensional array to store the result in a table format
	int results[3][10][3];
    
    //for loop to create ten arrays
	for (i = 0; i < 10; i++)
	{
	    //Another for loop to define each array sizes in each array 
		for (k = 0; k < sizeof(size) / sizeof(size[0]); k++)
		{
		    //Initializing the Array
			int *array = new int[size[k]];

			// Populating the Array with random numbers using rand() function
			for (j = 0; j < size[k]; j++)
			{
				array[j] = rand() % size[k];
			}

			// Starting the clock. The clock provides time in milliseconds
			std::clock_t start = std::clock();
			
			// Sorting the unsorted array and calculating time
			// and storing the results in results array
			sort(array, array + size[k]);
			results[k][i][0] = (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);

			// Sorting the sorted array, measuring time and storing the results
			start = std::clock();
			sort(array, array + size[k]);
			results[k][i][1] = (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);

			// Inversing the sorted array using reverse() function	
			reverse(array, array + size[k]);

            // Sorting the inverse array, measuring time and storing the results 
			start = std::clock();
			sort(array, array + size[k]);
			results[k][i][2] = (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);

			delete[] array;
		}
	}

	// Initializing an array of character
	// to store the name of the array sizes
	const char *array_names[3] = {"==================Table For The Array Size Of 100000==================",
	 							"==================Table For The Array Size Of 1000000==================",
								  "==================Table For The Array Size Of 10000000=================="};
	
	// Looping through the results array to print the array
	for (i = 0; i < 3; i++)
	{
		cout << array_names[i] << endl;
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