//link:https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    #define ll long long
    static bool compare(struct Job a,Job b){
        return a.profit>b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,compare);
        ll count=0;
        ll profit=0;
        int n2=0;
        for(int i=0;i<n;i++){
            n2=max(n2,arr[i].dead);
        }
        int done[n2];
        for(int i=0;i<n2;i++){
            done[i]=-1;
        }
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead;j>=0;j--){
                if(done[j-1]==-1){
                    profit+=arr[i].profit;
                    done[j-1]=arr[i].id;
                    count++;
                    break;
                }
            }
        }
        vector<int> ans;
        ans.push_back(count);
        ans.push_back(profit);
        return ans;
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends
