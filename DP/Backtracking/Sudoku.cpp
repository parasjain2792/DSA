// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find a solved Sudoku.
   bool horizontal(int A[9][9],int row,int col,int value){
    for(int i=0;i<9;i++){
        if(A[row][i]==value){
            return false;
        }
        if(A[i][col]==value)
            return false;
    }
    return true;
}
bool box(int A[9][9],int row,int col,int value){
    int rowstart=((row/3)*3);
    int colstart=((col/3)*3);
    for(int i=rowstart;i<rowstart+3;i++){
        for(int j=colstart;j<colstart+3;j++){
            if(A[i][j]==value){
                return false;
            }
        }
    }
    return true;
}
bool check(int A[9][9],int row,int col,int value){
    if(horizontal(A,row,col,value) && box(A,row,col,value)){
        return true;
    }
    return false;
}
bool helper(int A[9][9],int row,int col){
    if(row==8 && col==8){
        for(int i=1;i<=9;i++){
            if(check(A,row,col,i)){
            A[row][col]=i;
            return true;
            }
        }
        return true;
    }
    if(col==9){
        row++;
        col=0;
    }
    if(A[row][col]!=0){
        return helper(A,row,col+1);
    }
    for(int val=1;val<=9;val++){
        if(check(A,row,col,val)){
            A[row][col]=val;
            if(helper(A,row,col+1))
                return true;
           A[row][col]=0; 
        }
    }
    return false;
}
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        if(helper(grid,0,0)){
        return true;
        }
        else
        return 0;
        
    }
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<grid[i][j]<<" ";
            }
        }
        
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends
