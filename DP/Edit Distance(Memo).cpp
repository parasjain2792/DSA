int eD(string s1,string s2,int n,int m,int **dp){    
        if(n==0)
            return m;
        if(m==0)
            return n;
        if(dp[n][m]!=-1)
            return dp[n][m];
        if(s1[n-1]==s2[m-1]){
            dp[n][m]=eD(s1,s2,n-1,m-1,dp);
            return dp[n][m];
        }
        
        dp[n][m]=1+min(eD(s1,s2,n-1,m-1,dp),min(eD(s1,s2,n-1,m,dp),eD(s1,s2,n,m-1,dp)));
        return dp[n][m];
    }
    int minDistance(string s1, string s2) {
        int n1=s1.size()+1;
        int n2=s2.size()+1;
        int **dp=new int*[n1];
        for(int i=0;i<n1;i++){
           dp[i]=new int[n2];
        }
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                dp[i][j]=-1;
            }
        }
        dp[n1-1][n2-1]=eD(s1,s2,n1-1,n2-1,dp);
        return dp[n1-1][n2-1];
    }
int main(){
 string s1;
  string s2;
  cin>>s1>>s2;
  cout<<minDistance(s1,s2);
}
