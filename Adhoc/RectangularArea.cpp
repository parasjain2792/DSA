/*
Rectangular Area
Send Feedback
You are given N rectangles, which are centered in the center of the Cartesian coordinate system and their sides are parallel to the coordinate axes. 
Each rectangle is uniquely identified with its width (along the x-axis) and height (along the y-axis). 
Navdeep has coloured each rectangle in a certain colour and now wants to know the area of the coloured part of the paper. 
Please refer to the sample test case 1 and image used in it for better understanding.
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    ll arr[n];
    unordered_map<ll,ll> umap;
    for(ll i=0;i<n;i++){
        ll side,num;
        cin>>num>>side;
        arr[i]=side;
        if(umap[side]<num/2)
        umap[side]=num/2;
        else if(umap.count(arr[i])==0){
            umap[side]=num/2;
        }
        
    }
    sort(arr,arr+n,greater<int>());
    // for(auto i:umap){
    //     cout<<i.first<<":"<<i.second<<endl;
    // }
    ll area=0;
    ll sum=0;
    for(int i=0;i<n;i++){
        if(sum<umap[arr[i]]){
            area+=(umap[arr[i]]-sum)*arr[i];
            sum+=(umap[arr[i]]-sum);
            
        }
    }
    cout<<area*2<<endl;
    return 0;
}
