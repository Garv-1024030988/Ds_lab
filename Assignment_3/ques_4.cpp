#include <iostream>
#include <stack>
using namespace std;


int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3; 
    return 0;
}


bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}


bool isLetter(char c) {
    return ( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') );
}


bool isDigit(char c) {
    return (c >= '0' && c <= '9');
}

bool isOperandChar(char c) {
    return isLetter(c) || isDigit(c) || c == '_';
}


string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";

    for (size_t i = 0; i < infix.length(); i++) {
        char c = infix[i];

  \
        if (isOperandChar(c)) {
            string token = "";
            while (i < infix.length() && isOperandChar(infix[i])) {
                token += infix[i];
                i++;
            }
            i--; 
            postfix += token + " ";
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                postfix += " ";
                st.pop();
            }
            if (!st.empty()) st.pop(); 
        }
        else if (isOperator(c)) {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                if (c == '^' && st.top() == '^') break; 
                postfix += st.top();
                postfix += " ";
                st.pop();
            }
            st.push(c);
        }
    }

    
    while (!st.empty()) {
        postfix += st.top();
        postfix += " ";
        st.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter expression: ";
    getline(cin, infix);

    cout << "Postfix Expression: " << infixToPostfix(infix) << endl;

    return 0;
}
