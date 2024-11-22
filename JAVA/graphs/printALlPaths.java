import java.util.ArrayList;
import java.util.Scanner;

public class printALlPaths {
    public static void printPaths(int src, int dest,ArrayList<Integer> graph[],String path)
    {
        if(src == dest)
        {
            System.out.println(path+dest);
            return;
        }
        for(int i = 0 ; i < graph[src].size() ; i++)
        {
            printPaths(graph[src].get(i), dest,graph, path+src);
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
        printPaths(5, 1, graph, "");
    }
}
