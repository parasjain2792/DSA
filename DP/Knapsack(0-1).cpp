// Q-You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. 
// Note that we have only one quantity of each item.
int knapSack(int W, int wt[], int val[], int N) 
    { 
       // Your code here
       int dp[2][W+1];
       for(int i=0;i<2;i++){
           for(int  j=0;j<=W;j++)
           dp[i][j]=0;
       }
       
       
       
      int count=0;
      
       for(int i=0;i<N;i++){
           int row=(count%2)?1:0;
           int alternate=!(row);
        for(int j=1;j<=W;j++){
            if(wt[count]>j)
            {
                dp[row][j]=dp[alternate][j];
                
            }
            else
            dp[row][j]=max(dp[alternate][j-wt[i]]+val[i],dp[alternate][j]);
            
        }   
           count++;
           
       }
       
       int finalrow=!(N%2);
       
      return dp[finalrow][W];
       
       
    }
