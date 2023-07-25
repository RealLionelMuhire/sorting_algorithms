#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * bubble_sort - sorts an array of integers in ascending order using
 * --------------the Bubble sort algorithm
 * @array: array after each time you swap two elements
 * @size: size of sort
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	bool swapped = false;
	int temp;

	for (i = 0 && swapped; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];

				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = true;
				print_array(array, size);
			}
		}
	}
}

