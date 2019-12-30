#include <stdio.h>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#define MAX_ARRAY 100
//void quick_sort(int *base, size_t nmemb, size_t size, int(*compr) (const int *, const int *));
void swap_numbers(int *, int *);
int *quick_sort(int *, int, int);
int partition(int *, int, int);
void print_array(int *, int);
int RNG();
void check(int[]);
int compare_func(int *, int *);

int main()
{
	srand(time(0));
	int array[MAX_ARRAY];
	for (int i = 0; i < MAX_ARRAY; i++)
		array[i] = RNG();
	int size_input = sizeof(array) / sizeof(array[0]);
	int *sorted_array = quick_sort(array, 0, size_input - 1);
	printf("Sorted Array: ");
	print_array(sorted_array, size_input);
	check(sorted_array);
	return 0;
}

int RNG()
{
	return rand() % 100000;
}

void swap_numbers(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int *array, int ln, int hn)
{
	int pivot = *(array + hn);//int pivot = array[hn];
	int low_index = ln - 1;

	for (int compare = ln; compare < hn; compare++)
		if (*(array + compare) <= pivot)//if (array[compare] <= pivot)
		{
			low_index++;
			swap_numbers(&*(array + low_index), &*(array + compare)); //swap_numbers(&array[low_index], &array[compare]); 
		}
	swap_numbers(&*(array + (low_index + 1)), &*(array + hn));//swap_numbers(&array[low_index + 1], &array[hn]);
	return low_index + 1;
}

int* quick_sort(int *array, int ln, int hn)
{
	if (ln >= hn)
		return array;
	else
	{
		int part = partition(array, ln, hn);
		quick_sort(array, ln, part - 1);
		quick_sort(array, part + 1, hn);
	}
}

void print_array(int *array, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", *(array + i));
	printf("\n");
	return;
}

void check(int *array)
{
	for (int i = 0; i < MAX_ARRAY - 1; i++)
		if (*(array + i) > *(array + (i + 1)))
		{
			printf("\ni = %d\t\tarray[i] = %d\t\tarray[i] + 1%d\n\nERROR\n", i, array[i], array[i + 1]);
			return;
		}
	printf("Correct - no error\n");
	return;
}

int compare_func(int *a, int *pivot)
{
	if (a > pivot)
		return 1;
	else if (a < pivot)
		return -1;
	return 0;
}