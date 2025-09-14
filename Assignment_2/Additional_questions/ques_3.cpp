#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


bool anagramStrings(string& s,string t){
            if(s.length() != t.length()) return false;
			vector<int>frq(26,0);
            for(char ch: s){
                frq[ch-'a']++;
            }
            for(char ch: t){
                frq[ch-'a']--;
            }
            for(int count: frq){
                if(count != 0){
                    return false;
                }
            }
            return true;
       
		}

   int main(){
    string str1="hello";
    string str2="leloh";
    string bothanan=anagramStrings(str1,str2)? "Yes" : "No";
    cout<<"Are they both Anangrams?: "<<bothanan;
    return 0;
   }  
