#include <bits/stdc++.h>
using namespace std;

vector<int> nearestSmallerToLeft(vector<int>& A) {
    int n = A.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() >= A[i]) {
            st.pop();
        }
        ans[i] = (st.empty() ? -1 : st.top());
        st.push(A[i]);
    }

    return ans;
}

int main() {
    vector<int> A = {4, 5, 2, 10, 8};
    vector<int> res = nearestSmallerToLeft(A);

    for (int x : res) cout << x << " ";
    return 0;
}
