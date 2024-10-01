#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i = 0 ; i < m ; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool>arr(n+1);//1 based indexing
    arr[1]=1;
    queue<int>q;
    q.push(1);
    vector<int>bfs;
    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        bfs.push_back(front);
        for(int i = 0 ; i < adj[front].size() ; i++)
        {
            if(!arr[adj[front][i]])
            {
                arr[adj[front][i]]=1;
                q.push(adj[front][i]);
            }
        }
    }
    for(int i = 0 ; i < bfs.size() ; i++)
    {
        cout<<bfs[i]<<" ";
    }
}