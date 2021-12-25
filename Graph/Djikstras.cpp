#include<bits/stdc++.h>
using namespace std;
int getminval(bool* visited,int* distance,int v){
   int minVertex=-1;
    for(int i=0;i<v;i++){
        if(!visited[i] && (minVertex==-1 || distance[i]<distance[minVertex])){
            minVertex=i;
        }
    }
    return minVertex;
}
void algo(int **edges,int v){
    bool* visited=new bool[v];
    int* distance=new int[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
        distance[i]=INT_MAX;
    }
    distance[0]=0;
    for(int i=0;i<=v-1;i++){
        int minval=getminval(visited,distance,v);
        visited[minval]=true;
       // cout<<minval;
        for(int j=0;j<v;j++){
            if(!visited[j] && edges[j][minval] && distance[j]>distance[minval]+edges[j][minval]){
                distance[j]=distance[minval]+edges[j][minval];
                // cout<<distance[j]<<" "<<j;
                // cout<<endl;
            }
        }
    }
    cout<<endl;
    for(int i=0;i<v;i++){
        cout<<i<<" "<<distance[i]<<endl;
    }
    return ;
}
int main(){
    int t;
    cin>>t;
    while(t--){
          int v,e;
    cin>>v>>e;
    int **edges=new int*[v];
    for(int i=0;i<v;i++){
        edges[i]=new int[v];
        for(int j=0;j<v;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int a,b,w;
        cin>>a>>b>>w;
        edges[a][b]=w;
        edges[b][a]=w;
    }
        algo(edges,v);
    }
    return 0;
}
