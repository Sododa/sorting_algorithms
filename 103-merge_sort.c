#include "sort.h"

/**
 * copy - copies data from one buffer to another
 *
 * @src: source buffer
 * @dst: destination buffer
 * @size: size of buffers
 * Return: null
 */
void copy(int *src, int *dst, int size)
{
	int a;

	for (a = 0; a < size; a++)
		dst[a] = src[a];
}
/**
 * merge - merges two sets of data in ascending order
 * but they must already be sorted before hand
 * @array: first set of data
 * @buff: second set of data
 * @minL: min range of first set of data
 * @maxL: max range of first set of data
 * @minR: min range of second set of data
 * @maxR: max range of second set of data
 * Return: Null
 */
void merge(int *array, int *buff, int minL, int maxL, int minR, int maxR)
{
	int a = minL, b = minR, c = minL;

	while (a <= maxL || b <= maxR)

		if (a <= maxL && b <= maxR)
			if (buff[a] <= buff[b])
				array[c] = buff[a], c++, a++;
			else
				array[c] = buff[b], c++, b++;

		else if (a > maxL && b <= maxR)
			array[c] = buff[b], c++, b++;
		else
			array[c] = buff[a], c++, a++;
}
/**
 * printcheck - prints an array in a given range
 *
 * @array: array of data to be print
 * @r1: start of range r1
 * @r2: end of range r2
 * Return: Null
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
 * split - recursive function to split data into merge tree
 *
 * @array: array of data to be split
 * @buff: auxiliary array of data for merging
 * @min: min range of data in array
 * @max: max range of data in array
 * @size: size of total data
 * Return: Null
 */
void split(int *array, int *buff, int min, int max, int size)
{
	int mid, tmax, minL, maxL, minR, maxR;

	if ((max - min) <= 0)
		return;

	mid = (max + min + 1) / 2;
	tmax = max;
	max = mid - 1;

	minL = min;
	maxL = max;

	split(array, buff, min, max, size);

	min = mid;
	max = tmax;

	minR = min;
	maxR = max;

	split(array, buff, min, max, size);

	printf("Merging...\n");
	printf("[left]: ");

	printcheck(array, minL, maxL);

	printf("[right]: ");

	printcheck(array, minR, maxR);
	merge(array, buff, minL, maxL, minR, maxR);
	copy(array, buff, size);

	printf("[Done]: ");
	printcheck(array, minL, maxR);
}
/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 *
 * @array: array of data to be sorted
 * @size: size of data
 *
 * Return: Null
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	copy(array, buff, size);

	split(array, buff, 0, size - 1, size);

	free(buff);
}
