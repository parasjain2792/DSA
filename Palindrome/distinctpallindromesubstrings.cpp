//link:https://practice.geeksforgeeks.org/problems/distinct-palindromic-substrings5141/1#
//link:https://www.codingninjas.com/codestudio/problems/find-all-distinct-palindromic-substrings-of-a-given-string_1382054?leftPanelTab=2
// { Driver Code Starts
// C++ program to find all distinct palindrome sub-strings
// of a given string
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
  public:
  
    int palindromeSubStrs(string s) {
        // code here
        map<string,int> umap;
        int n=s.size();
        for(int i=0;i<n;i++){
            umap[s.substr(i,1)]++;
        }
        for(int i=0;i<n;i++){
            string s1="";
            int start=i-1;
            int end=i+1;
            //odd
            s1+=s[i];
            while(start>=0 && end<n && s[start]==s[end]){
                s1=s[start]+s1+s[end];
                umap[s1]++;
                start--;
                end++;
            }
            //even
            s1.clear();
            start=i;
            end=i+1;
            while(start>=0 && end<n && s[start]==s[end]){
                s1=s[start]+s1+s[end];
                umap[s1]++;
                start--;
                end++;
            }
        }
        int count=0;
        for(auto it=umap.begin();it!=umap.end();it++){
          // cout<<it->first<<endl;
            count++;
        }
        return count;
    }
};

// { Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.palindromeSubStrs(str) << endl;
    }
    return 0;
}
  // } Driver Code Ends
