#include "sort.h"

/**
 * selection_sort - function that sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: print the array after each time you swap two elements
 * @size: the size of the array
 * Return: Null
 */

void selection_sort(int *array, size_t size)
{
	size_t a, b;
	int idx, temp, swap;

	for (a = 0; a < size - 1; a++)
	{
		idx = a;
		swap = 0;

		for (b = a + 1; b < size; b++)
		{
			if (array[b] < array[idx])
			{
				idx = b;
				swap = 1;
			}
		}

		if (swap)
		{
			temp = array[a];
			array[a] = array[idx];
			array[idx] = temp;

			print_array(array, size);
		}
	}
}
