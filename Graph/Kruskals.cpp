#include<bits/stdc++.h>
using namespace std;
class Edges{
    public:
    int source;
    int destination;
    int weight;
};
bool comparator(Edges a,Edges b){
    return a.weight<b.weight;
}
int getP(int *parents,int v,int num){
    while(parents[num]!=num){
        num=parents[num];
    }
    return num;
}
int main(){
    int t;
    cin>>t;
    while(t--){
               int e,v;
        cin>>v>>e;
        int* parents=new int[v];
        for(int i=0;i<v;i++){
            parents[i]=i;
        }
        Edges M[e];
        for(int i=0;i<e;i++){
            int s,d,w;
            cin>>s>>d>>w;
            M[i].source=s;
            M[i].destination=d;
            M[i].weight=w;
        }
        sort(M,M+e,comparator);
        //  for(int i=0;i<e;i++){
        //     cout<<M[i].source<<" "<<M[i].destination<<" "<<M[i].weight;
        //     cout<<endl;
        // }
        int count=0;
        int i=0;
        int sum=0;
       // cout<<"BREAK"<<endl;
        while(count<v-1 && i<e){
            Edges E=M[i];
            int val=getP(parents,v,E.source);
            int val2=getP(parents,v,E.destination);
            if(val!=val2){
                sum+=E.weight;
                count++;
                //cout<<E.source<<" "<<E.destination<<" "<<E.weight<<" "<<val<<" "<<val2<<endl;
                parents[val]=val2;
            }
            
            i++;
        }
        cout<<sum<<endl;
    }
    return 0;
}
