#include <stdio.h>
#include "vidhan_sort.h"

int main()
{
	int arr[] = {3,2,1};
	int n = 3;
	printf("Bubble Sort\n");

	printf("Before Sorting : ");
	for(int i = 0 ; i < n ; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	printf("After Sorting : ");
	bubbleSort(arr,n);
	for(int i = 0 ; i < n ; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");

	int arr1[] = {3,2,1,4,5};
	n = sizeof(arr1)/sizeof(arr1[0]);

	printf("Merge Sort : \n Before Sorting : ");
	for(int i = 0 ; i < n ; i++)
	{
		printf("%d ",arr1[i]);
	}

	printf("\nAfter Sorting : ");
	mergeSort(arr1,n);
	for(int i = 0 ; i < n ; i++)
	{
		printf("%d ",arr1[i]);
	}
	printf("\n");

	return 0;
}
