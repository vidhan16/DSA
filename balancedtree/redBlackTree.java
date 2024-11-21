import java.util.LinkedList;
import java.util.Queue;

public class redBlackTree
{
    public class node {
        int data;
        node left;
        node right;
        int color;
        node(int data,int color)
        {
            this.data = data;
            this.left = null;
            this.right = null;
            this.color = color;
        }
    }

    private node rotateRight(node h)
    {
        node x = h.left;
        h.left = x.right;
        x.right = h;
        x.color = h.color;
        h.color = 0;
        return x;
    }

    private node rotateLeft(node h)
    {
        node x = h.right;
        h.right = x.left;
        x.left = h;
        x.color = h.color;
        h.color = 0;
        return x;
    }

    private node flipColors(node h)
    {
        h.color = 0;
        h.left.color = 1;
        h.right.color = 1;
        return h;
    }
    private node put(node h,int data,int color)
    {
        if(h == null) return new node(data,color);
        if(h.data > data)
        {
            h.left = put(h.left,data,color);
        }
        else if(h.data < data)
        {
            h.right = put(h.right,data,color);
        }

        if(h.left != null && h.left.left != null && h.left.color == h.left.left.color) h = rotateRight(h);
        else if(h.left != null && h.right != null && h.left.color == 1 && h.right.color == 0) // 0 stands for red and 1 stands for black
        {
            h = rotateLeft(h);
        }
        else if(h.left != null && h.right != null && h.left.color == 0 && h.right.color == 0) h = flipColors(h);
        return h;
    }
    public void levelOrder(node root)
    {
        Queue<node> q = new LinkedList<>();
        q.add(root);
        q.add(null);
        while(!q.isEmpty())
        {
            node front = q.remove();
            if(front == null)
            {
                System.out.println();
                if(!q.isEmpty())
                {
                    q.add(null);
                }
            }
            else
            {
                System.out.print(front.data+" "+front.color+"  ");
                if(front.left != null) q.add(front.left);
                if(front.right != null) q.add(front.right);
            }
        }

    }
    public static void main(String[] args)
    {
        redBlackTree r = new redBlackTree();
        node root = null;
        root = r.put(root, 10, 0); 
        root = r.put(root, 20, 0); 
        root = r.put(root, 5, 0);  
        root = r.put(root, 15, 0); 
        root = r.put(root, 25, 0);
        r.levelOrder(root);
    }
}