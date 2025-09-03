#include <iostream>
#include <stack>
using namespace std;

bool isDigit(char c) {
    return (c >= '0' && c <= '9');
}


int evaluatePostfix(string postfix) {
    stack<int> st;

    for (int i = 0; i < (int)postfix.length(); i++) {
        char c = postfix[i];

        if (c == ' ') continue;

        if (isDigit(c)) {
            int num = 0;
            while (i < (int)postfix.length() && isDigit(postfix[i])) {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            i--; 
            st.push(num);
        }
        else {
            
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();

            switch (c) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
                case '^': {
                    int result = 1;
                    for (int j = 0; j < val2; j++) result *= val1;
                    st.push(result);
                    break;
                }
            }
        }
    }

    return st.top();
}

int main() {
    string postfix;
    cout << "Enter a Postfix Expression: ";
    getline(cin, postfix);

    cout << "Result = " << evaluatePostfix(postfix) << endl;

    return 0;
}
