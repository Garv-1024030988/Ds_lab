#include <iostream>
#include<vector>

using namespace std;
vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }
            if (!st.empty()) {
                answer[i] = st.top() - i;
            }
            st.push(i);
        }
        return answer;
    }
int main () {
    vector<int> temperatures;
    cout<<"Enter numebr of Elements :";
    int n ;
    cin>>n;

    for(int i = 0 ; i < n ; i++){
        cout<<"Enter element :";
        int a ;
        cin>>a;
        temperatures.push_back(a);
    }
    vector<int>ans ;
    ans = dailyTemperatures(temperatures);

    for(int ele : ans){
        cout<<ele<<" ";
    }
    return 0;
}
