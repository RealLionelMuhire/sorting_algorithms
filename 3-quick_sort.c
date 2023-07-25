#include <stdio.h>
#include <stdlib.h>

/**
 * swap - Swaps two integers
 *
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort
 *
 * @array: Pointer to the array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 *
 * Return: Index of the pivot after partitioning
 */
int lomuto_partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1, j, k;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
			}
		}
	}
	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		printf("Current array: ");
		for (k = low; k <= high; k++)
			printf("%d%s", array[k], k < high ? ", " : "\n");
	}
	return (i + 1);
}

/**
 * quick_sort_recursive - Recursive helper function for Quick sort
 *
 * @array: Pointer to the array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 */
void quick_sort_recursive(int *array, int low, int high)
{
	if (low < high)
	{
		int partition_idx = lomuto_partition(array, low, high);
		quick_sort_recursive(array, low, partition_idx - 1);
		quick_sort_recursive(array, partition_idx + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using the
 *              Quick sort algorithm with Lomuto partition scheme.
 *
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	quick_sort_recursive(array, 0, size - 1);
}

