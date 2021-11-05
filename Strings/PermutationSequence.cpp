//link:https://leetcode.com/problems/permutation-sequence/submissions/
class Solution {
public:
    int factorial(int n){
       int ans=1;
        while(n>1){
            ans*=n;
            n--;
        }
        return ans;
    }
    string helper(string s,int k){
        if(s.size()==1){
            
            return s;
        }
        int m=s.size();
        int count=factorial(m-1);
        int rank=k/count;
        int residual=k%count;
        string s1=s.substr(0,rank)+s.substr(rank+1,m-rank);
        string ans=s[rank]+helper(s1,residual);
      //  cout<<ans<<s1<<endl;
        return ans;
    }
    string getPermutation(int n, int k) {
        string s="";
        for(int i=1;i<=n;i++){
            s+=to_string(i);
        }
        return helper(s,k-1);
    }
};
