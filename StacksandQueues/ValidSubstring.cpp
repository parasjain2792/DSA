//link:https://practice.geeksforgeeks.org/problems/valid-substring0624/1#
// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        stack<int > s1;
        s1.push(-1);
        int ans1=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                s1.push(i);
            }
            else{
                s1.pop();
                if(s1.empty()){
                    s1.push(i);
                }
                else{
                    int ans2=i-s1.top();
                    ans1=max(ans2,ans1);
                }
            }
            
        }
        return ans1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}
  // } Driver Code Ends
