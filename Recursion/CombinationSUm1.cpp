//link:https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1
// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int>> ans;
    void  helper(vector<int> num,vector<int> ans1,int B,int index){
        if(B==0){
            //sort(ans1,ans1+n);
            ans.push_back(ans1);
            return ;
        }
        if(B<0 || index>=num.size()){
            return ;
        }
      ans1.push_back(num[index]);
      helper(num,ans1,B-num[index],index);
      ans1.pop_back();
        helper(num,ans1,B,index+1);
        return ;
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        vector<int> sample;
        sort(A.begin(),A.end());
        vector<int> num;
        int count=0;
        int n=A.size();
        for(int i=0;i<n;){
            int j=i;
            while(j<n && A[i]==A[j]){
                j++;
            }
           // cout<<A[i];
            num.push_back(A[i]);
            i=j;
        }
       // cout<<num.size();
        helper(num,sample,B,0);
        //cout<<ans.size();
        return ans;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends
