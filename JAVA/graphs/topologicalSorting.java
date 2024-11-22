import java.util.*;
public class topologicalSorting {
    public static void dfs(int node,ArrayList<Integer> graph[],boolean vis[],Stack<Integer> st)
    {
        vis[node] = true;
        for(int i = 0 ; i < graph[node].size() ; i++)
        {
            if(!vis[graph[node].get(i)])
            {
                dfs(graph[node].get(i),graph,vis,st);
            }
        }
        st.add(node);
    }
    public static void topoSort(ArrayList<Integer> graph[])
    {
        Stack<Integer>st = new Stack<>();
        boolean[] vis = new boolean[graph.length];
        for(int i = 1 ; i < graph.length ; i++)
        {
            if(!vis[i])
            {
                dfs(i,graph,vis,st);
            }
        }
        while(!st.empty())
        {
            System.out.print(st.peek()+" ");
            st.pop();
        }
    }
    public static void main(String[] args)
    {
        int n,m;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        ArrayList<Integer>[] graph = new ArrayList[n+1];
        for(int i = 0 ; i <= n ; i++)
        {
            graph[i] = new ArrayList<Integer>();
        }

        for(int i = 0 ; i < m ; i++)
        {
            int u,v;
            u = sc.nextInt();
            v = sc.nextInt();
            graph[u].add(v);
        }
        topoSort(graph);
    }
}
