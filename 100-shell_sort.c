#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using the
 *              Shell sort algorithm with the Knuth sequence.
 *
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void shell_sort(int *array, size_t size)
{
	int gap = 1, i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	/* Calculate initial gap using Knuth sequence */
	while (gap <= (int)size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		/* Perform insertion sort with the current gap */
		for (i = gap; i < (int)size; i++)
		{
			temp = array[i];

			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}

			array[j] = temp;
		}

		print_array(array, size);

		/* Calculate the next gap using Knuth sequence */
		gap = (gap - 1) / 3;
	}
}

