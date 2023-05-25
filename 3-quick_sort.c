#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm (Lomuto partition scheme).
 *
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	recursive_quick_sort(array, 0, size - 1);
}

/**
 * recursive_quick_sort - Recursively sorts a partition of the array using
 *                        the Quick sort algorithm (Lomuto partition scheme).
 *
 * @array: Pointer to the array to be sorted.
 * @low: Index of the low element of the partition.
 * @high: Index of the high element of the partition.
 */
void recursive_quick_sort(int *array, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high);
		recursive_quick_sort(array, low, pivot - 1);
		recursive_quick_sort(array, pivot + 1, high);
	}
}

/**
 * lomuto_partition - Partitions the array using Lomuto partition scheme.
 *
 * @array: Pointer to the array to be partitioned.
 * @low: Index of the low element of the partition.
 * @high: Index of the high element of the partition.
 *
 * Return: Index of the pivot element.
 */
int lomuto_partition(int *array, int low, int high)
{
	int pivot, i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, high + 1);
		}
	}

	swap(&array[i + 1], &array[high]);
	print_array(array, high + 1);

	return (i + 1);
}
