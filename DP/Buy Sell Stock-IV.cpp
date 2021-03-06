// O(N^3)
// Qs-You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

// Find the maximum profit you can achieve. You may complete at most k transactions.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

// Example 1:

// Input: k = 2, prices = [2,4,1]
// Output: 2
// Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.


 int maxProfit(int k, vector<int>& prices) {
      int n=prices.size();
        
        if(k==0)
            return 0;
        if(n<=1)
            return 0;
        
        
        
        int cost[k+1][n];
        for(int i=0;i<=k;i++){
            for(int j=0;j<n;j++){        
             cost[i][j]=0;   
            }
        }
        int maximum=0;
        for(int i=1;i<=k;i++){
            for(int j=1;j<n;j++){
                int max1=cost[i][j-1];
                for(int l=0;l<j;l++){
                    max1=max(max1,cost[i-1][l]+prices[j]-prices[l]);
                }
                cost[i][j]=max1;
                maximum=max(maximum,cost[i][j]);
            }    
            
        }
       return maximum; 
    }

//O(N^2)
 int maxProfit(int k, vector<int>& prices) {
      int n=prices.size();
        
        if(k==0)
            return 0;
        if(n<=1)
            return 0;
        
        
        
        int cost[k+1][n];
        for(int i=0;i<=k;i++){
            for(int j=0;j<n;j++){        
             cost[i][j]=0;   
            }
        }
        int maximum=0;
        for(int i=1;i<=k;i++){
          int  max1=INT_MIN;
            for(int j=1;j<n;j++){
                 max1=max(cost[i-1][j-1]-prices[j-1],max1);
                cost[i][j]=max(max1+prices[j],cost[i][j-1]);
            }    
            
        }
       return cost[k][n-1]; 
    }
Explanation: Comment:https://leetcode.com/parasanandjain/
