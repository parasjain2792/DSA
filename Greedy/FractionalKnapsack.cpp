//link:https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1#
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    #define ll long long
    //Function to get the maximum total value in the knapsack.
    static bool compare(Item a,Item b){
        double r1=((double)a.value)/((double)a.weight);
        double r2=((double)b.value)/((double)b.weight);
        return r1>r2;
        
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,compare);
        double final_value=0.0;
        ll cur_weight=0;
        for(int i=0;i<n;i++){
            if(cur_weight+arr[i].weight<=W){
                cur_weight+=arr[i].weight;
                final_value+=arr[i].value;
            }
            else{
                ll remain=W-cur_weight;
                final_value+=((double)arr[i].value/(double)arr[i].weight)*remain;
                break;
            }
        }
        return final_value;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends
