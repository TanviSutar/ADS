#include<bits/stdc++.h>
#define node1 first
#define nodelist second
#define node2 second.first
#define weight second.second
using namespace std;

template<typename T>
class Graph{
    private:
        map< T, vector<pair<T, int>> > edges;
    public:
        void addEdge(T n1, T n2, int wght, bool bidirec = 1){
            edges[n1].push_back(make_pair(n2, wght));
            if(bidirec) edges[n2].push_back(make_pair(n1, wght));
        }
        void display(map< T, vector<pair<T, int>> > edges){
            cout<< "Node1 " <<"\t"<< "Node2" <<"\t" << "Weight"<<endl;
            for(auto a: edges){
                for(auto n: a.second){
                    cout<< a.first <<"\t"<< n.first <<"\t"<< n.second << endl;
                }
            }
        }
        void bfs(T node1){
            queue<T> que;
            que.push(node1);
            map<T, bool> visited;
            cout<<"Following is the bfs traversal:\n";
            while(!que.empty()){
                T curr = que.front();
                que.pop();
                visited[curr] = true;
                cout<<curr<<" ";
                for(auto var : edges[curr]){
                    if(!visited[var.first]) 
                        que.push(var.first);
                }
            }
        }
        void dfs_helper(T node1, map<T, bool> &visited, map< T, vector<pair<T, int>> > edges){
            //cout<<node1<<"* ";
            visited[node1] = true;
            for(auto var : edges[node1]){
                if(!visited[var.first]){
                    dfs_helper(var.first, visited, edges);
                } 
            }
        }
        void dfs(T node1){
            map<T, bool> visited;
            cout<<"Following is dfs traversal:\n";
            dfs_helper(node1, visited, edges);
        }

        bool isStronglyConnected(T node){//kosaraju's algo
            if(edges.size() == 0) return false;
            map<T, bool> visited;
            dfs_helper(node,visited, edges);
            if(visited.size() != edges.size()) return false;

            map< T, vector<pair<T, int>> >  dummy;
            for(auto a : edges){//form the reverse edges
                for(auto b : a.second){
                    dummy[b.first].push_back(make_pair(a.first, b.second));
                }
            }
            
            visited.clear();
            dfs_helper(node, visited, dummy);
            if(visited.size() == edges.size()) return true;
            return false;
        }
};



int main(){
    //no. of vertices
    //no. of edges
    //edge list along with weight

    int n;
    cin>>n;
    
    int e;
    cin>>e;

    Graph<int> g;
    for(int i=0; i<e; i++){
        int x, y, w;
        cin >> x >> y >> w;
        g.addEdge(x, y, w, 0);
    }

    int tmp;
    cin>>tmp;
    cout<<"\nStrongly connected?: "<<g.isStronglyConnected(tmp)<<endl;

    return 0;
}