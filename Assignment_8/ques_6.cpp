#include <bits/stdc++.h>
using namespace std;
class priorityQueue
{
    int idx;
    int arr[100];

public:
    priorityQueue() : idx(1) {}

    int top()
    {
        if (!size())
        {
            cout << "Empty" << endl;
            return -1;
        }
        return arr[1];
    }
    void push(int val)
    {
        arr[idx] = val;

        int i = idx;
        idx++;

        
        while (i > 1)
        {
            int p = i / 2;
            if (arr[p] > arr[i])
            {
                swap(arr[i], arr[p]);
                i = p;
            }
            else
                break;
        }
    }

    void pop()
    {
        if (!size())
            return;

        idx--;
        arr[1] = arr[idx];
        int i = 1;
        
        while(i<idx){
            int left=2*i;
            int right=2*i+1;
            int smallest=i;
            if(left<idx && arr[left]<arr[smallest]){
                smallest=left;
            }
            if(right<idx && arr[right]<arr[smallest]){
                smallest=right;
            }
            if(smallest!=i){
                swap(arr[i],arr[smallest]);
                i=smallest;
            }
            else break;
        }
    }
    void display(){
        if(!size()) return;
        for(int i=1;i<idx;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    int size()
    {
        return idx - 1;
    }
};

int main()
{
    priorityQueue pq;
    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(1);
    pq.push(4);
    pq.display();
    pq.pop();
    pq.display();
    pq.push(-1);
    pq.push(100);
    pq.display();
    pq.pop();pq.pop();pq.pop();
    pq.display();
    pq.pop();
    pq.pop();pq.display();
    return 0;
}
