#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void create_permutations(vector<int>arr,vector<int>&temp,unordered_map<int,int>&m)
{
    if(temp.size() == arr.size())
    {
        for(int j = 0 ; j < temp.size() ; j++)
        {
            cout<<temp[j]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int j = 0 ; j < arr.size() ; j++)
    {
        if(!m[j])
        {
            temp.push_back(arr[j]);
            m[j] = 1;
            create_permutations(arr,temp,m);
            temp.pop_back();
            m[j] = 0;
        }
    }
}

int main()
{
    vector<int>arr = {1,2,3};
    vector<int>temp;
    int i = 0;
    unordered_map<int,int>m;
    create_permutations(arr,temp,m);
}