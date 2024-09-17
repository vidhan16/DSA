#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minimizeHeights(vector<int>&num,int k)
{
    sort(num.begin(),num.end());
    int smallest = num[0];
    int largest = num[num.size()-1];
    int ans = largest - smallest;
    for(int i = 1 ; i < num.size() ; i++)
    {
        largest = max(num[num.size()-1]-k,num[i-1]+k);
        smallest = min(num[0]+k,num[i]-k);

        if(smallest >= 0)
        {
            ans = min(ans,largest - smallest);
        }
    }
    return ans;
}
int main()
{
    vector<int>num = {3,9,12,16,20};
    int k = 3;
    cout<<minimizeHeights(num,k);
    return 0;
}