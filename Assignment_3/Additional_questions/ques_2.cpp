
#include<iostream>
using namespace std;

class MinStack {
    stack<int> st;
    int mini;

   public:
    MinStack() { 
        mini = INT_MAX; 
    }

    void push(int value) {
        if (st.empty()) {
            st.push(value);
            mini = value;
        }

        else if (value > mini) {
            st.push(value);
        }

        else {
            st.push(2 * value - mini);
            mini = value;
        }
    }

    void pop() {
        if(st.size()==1){
            mini= -1;
            st.pop();
        }
        else{
        int x = st.top();
        st.pop();
        if (x < mini) {
            mini = 2 * mini - x;
        }
    }
    }

    int top() {
        if (st.top() > mini) {
            return st.top();
        }

        return mini;
    }

    int getMin() { 
        return mini; 
    }
};


int main(){
    MinStack st;
    st.push(4);
    st.push(7);
    st.push(3);
    st.push(2);
    st.pop();
    cout<<st.getMin()<<endl;
    st.pop();
    cout<<st.getMin()<<endl;
    st.pop();
    cout<<st.getMin()<<endl;
    st.pop();
    cout<<st.getMin()<<endl;
    
    return 0;
}
