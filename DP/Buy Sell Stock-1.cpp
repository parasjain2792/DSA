//Qs-1 transaction allowed peak approach      
int profit(vector<int> &arr)
{ 
       int n=arr.size(); 
        int profit=0;
        int peak=arr[n-1];
        
        for(int i=n-1;i>=0;i--){
            peak=max(peak,arr[i]);
            profit=max(profit,peak-arr[i]);
            
        }
        
        
        return profit;
        
     }
     
//      Another approach but here i am finding the valley i.e,minimum value
int profit(vector<int> &prices)
{
      int profit=0;
        int start=prices[0];
        for(auto price : prices){
            
            if(start>price){
            start=price;
            }
            else{
                int lprofit=price-start;
                profit=max(lprofit,profit);
                
            }
            
            
        }
        
        
        return (profit>0?profit:0);
     
}
