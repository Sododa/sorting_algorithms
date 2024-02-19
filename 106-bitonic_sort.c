#include "sort.h"

/**
 * printcheck - print a range check
 * @array: The array to print
 * @r1: Less range
 * @r2: Final range
 * Return: null
 */
void printcheck(int *array, int r1, int r2)
{
	int a;

	for (a = r1; a <= r2; a++)
	{
		if (a > r1)
			printf(", ");
		printf("%d", array[a]);
	}
	printf("\n");
}
/**
 * _swap - swap two elements in an array
 * @array: THe array to change the values
 * @a: A index
 * @b: Another index
 * @dir: Direction of the array
 * Return: Null
 */
void _swap(int *array, int a, int b, int dir)
{
	int tmp;

	if (dir == (array[a] > array[b]))
	{
		tmp = array[a];
		array[a] = array[b];
		array[b] = tmp;
	}
}
/**
 * bitonic_merge - swap the elements to sort
 * @array: Array to sort
 * @low: The low element in the range to sort
 * @size: The size of the range to sort
 * @dir: Indicate which half are manage
 * @r_size: The size of the all array
 * Return: Null
 */
void bitonic_merge(int *array, int low, int size, int dir, const int r_size)
{
	int k = size, a = low;

	if (size > 1)
	{
		k = size / 2;

		for (a = low; a < low + k; a++)
			_swap(array, a, a + k, dir);

		bitonic_merge(array, low, k, dir, r_size);
		bitonic_merge(array, low + k, k, dir, r_size);
	}
}
/**
 * _sort - segmentate the array
 * @array: The array to sort
 * @low: The lowest element in each range
 * @size: Size of the range to sort
 * @dir:  directory Indicate which half are manage
 * @r_size: The size of the all array
 * Return: Null
 */
void _sort(int *array, int low, int size, int dir, const int r_size)
{
	int k = size;

	if (size > 1)
	{
		if (dir == 1)
			printf("Merging [%d/%d] (UP):\n", size, r_size);
		if (dir == 0)
			printf("Merging [%d/%d] (DOWN):\n", size, r_size);
		printcheck(array, low, low + k - 1);

		k = size / 2;
		_sort(array, low, k, 1, r_size);

		_sort(array, low + k, k, 0, r_size);

		bitonic_merge(array, low, size, dir, r_size);
		if (dir == 1)
		{
			printf("Result [%d/%d] (UP):\n", size, r_size);
			printcheck(array, low, low + 2 * k - 1);
		}
		if (dir == 0)
		{
			printf("Result [%d/%d] (DOWN):\n", size, r_size);
			printcheck(array, low, low + 2 * k - 1);
		}
	}
}
/**
 * bitonic_sort - call the sort function
 * @array: The array to sort
 * @size: Size of the array
 * Return: Nothing
 */
void bitonic_sort(int *array, size_t size)
{
	int up = 1;
	const int r_size = (int)size;

	if (size < 2 || !array)
		return;

	_sort(array, 0, (int)size, up, r_size);
}
