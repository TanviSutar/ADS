#include<iostream>
#include<vector>
#define ll long long
using namespace std;

vector<ll> graph[100000];
vector<ll> weight[100000];

void addedge(ll u,ll v,ll w){
    graph[u].push_back(v);
    graph[v].push_back(u);
    weight[u].push_back(w);
    weight[v].push_back(w);
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,q,r;
        cin>>n>>q>>r;
        ll n1 = n-1;
        ll u,v,w;
        while(n1--){
            cin>>u>>v>>w;
            addedge(u,v,w);
        }
        cout<<weight[u][1];
    }
    return 0;
}