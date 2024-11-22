import java.util.*;
public class topoSortBFS {
    public static void calcIndeg(ArrayList<Integer> graph[],int indeg[])
    {
        for(int i = 0 ; i < graph.length ; i++)
        {
            for(int j = 0 ; j < graph[i].size() ; j++)
            {
                indeg[graph[i].get(j)]++;
            }
        }
    }
    public static void topoSort(ArrayList<Integer> graph[])
    {
        Queue<Integer> q = new LinkedList<>();
        int[] indeg = new int[graph.length];
        calcIndeg(graph,indeg);

        for(int i = 0 ; i < graph.length ; i++)
        {
            if(indeg[i] == 0)
            {
                q.add(i);
            }
        }

        while(!q.isEmpty())
        {
            int front = q.remove();
            System.out.print(front+" ");
            for(int i = 0 ; i < graph[front].size() ; i++)
            {
                indeg[graph[front].get(i)]--;
                if(indeg[graph[front].get(i)] == 0)
                {
                    q.add(graph[front].get(i));
                }
            }
        }
    }
    public static void main(String[] args)
    {
        int n,m;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        ArrayList<Integer>[] graph = new ArrayList[n];
        for(int i = 0 ; i < n ; i++)
        {
            graph[i] = new ArrayList<>();
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
