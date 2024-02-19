#include "sort.h"

/**
 * _swap - swap two values.
 * @array: the array for swap him values.
 * @a: First index
 * @b: Second index
 * @r_size: The size constant for print
 * Return: Nothing
 */
void _swap(int *array, int a, int b, const int r_size)
{
	int tmp;
	(void) r_size;

	if (a != b)
	{
		tmp = array[a];
		array[a] = array[b];
		array[b] = tmp;
		print_array(array, (size_t)r_size);
	}
}

/**
 * _largest - Find the largest number btween the layers
 * @array: The array for sort
 * @size: The minor element
 * @a: The largest.
 * @r_size: The size for print in swap
 * Return: Null
 */
void _largest(int *array, size_t size, int a, const int r_size)
{
	int largest = a;
	int lft = (2 * a) + 1;
	int rgt = (2 * a) + 2;

	if (lft < (int)size && array[lft] > array[largest])
		largest = lft;

	if (rgt < (int)size && array[rgt] > array[largest])
		largest = rgt;

	if (largest != a)
	{
		_swap(array, a, largest, r_size);
		_largest(array, size, largest, r_size);
	}
}

/**
 * heap_sort - Call largest while exist layers
 * @array: The array that generate the layers
 * @size: Size of the array
 * Return: Null
 */
void heap_sort(int *array, size_t size)
{
	const int r_size = (const int)size;
	int a;

	if (size < 2 || !array)
		return;

	for (a = size / 2 - 1; a >= 0; a--)
		_largest(array, size, a, r_size);

	for (a = size - 1; a >= 0; a--)
	{
		_swap(array, 0, a, r_size);
		_largest(array, a, 0, r_size);
	}
}
