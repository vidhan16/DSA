void swap(int *a, int *b)
{
	int temp  = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(int *arr,int size)
{
	for(int i = 0 ; i < size ; i++)
	{
		for(int j = i + 1 ; j < size ; j++)
		{
			if(arr[i] > arr[j])
			{
				swap(&arr[i],&arr[j]);
			}
		}
	}
}

void merge(int *arr, int *aux, int left, int mid, int right)
{
	for(int i = left ; i <= right ; i++)
	{
		aux[i] = arr[i];
	}

	int j = left;
	int k = mid + 1;

	for(int i = left ; i <=right ; i++)
	{
		if(j > mid)
		{
			arr[i] = aux[k++];
		}
		else if(k > right)
		{
			arr[i] = aux[j++];
		}
		else if(aux[j] < aux[k])
		{
			arr[i] = aux[j++];
		}
		else
		{
			arr[i] = aux[k++];
		}
	}
}

void mergeSortRecursive(int *arr, int *aux, int left, int right)
{
	if(left >= right)
	{
		return;
	}
	int mid = left + (right - left)/2;
	mergeSortRecursive(arr,aux,left,mid);
	mergeSortRecursive(arr,aux,mid+1,right);
	merge(arr,aux,left,mid,right);
}

void mergeSort(int *arr,int size)
{
	int aux[size];
	int left = 0;
	int right = size - 1;
	mergeSortRecursive(arr,aux,left,right);
}
