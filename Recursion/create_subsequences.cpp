#include <iostream>
#include <vector>
using namespace std;
void create_subsequences(vector<int>arr,vector<int>temp,int i)
{
    if(i == arr.size())
    {
        for(int j= 0 ; j < temp.size() ; j++) cout<<temp[j]<<" ";
        cout<<endl;
        return;
    }
    temp.push_back(arr[i]);
    create_subsequences(arr,temp,i+1);
    temp.pop_back();
    create_subsequences(arr,temp,i+1);
}
int main()
{
    vector<int>arr = {1,3,2,4,5,6};
    vector<int>temp;
    create_subsequences(arr,temp,0);
}