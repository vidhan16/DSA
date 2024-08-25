#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr, j, j + 1);
        }
    }
}

void test_simple_input()
{
  int input[] = {5, 3, 1, 9, 7};
  printf("Unsorted array : ");
  int size = sizeof(input)/sizeof(input[0]);
  for(int i = 0 ; i < size ; i++) printf("%d ",input[i]);
  printf("\n");
  bubbleSort(input, 5);
  printf("Sorted array : ");
  for(int i = 0; i < 5; i++) printf("%d ",input[i]);
}

long long time_elapsed(int n)
{
  int *arr = (int *) malloc(n * sizeof(int));

  srand(time(NULL));
  for(int i = 0; i < n; i++) arr[i] = rand();

  struct timeval before;
  gettimeofday(&before, NULL);
  long long before_millis = before.tv_sec*1000LL + before.tv_usec/1000;

  bubbleSort(arr, n);

  struct timeval after;
  gettimeofday(&after, NULL);
  long long after_millis = after.tv_sec*1000LL + after.tv_usec/1000;

  return after_millis-before_millis;
}
int main() {
    test_simple_input();

    return 0;
}