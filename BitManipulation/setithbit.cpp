#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
    
    // write your code here
    ll t;
    cin>>t;
   ll mod=1e9+7;
    while(t--){
        ll places,number;
        cin>>number>>places;
        ll temp=1<<places;
        number = number | temp;
        cout<<number<<endl;
    }
    return 0;
}
