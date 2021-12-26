#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Edge{
    public:
    ll src;
    ll dest;
    ll weight;
};
const int INF=1e9;
void algo(ll v1,ll v2,Edge *E,ll v,ll e){
    ll weights[v+1];
    for(int i=0;i<=v;i++){
        weights[i]=INF;
    }
    weights[v1]=0;
    for(int i=0;i<v-1;i++){
        for(int j=0;j<e;j++){
            if( weights[E[j].src]!=INF && weights[E[j].dest]>weights[E[j].src]+E[j].weight){
                weights[E[j].dest]=weights[E[j].src]+E[j].weight;
            }
        }
    }
    cout<<weights[v2]<<endl;
    return ;
}
int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
         int e,v;
    cin>>v>>e;
    Edge *E=new Edge[e];
    
    ll v1,v2;
    cin>>v1>>v2;
    for(int i=0;i<e;i++){
        cin>>E[i].src>>E[i].dest>>E[i].weight;
    }
    algo(v1,v2,E,v,e);
    }
    return 0;
}
// #include <bits/stdc++.h> 
// using namespace std;
// class edge { 
//     public: int a, b, cost;
//     edge(int a, int b, int cost) { 
//         this->a = a; 
//         this->b = b; 
//         this->cost = cost; } };
// const int INF = 1e9;
// int solve(vector<edge> &e, int n, int m, int src, int des) { 
//     vector<int> d(n + 1, INF);
//     d[src] = 0; 
//     for (int i = 0; i < n - 1; ++i) { 
//         for (int j = 0; j < m; ++j) { 
//             if (d[e[j].a] < INF) {
//                 d[e[j].b] = min(d[e[j].b], d[e[j].a] + e[j].cost); } } }
//     return d[des]; } 
// int main() { int t; cin >> t;
//             while (t--) { 
//                 int n, m; cin >> n >> m; 
//                 int src, des; cin >> src>> des;
//                 vector<edge> e; for (int i = 0; i < m; i++) { 
//                     int a, b, cost; cin >> a >> b >> cost; e.push_back(edge(a, b, cost)); }
//                 int ans = solve(e, n, m, src, des); cout << ans << endl; } }
