// Qs you can do any number of transactions but you should hold atmost 1 stock
// (peak-valley approach)O(N)

 int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        if(n==1)
            return 0;
        
        int maxprofit=0;
        int valley=prices[0];
        int peak=prices[0];
          int i=0;
          for(int i=0;i<n-1;){
              while(i<n-1 && prices[i]>=prices[i+1])
                  i++;
              valley=prices[i];
              while(i<n-1 && prices[i]<=prices[i+1])
                  i++;
              peak=prices[i];
              
              maxprofit+=(peak-valley);
              
          }
  
        return maxprofit;
    }
