#include <bits/stdc++.h>
using namespace std;

bool canBeSorted(vector<int>& A) {
    stack<int> S;
    int expected = 1;
    int n = A.size();
    int i = 0;

    while (i < n || !S.empty()) {
        if (!S.empty() && S.top() == expected) {
            S.pop();
            expected++;
        } else if (i < n) {
            S.push(A[i]);
            i++;
        } else {
          
            break;
        }
    }

    return expected == n + 1;
}

int main() {
    vector<int> A = {2, 3, 1};
    cout << (canBeSorted(A) ? "yes" : "no") << endl;

    vector<int> B = {3, 1, 2};
    cout << (canBeSorted(B) ? "yes" : "no") << endl; 
}
