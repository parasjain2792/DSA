/*Qs:BBS possible 
link:https://www.hackerrank.com/challenges/stockmax/submissions/code/234615157
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        
        long long n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++){
             cin>>arr[i];
         }
        long long max_val=0;
        long long peak=arr[n-1];
        for(int i=n-1;i>=0;i--){
            peak=max(peak,arr[i]);
            max_val+=peak-arr[i];
        }
        cout<<max_val<<endl;
    }
    return 0;
}
