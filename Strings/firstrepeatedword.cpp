// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        unordered_map<string,int> umap;
        for(int i=0;i<n;i++)
       {
           umap[arr[i]]++;
    
        }       
        int max=INT_MIN;
        int smax=INT_MIN;
        string mans="";
        string ans="";
        for(auto itr:umap){
            if(max<itr.second){
                smax=max;
            max=itr.second;
            ans=mans;
            mans=itr.first;
                
                
            }
            else if(smax<itr.second){
                smax=itr.second;
                ans=itr.first;
                
            }
        }
        
        
       return ans; 
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends
