//finding articulation points using tarjan's algo
#include<bits/stdc++.h>
using namespace std;

void dfs(int curr, int root, vector<vector<int>> &adj, vector<int> &disc, vector<int> &low, vector<bool> &instk, map<int,bool> &ap, int &child){
    static int timer = 0;
    disc[curr] = low[curr] = timer++;
    instk[curr] = true;
    for(auto a: adj[curr]){
        if(disc[a] == -1){ //not visited yet (tree edge)
            if(curr == root) child++;
            dfs(a, root, adj, disc, low, instk, ap, child);
            low[curr] = min(low[curr], low[a]);
            if(curr != root){
                if(low[a] >= disc[curr]) //there is no backedge from this subtree to ancestor of curr 
                    ap[curr] = true;
            }
        }
        else if(instk[curr]) // already visited ancestor node
            low[curr] = min(low[curr], disc[a]);
    }
    if(curr == root and child > 1) ap[curr] = true;
    instk[curr] = false;
}

void tarjans(int n, vector<vector<int>> &adj){
    vector<int> disc(n, -1);
    vector<int> low(n, -1);
    vector<bool> instk(n, false);
    map<int,bool> ap;
    for(int i=0; i<n; i++){
        int child = 0;
        if(disc[i] == -1) //if not visited yet
            dfs(i, i, adj, disc, low, instk, ap, child);
    }

    if(ap.empty()){
        cout<<"No articulation points\n";
        return;
    }

    cout<<"Following are articulation points: ";
    for(auto a: ap) cout<<a.first<<" ";cout<<endl;
}

int main(){
    int n;//vertices numbering starts from 0 and ends at n-1
    cin>>n;
    int e;
    cin>>e;
    vector<vector<int>> adj(n);
    for(int i=0; i<e; i++){
        int n1, n2;
        cin>>n1>>n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
    tarjans(n, adj);
    return 0;
}