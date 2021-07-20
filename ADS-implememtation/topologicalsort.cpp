#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
        int n;
        vector<vector<int>> adj;
        Graph(int n){
            this->n = n;
            adj.resize(n);
        }
        void addedge(int a, int b){
            adj[a].push_back(b);
        }
        bool iscyclic(){//detect if there is any cycle
            vector<int> visited(n, false);
            for(int i=0; i<n; i++)
                if(!visited[i])
                    if(detect(i, visited)) return true;
            return false;
        }

        //visited[curr] = {0:if not visited, 1: visited but not processed, 2: visited and processed}
        // visited means it has been visited but all its decendents haven't been visited yet
        // processed means the node and all its decendents have been visited 
        bool detect(int curr, vector<int> &visited){
            if(visited[curr] == 1) return true;
            if(visited[curr] == 2) return false;
            visited[curr] = 1;
            for(auto a: adj[curr])
                if(detect(a, visited)) return true;
            visited[curr] = 2;
            return false;
        }
        void toposort(){
            if(iscyclic()) return;
            vector<bool> visited(n, false);
            stack<int> stk;
            for(int i=0; i<n; i++)
                if(!visited[i])
                    sort(i, visited, stk);
            while(!stk.empty()){
                cout<<stk.top()<<" ";
                stk.pop();
            }
        }
        void sort(int curr, vector<bool> &visited, stack<int> &stk){
            visited[curr] = true;
            for(auto a: adj[curr])
                if(!visited[a])
                    sort(a, visited, stk);
            stk.push(curr);
        }
};

int main(){
    int n;
    cin>>n;
    Graph g(n);
    int e;
    cin>>e;
    int n1, n2;
    while(e--){
        cin>>n1>>n2;
        g.addedge(n1, n2);
    }
    g.toposort();
    return 0;
}