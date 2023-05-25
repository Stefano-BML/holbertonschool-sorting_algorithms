#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size <= 1)
        return;

    quicksort_recursive(array, 0, size - 1);
}

/**
 * quicksort_recursive - Recursive function to perform Quick sort.
 *
 * @array: Pointer to the array to be sorted.
 * @low: Index of the low element of the partition.
 * @high: Index of the high element of the partition.
 */
void quicksort_recursive(int *array, int low, int high)
{
    if (low < high)
    {
        int pivot = lomuto_partition(array, low, high);
        quicksort_recursive(array, low, pivot - 1);
        quicksort_recursive(array, pivot + 1, high);
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
            if (i != j)
            {
                swap(&array[i], &array[j]);
                print_array(array, high + 1);
            }
        }
    }

    if ((i + 1) != high)
    {
        swap(&array[i + 1], &array[high]);
        print_array(array, high + 1);
    }

    return (i + 1);
}

/**
 * swap - Swaps two integers.
 *
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
