#include <iostream>
#include <stack>
using namespace std;

string rev(const string &str) {
    stack<char> s;
    string reversed = "";

   
    for (char c : str) {
        s.push(c);
    }

    
    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }
    return reversed;
}

int main() {
    string str = "HOLA";
    
    cout << rev(str) << endl;
    return 0;
}
