// At most  2 transactions:
// 2 traversals:
int buysell(vector<int> arr){
{
 int n=arr.size();
        if(n<=1){
            return 0;
        }
        int dp[n];
        dp[0]=0;
        int valley=arr[0];
        int peak=arr[n-1];    
        int ans=0;
        for(int i=1;i<n;i++){
            valley=min(valley,arr[i]);
            dp[i]=max(dp[i-1],arr[i]-valley);
        }
       
        for(int i=n-1;i>=0;i--){
            peak=max(peak,arr[i]);
            dp[i]=max(dp[i],dp[i]+peak-arr[i]);
            ans=max(dp[i],ans);
        }
        
        
        
         return ans;'
}  
//   1 traversal:
          int buysell(vector<int> arr){
   int n=arr.size();
        if(n<=1){
            return 0;
        }
        int dp[n];
        dp[0]=0;
        int valley=arr[0];
        int peak=arr[n-1];    
        int ans=0;
        for(int i=1;i<n;i++){
            valley=min(valley,arr[i]);
            dp[i]=max(dp[i-1],arr[i]-valley);
        }
       
        for(int i=n-1;i>=0;i--){
            peak=max(peak,arr[i]);
            dp[i]=max(dp[i],dp[i]+peak-arr[i]);
            ans=max(dp[i],ans);
        }
        
        
        
         return ans;
         
}      
