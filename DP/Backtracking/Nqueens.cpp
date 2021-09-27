#include<bits/stdc++.h>
using namespace std;
void printNqueens(int n,int queens[10][10]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<queens[i][j]<<" ";
        }
    }
    cout<<endl;
    return;
}
bool check(int queens[10][10],int i,int j,int n){
    if(n==0)
        return true;
    //vertical
   for(int row=i-1;row>=0;row--){
       if(queens[row][j]==1)
           return false;
   }
   for(int row=i+1;row<n;row++)
   {
       if(queens[row][j])
           return false;
   }
    //left-diagonal
    int row=i+1;
    int c=j+1;
    while(row<n && c<n){
        if(queens[row++][c++])
            return false;
        
    }
    //left diagonal
    row=i-1;
    c=j-1;
    while(row>=0 && c>=0){
        if(queens[row--][c--])
            return false;
    }
    //right diagonal
    row=i-1;
    c=j+1;
    while(row>=0 && c<n){
        if(queens[row--][c++]){
            return false;
        }
    }
    row=i+1;
    c=j-1;
    while(row<n && c>=0){
        if(queens[row++][c--])
            return false;
    }
    
    return true;    
    
}
void backtrack(int n,int queens[10][10],int row){
   if(row==n){
       printNqueens(n,queens);
       return ;
   }
    
    for(int i=0;i<n;i++){
        if(check(queens,row,i,n)){
            queens[row][i]=1;
            backtrack(n,queens,row+1);
            queens[row][i]=0;
        }
        
    }
  //  cout<<"yaya";
return ;
       
    
    
}
int main(){
    
    // write your code here
    int n;
    cin>>n;
    int queens[10][10]={0};
    
     backtrack(n,queens,0);
    
    
    return 0;
}
