#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

class Graph{
    public: 
        int n;
        vector<vector<pair<int, int>>> adj;
        bool bidirec = true;
        Graph(int n){
            this->n = n;
            adj.resize(n);
        }
        Graph(int n, bool b){
            this->n = n;
            adj.resize(n);
            bidirec = b;
        }
        void addedge(int a, int b, int wght){
            adj[a].push_back(make_pair(b, wght));
            if(bidirec) adj[b].push_back(make_pair(a, wght));
        }

        //dijkstra with prioirty queue and complexity O(E logV)
        int dijkstra(int src, int dest){
            vector<int> visited(n, INT_MAX);
            visited[src] = 0;

            class elem{//class to store vertex and distance in priority queue
                public:
                    int vert;
                    int dist;
                    elem(int vert, int dist){
                        this->vert = vert;
                        this->dist = dist;
                    }
            };

            class Compare{//custom compare function for comparing elem objects
                public:
                    bool operator()(elem a, elem b){
                        return a.dist < b.dist;
                    }
            };

            priority_queue<elem, vector<elem>, Compare> que;
            que.push(elem(src, 0));


            while(!que.empty()){
                int curr = que.top().vert;
                int cdist = que.top().dist;
                que.pop();
                if(cdist > visited[curr]) continue;
                for(auto a: adj[curr]){
                    if(visited[a.first] > cdist+a.second){
                        visited[a.first] = cdist+a.second;
                        que.push(elem(a.first, cdist+a.second));
                    }
                }
            }

            cout<<"Shortest distance from source to all other nodes:\n";
            for(auto a: visited) cout<<a<<endl; //printing shortest distance from source to all other nodes

            return visited[dest];
        }

        //dfs-based dijkstra with O(V^2) complexity
        int func(int src, int dest){ 
            vector<int> visited(n, INT_MAX);
            visited[src] = 0;
            dijkstra2(src, 0, visited);
            return visited[dest];
        }
        void dijkstra2(int curr, int dist, vector<int> &visited){
            for(auto a: adj[curr]){
                if(visited[a.first] > dist+a.second){
                    visited[a.first] = dist+a.second;
                    dijkstra2(a.first, dist+a.second, visited);
                }
            }
        }
};

int main(){
    int n;
    cin>>n;
    bool bidirec;
    cin>>bidirec;
    Graph g(n, bidirec);
    int e;
    cin>>e;
    int n1, n2, w;
    while(e--){
        cin>>n1>>n2>>w;
        g.addedge(n1, n2, w);
    }
    cin>>n1>>n2;
    cout<<g.func(n1, n2)<<endl;
    return 0;
}