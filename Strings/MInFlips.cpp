//link:https://practice.geeksforgeeks.org/problems/min-number-of-flips3210/1
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends

int count(string s,char c,int index){
    int n=s.size();
    int start=index;
    int count=0;
    while(start<n){
        if(s[start]!=c){
            count++;
        }
        start=start+2;
    }
    return count;
}
int minFlips (string s)
{
    // your code here
    int count1=count(s,'1',0);
    int count0=count(s,'0',0);
    int s1=count(s,'1',1);
    int s0=count(s,'0',1);
    return min(s1+count0,s0+count1);
}
