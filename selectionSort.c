#include <stdio.h>
#include<stdlib.h>
void swap(int arr[],int a,int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
long long getTimeElapsed(int n){
    srand(time(NULL));
    int *arr = (int*)malloc(n * sizeof(int));
    for(int i=0;i<n;i++){
        arr[i]=rand();
    }
    selectionSort(arr,n);
}
void selectionSort(int arr[],int size){
    for(int i = 0 ; i < size; i++){
        int min = i;
        for(int j = i+1 ; j < size ; j++){
            if(arr[j]<arr[i]){
                min = j;
            }
        }
        swap(arr,i,min);
    }
}
int main(){
    int arr[] = {2,4,3,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr,size);
    for(int i = 0 ; i < size ; i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}