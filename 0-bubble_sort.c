#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void bubble_sort(int *array, size_t size)
{
  size_t i;
  size_t j;
  bool swapped = false;

  for (i = 0 && swapped; i < size - 1; i++)
  {
    for (j = 0; j < size - i - 1; j++)
    {
      if (array[j] > array[j + 1])
      {
        int temp = array[j];

        array[j] = array[j + 1];
        array[j + 1] = temp;
        swapped = true;
        print_array(array, size);
      }
    }
  }
}

