#include<iostream>
#include<queue>
using namespace std;
void interleave(queue<int> & q){
    if(q.size() % 2 != 0){
        cout<<"The number of elements in the queue must be even ";
        return ;
    }
    int mid = q.size() / 2;
    queue<int> q1 ;

    for(int i = 0 ; i < mid ; i++){
        q1.push(q.front());
        q.pop();
    }
     while (!q1.empty()) {
        q.push(q1.front());
        q1.pop();

        q.push(q.front());         
        q.pop();
    }
}
int main (){
    queue <int> q;
    cout<<"Enter number of element in queue :";
    int n;
    cin>>n;
    cout<<"enter the elemenst : ";
    for(int i = 0 ; i < n ; i++){
        int a ;
        cin>>a;
        q.push(a);
    }

    interleave(q);

    cout << "Interleaved queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}
