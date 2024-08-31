//Combination Sum I
#include <iostream>
#include <vector>
using namespace std;

void combinationSum(vector<int>arr,int i,vector<int>&temp,int target)
{
    if(i == arr.size())
    {
        if(target == 0)
        {
            for(int j = 0 ; j < temp.size() ; j++)
            {
                cout<<temp[j]<<" ";
            }
            cout<<endl;
        }
        return;
    }

    if(arr[i] <= target)
    {
        temp.push_back(arr[i]);
        combinationSum(arr,i,temp,target-arr[i]);
        temp.pop_back();
    }
    combinationSum(arr,i+1,temp,target);
}
int main()
{
    vector<int>arr = {1,2,3,4};
    vector<int>temp;
    combinationSum(arr,0,temp,7);
}