//Count subsequences with given sum..

#include <iostream>
#include <vector>
using namespace std;
int count_subsequences(vector<int>arr,vector<int>temp,int sum,int i)
{
    if(i == arr.size())
    {
        int sum1 = 0;
        for(int j = 0 ; j < temp.size() ; j++) sum1+=temp[j];
        if(sum1 == sum) return 1;
        return 0;
    }

    temp.push_back(arr[i]);
    int in = count_subsequences(arr,temp,sum,i+1);
    temp.pop_back();
    int no = count_subsequences(arr,temp,sum,i+1);

    return in + no;
}
int main()
{
    vector<int>arr = {1,2,3,4};
    vector<int>temp;
    int sum = 5;
    cout<<count_subsequences(arr,temp,sum,0);
}