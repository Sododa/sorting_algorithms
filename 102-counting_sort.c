#include "sort.h"
#include <stdio.h>
/**
 * _largest -  Give me the largest number in a array of integers
 * @array: The Int array
 * @size: Size of array
 * Return: The largest number
 */
int _largest(int *array, size_t size)
{
	size_t a;
	int c = 0;

	for (a = 0; a < size; a++)
	{
		if (c < array[a])
			c = array[a];
	}

	return (c);
}
/**
 * _memset -  Create a integer array and set each space in 0
 * @size: Size of array
 * Return: The integer array
 */
int *_memset(int size)
{
	int *ptr = NULL;
	int a;

	ptr = malloc((size) * sizeof(int));

	for (a = 0; a < size; a++)
		ptr[a] = 0;

	return (ptr);
}
/**
 * counting_sort - sort an array with the counting sort algorithm
 * @array: The Int array
 * @size: Size of array
 * Return: The sorted list
 */
void counting_sort(int *array, size_t size)
{
	size_t a, b;
	int c = 0;
	int *ptr = NULL, *sort_ar = NULL;

	if (size < 2)
		return;
	c = _largest(array, size);
	ptr = _memset(c + 1);
	if (!ptr)
		return;
	for (a = 0; a < size; a++)
		for (b = 0; (int)b < c + 1; b++)
			if ((int)b == array[a])
				ptr[b] += 1;
	for (a = 0; (int)a < c; a++)
		ptr[a + 1] = ptr[a] + ptr[a + 1];
	print_array(ptr, c + 1);
	/*Create the sort array*/
	sort_ar = malloc(size * sizeof(int));
	if (!sort_ar)
	{
		free(ptr);
		return;
	}

	for (a = 0; a < size; a++)
	{
		sort_ar[ptr[array[a]] - 1] = array[a];
		ptr[array[a]] -= 1;
	}
	for (b = 0; b < size; b++)
		array[b] = sort_ar[b];

	free(sort_ar);
	free(ptr);
}
