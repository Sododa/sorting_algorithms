#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: print the array after each time you swap two elements
 * @size: array size
 *
 * Return: Null
 */


void bubble_sort(int *array, size_t size)
{
	size_t a, b;
	int temp, swapped;

	if (size < 2)
		return;

	for (a = 0; a < size; a++)
	{
		swapped = 0;

		for (b = 0; b < size - (a + 1); b++)
		{
			if (array[b] > array[b + 1])
			{
				swapped = 1;
				temp = array[b];
				array[b] = array[b + 1];
				array[b + 1] = temp;
				print_array(array, size);
			}
		}
		if (!swapped)
			return;
	}
}
