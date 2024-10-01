#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
void swap(int arr[],int a,int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int func(int *arr,int low,int high)
{
    int i = low;
    int j = high;
    int pivot = low;
    while(i < j)
    {
        while(arr[i] <= arr[pivot] && i <= high)
        {
            i++;
        }

        while(arr[j] >= arr[pivot] && j >= low)
        {
            j--;
        }

        if(i < j) swap(arr,i,j);
    }
    return j;
}

void quickSortRecursive(int *arr,int low,int high)
{
    if(low < high)
    {
        int pIndex = func(arr,low,high);
        quickSortRecursive(arr,low,pIndex-1);
        quickSortRecursive(arr,pIndex+1,high);
    }
}

void quickSort(int *arr,int n)
{
    int low = 0;
    int high = n - 1;
    quickSortRecursive(arr,low,high);
}

void test_simple_input() {
    int arr[] = {2,4,3,1,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Unsorted array : ");
    for(int i = 0 ; i < size ; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    quickSort(arr,size);
    printf("Sorted array : ");
    for(int i = 0 ; i < size ; i++){
        printf("%d ",arr[i]);
    } 
    printf("\n");
}

long long time_elapsed(int n)
{
  int *arr = (int *) malloc(n * sizeof(int));

  srand(time(NULL));
  for(int i = 0; i < n; i++) arr[i] = rand();

  struct timeval before;
  gettimeofday(&before, NULL);
  long long before_millis = before.tv_sec*1000LL + before.tv_usec/1000;

  quickSort(arr, n);

  struct timeval after;
  gettimeofday(&after, NULL);
  long long after_millis = after.tv_sec*1000LL + after.tv_usec/1000;

  return after_millis-before_millis;
}
int main(){
    test_simple_input();

    // long long t1 = time_elapsed(32000);
    // long long t2 = time_elapsed(64000);
  
    // printf("%lf\n", t2*1.0/t1);
    return 0;
}