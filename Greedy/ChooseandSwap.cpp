//link:https://practice.geeksforgeeks.org/problems/choose-and-swap0531/1
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
#define ll long long
    string chooseandswap(string a){
        // Code Here
    ll arr[26]={0};
    int min_val=26;
    for(int i=0;i<a.size();i++){
        arr[a[i]-'a']=true;
       // min_val=min(min_val,a[i]-'a');
    }
    char first,second;
    for(int i=0;i<a.size();i++){
    int flag=0;
         if(arr[a[i]-'a']){
             for(int j=0;j<a[i]-'a';j++){
             if(arr[j]==true){
                 second='a'+j;
                first=a[i];
                flag=1;
                break;
             }
         }
         
         }
         if(flag==1){
             break;
         }
         arr[a[i]-'a']=false;
    }
    for(int i=0;i<a.size();i++){
        if(a[i]==first){
            a[i]=second;
        }
        else if(a[i]==second){
            a[i]=first;
        }
    }
    return a;
    }
    
};


// { Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
  // } Driver Code Ends
