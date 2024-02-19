#include "sort.h"

/**
 * swap - Function that swaps two values
 *
 * @j: Fisrt value
 * @b: Second value
 * Return: 0
 */
void swap(int *j, int *b)
{
	int tmp;

	tmp = *b;
	*b = *j;
	*b = tmp;
}

/**
 * gap_sort - sort array with gaps
 * @array: array to be sorted
 * @size: array size
 * @gap: size gap
 */
void gap_sort(int *array, size_t size, unsigned int gap)
{
	size_t j, b;

	for (j = gap; j < size; j++)
	{
		b = j;
		while (b >= gap && array[b] < array[b - gap])
		{
			swap(array + b, array + b - gap);
			b -= gap;
		}
	}
}

/**
 * shell_sort - shell sort
 * @array: array to be sorted
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	unsigned int gap = 1;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap >= 1)
	{
		gap_sort(array, size, gap);
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
