#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    stack<int> s;
    queue<int> st;
    for (int i = sandwiches.size() - 1; i >= 0; i--) s.push(sandwiches[i]);
    for (int i = 0; i < students.size(); i++) st.push(students[i]);
    int k = 0, num = st.size();
    while (k != num) {
        if (st.front() == s.top()) {
            st.pop();
            s.pop();
            k = 0;
            num--;
        } else {
            k++;
            int temp = st.front();
            st.pop();
            st.push(temp);
        }
    }
    return st.size();
}

int main() {
    vector<int> students = {1, 1, 0, 0};
    vector<int> sandwiches = {0, 1, 0, 1};
    cout << "Students unable to eat: " << countStudents(students, sandwiches) << endl;
    return 0;
}
