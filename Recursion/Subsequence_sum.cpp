//Return true or false if any subsequence is present having given sum..
#include <iostream>
#include <vector>
using namespace std;

bool subsequence_present(vector<int>arr,vector<int>temp,int sum,int i)
{
    if(i == arr.size())
    {
        int sum1 = 0;
        for(int j = 0 ; j < temp.size() ; j++) sum1+=temp[j];
        if(sum1 == sum) return true;
        return false;
    }

    temp.push_back(arr[i]);
    if(subsequence_present(arr,temp,sum,i+1) == true)
    {
        return true;
    }
    temp.pop_back();
    if(subsequence_present(arr,temp,sum,i+1) == true)
    {
        return true;
    }
    return false;
}
int main()
{
    vector<int>arr = {1,2,3,4};
    vector<int>temp;
    int sum = 1;
    cout << subsequence_present(arr,temp,sum,0);
}