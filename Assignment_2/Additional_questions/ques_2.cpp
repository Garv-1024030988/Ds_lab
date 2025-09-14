#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool canSplit(string &st){
    int n=st.length();

    if(n<3) return false;

    vector<int>freq(26,0);
    for(char c:st) freq[c-'a']++;
    for(int f : freq){
        if(f>=3) return true;
    }


    return false;
}


int main(){
    
    string s="ababa";
    cout<<(canSplit(s) ? "Yes" : "No");
    
    return 0;
}
