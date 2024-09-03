#include <iostream>
#include <vector>
using namespace std;

class pq{
    public:
    int n;
    int *arr;
    pq(int c){
        arr = new int[c+1];
        n = 0;
        arr[0] = 0;
    }

    void swim(int in)
    {
        while((in > 1) && (arr[in/2] < arr[in]))
        {
            swap(arr[in/2],arr[in]);
            in = in / 2;
        }
    }
    void insert(int ele)
    {
        arr[++n] = ele;
        swim(n);
    }
    
    void sink(int in)
    {
        while((2 * in) < n)
        {
            int j = 2*in;
            if(arr[j] < arr[j+1]) j++;
            if(arr[j] > arr[in])
            {
                swap(arr[in],arr[j]);
                in = j;
            }
            else return;
        }
    }

    void delMax()
    {
        if(isEmpty()){
            cout<<"No elements present"<<endl;
            return;
        }
        arr[1] = arr[n--];
        sink(1);
    }
    int top()
    {
        return arr[1];
    }

    bool isEmpty()
    {
        if(n == 0) return 1;
        return 0;
    }
};
using namespace std;
int main()
{
    pq pq1(10);
    pq1.insert(1);
    pq1.insert(2);
    pq1.insert(3);
    pq1.insert(4);
    cout<<pq1.top()<<endl;
    pq1.delMax();
    cout<<pq1.top()<<endl;
}