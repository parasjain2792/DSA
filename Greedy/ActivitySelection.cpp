//Link:https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool compare(pair<int,int> a,pair<int,int> b){
        if(a.second<b.second){
            return true;
        }
        else if(a.second>b.second){
            return false;
        }
        else if((a.second-a.first)<(b.second-b.first))
        return true;
        else
        return false;
        
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        pair<int,int> arr[n];
        for(int i=0;i<n;i++){
            arr[i].first=start[i];
            arr[i].second=end[i];
        }
        sort(arr,arr+n,compare);
        int end_limit=arr[0].second;
        int count=1;
        for(int i=0;i<n;i++)
        {
            if(end_limit<arr[i].first){
                end_limit=arr[i].second;
                count++;
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends
