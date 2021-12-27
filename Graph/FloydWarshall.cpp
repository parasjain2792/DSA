#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
void algo(int** dist,int v){
    for(int k=1;k<=v;k++){
        for(int i=1;i<=v;i++){
            for(int j=1;j<=v;j++){
                if(dist[i][k]!=INF && dist[k][j]!=INF && dist[i][j]>dist[i][k]+dist[k][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--){
            int v,e;
    cin>>v>>e;
   // int** edges=new int*[v];
    int** dist=new int*[v+1];
    for(int i=1;i<=v;i++){
        //edges[i]=new int[v];
        dist[i]=new int[v+1];
        for(int j=1;j<=v;j++){
            //edges[i][j]=INF;
            dist[i][j]=INF;
        }
    }
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
         c=(dist[a][b]!=INF)?min(dist[a][b],c):c;
        // edges[a][b]=c;
        // edges[b][a]=c;
        dist[a][b]=c;
        dist[b][a]=c;
    }
    algo(dist,v);
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        if(a==b){
            cout<<0<<endl;
        }
        else{
            cout<<dist[a][b]<<endl;
        }
    }
    }
    return 0;
}
