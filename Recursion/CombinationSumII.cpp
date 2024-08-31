//Combination Sum II
#include <iostream>
#include <vector>
using namespace std;
void combinationSum(vector<int>arr,vector<int>&temp,int i,int target)
{
    if(target == 0)
    {
        for(int j = 0 ; j < temp.size() ; j++)
        {
            cout<<temp[j]<<" ";
        }
        cout<<endl;
        return;
    }

    for(int j = i ; j < arr.size() ; j++)
    {
        if((j > 0 && (arr[j] == arr[j-1])) || arr[j] > target)
        {
            break;
        }
        temp.push_back(arr[j]);
        combinationSum(arr,temp,j+1,target - arr[j]);
        temp.pop_back();
    }
}
int main()
{
    vector<int>arr = {1,2,3,4};
    vector<int>temp;
    int i = 0;
    int target = 6;
    combinationSum(arr,temp,i,target);
    return 0;
}