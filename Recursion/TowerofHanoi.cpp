//Link:https://practice.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1#
// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    #define ll long long
    long long toh(int N, int from, int to, int aux) {
        // Your code here
        if(N==1){
        cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
        return 1;
    }
    ll val=toh(N-1,from,aux,to)+1;
    cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
    val+=toh(N-1,aux,to,from);
    return val;
    }

};

// { Driver Code Starts.

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}


//Position this line where user code will be pasted.  // } Driver Code Ends
