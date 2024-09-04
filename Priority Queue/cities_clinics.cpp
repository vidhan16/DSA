//Minimise the max load..

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    priority_queue<pair<int,int>>pq;
    vector<int>arr = {100,50,200};
    int m = 5;
    for(int i = 0 ; i < arr.size() ; i++)
    {
        pq.push({arr[i],1});
        m--;
    }

    while(m > 0)
    {
        int ele = pq.top().first;
        int count = pq.top().second;
        ele = (ele*count)/(++count);
        pq.pop();
        pq.push({ele,count});
        m--;
    }
    cout<<pq.top().first;
}