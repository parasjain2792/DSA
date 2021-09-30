// Qs:Given an array of integers and a target sum, determine the sum nearest to but not exceeding the target that can be created. 
// To create the sum, use any element of your array zero or more times.


#include<bits/stdc++.h>
using namespace std;
int main(){
    
int t;
cin>>t;
while(t--){
    
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bool arr2[k+1]={0};
    arr2[0]=1;
    sort(arr,arr+n);
   for(int i=0;i<n;i++){
       
        for(int j=arr[i];j<=k;j++){
        arr2[j]=!(j%arr[i])|| arr2[j]?1:0;
        arr2[j]=(arr2[j-arr[i]] || arr2[j])?1:0;
        
    }
       
       
   }
   int ans=0;
    for(int i=k;i>=0;i--){
       if(arr2[i]){
       ans=i;
       break;
       }
         
       
   }
   cout<<ans<<endl;
   
   
  
}   
    
   return 0; 
    
    
}
