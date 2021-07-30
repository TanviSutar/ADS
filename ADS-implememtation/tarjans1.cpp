//Tarjans algorithm for strongly connected components
#include<bits/stdc++.h>
using namespace std;

void dfs(int curr, vector<int> adj[], vector<int> &disc, vector<int> &low, vector<bool> &instk, stack<int> &stk, vector<vector<int>> &ans){
    static int timer = 0;
    disc[curr] = low[curr] = ++timer;
    instk[curr] = true;
    stk.push(curr);

    for(auto a: adj[curr]){
        if(disc[a] == -1){// not yet discovered (tree edge)
            dfs(a, adj, disc, low, instk, stk, ans);
            low[curr] = min(low[curr], low[a]);
        }
        else if(instk[a])// already discovered ancestor node (back edge)
            low[curr] = min(low[curr], disc[a]);
        else{} // may be already discovered or may not, but not an ancestor (cross edge)
    } 

    if(low[curr] == disc[curr]){//is it the head of the SCC
        vector<int> tmp;
        while(stk.top() != curr){
            tmp.push_back(stk.top());
            instk[stk.top()] = false;
            stk.pop();
        }
        tmp.push_back(stk.top());
        instk[stk.top()] = false;
        stk.pop();
        ans.push_back(tmp);
    }
}

vector<vector<int>> tarjans(int n, vector<int> adj[])
{
    vector<vector<int>> ans;
    vector<int> disc(n, -1);
    vector<int> low(n, -1);
    vector<bool> instk(n, false);
    stack<int> stk;

    for(int i=0; i<n; i++)
        if(disc[i] == -1)
            dfs(i, adj, disc, low, instk, stk, ans);
            
    //not a necessity to sort but did it anyways
    for(int i=0; i<ans.size(); i++)
        sort(ans[i].begin(), ans[i].end());
        
    sort(ans.begin(), ans.end());
    
    return ans;
}

int  main(){
    int n;//vertices numbering starts from 0 and ends at n-1
    cin>>n;
    int e;
    cin>>e;
    vector<int> adj[n];
    for(int i=0; i<e; i++){
        int n1, n2;
        cin>>n1>>n2;
        adj[n1].push_back(n2);
    }
    vector<vector<int>> vec = tarjans(n, adj);
    cout<<"Following are the SCC:\n";
    for(auto a: vec){
        for(auto b: a)
            cout<<b<<" ";
        cout<<endl;
    }
    return 0;
}

