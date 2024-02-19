#include "sort.h"
#include <stdio.h>
/**
 * _swap - swaped two integers
 * @array: the array that values are swaped.
 * @a: First index
 * @b: Second index
 * Return: Null
 */
void _swap(int *array, int a, int b)
{
	int tmp;

	if (array[a] != array[b])
	{
		tmp = array[a];
		array[a] = array[b];
		array[b] = tmp;
	}
}

/**
 * shell_sort - sort the list and print the changes
 * @array: The array to sort.
 * @size: Size of the array
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t c = 0,  a, b;

	if (size < 2)
		return;

	while (c <= size / 3)
		c = c * 3 + 1;

	while (c >= 1)
	{
		for (a = c; a < size; a++)
			for (b = a; b >= c && array[b] < array[b - c]; b -= c)
				_swap(array, b, b - c);
		c /= 3;
		print_array(array, size);
	}
}
