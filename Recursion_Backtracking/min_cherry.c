#include <stdio.h>
int min(int a,int b)
{
    if(a < b) return a;
    else return b;
}

int max(int a,int b)
{
    if(a > b) return a;
    else return b;
}
int isValid(int i, int j,int m,int n)
{
    if(i < 0 || j < 0 || i >= m || j >= n) return 0;
    return 1;
}
int minCherry(int arr[][4],int i,int j,int m,int n){

    if(i == m-1 && j == n-1) return arr[i][j];

    int choice1 = isValid(i+1,j,m,n);
    int choice2 = isValid(i,j+1,m,n);

    if(choice1 && choice2)
    {
        int choice1Valid = minCherry(arr,i+1,j,m,n);
        int choice2Valid = minCherry(arr,i,j+1,m,n);

        return arr[i][j] + min(choice1Valid, choice2Valid);
    }

    else if(choice1)
    {
        int choice1Valid = minCherry(arr,i+1,j,m,n);
        return arr[i][j] + choice1Valid;
    }

    return arr[i][j] + minCherry(arr,i,j+1,m,n);
}
int main()
{
    int arr[][4] = {{1,1,1,1},{1,0,0,1},{1,1,1,1},{0,0,0,1}};
    int m = 4;
    int n = 4;
    int i = 0;
    int j = 0;
    printf("%d",minCherry(arr,i,j,m,n));
}