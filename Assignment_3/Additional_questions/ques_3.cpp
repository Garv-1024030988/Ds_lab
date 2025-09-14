#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> nextLargerElement(vector<int> &nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> nle(n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }

            nle[i] = st.empty() ? -1 : st.top();
            st.push(nums[i]);
        }

        return nle;
    }

    void Display(const vector<int> &nums){
        for(int i=0; i<nums.size(); i++){
            cout<<nums[i]<<"\t";
        }
    }

     int main(){
        vector<int>arr={2,4,3,1,8,5,9,88};
        
        vector<int>nge=nextLargerElement(arr);

        Display(nge);
        return 0;
    }
