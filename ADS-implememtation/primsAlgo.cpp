#include<bits/stdc++.h>
using namespace std;

void printEdges(vector<int> edges){
    cout<<"Edges included in the MST are:\n";
    for(int i=0; i<edges.size(); i++){
        if(edges[i] == -1) continue;
        cout<<i<<" "<<edges[i]<<endl;
    }
}

int prims(int n, vector<vector<int>> edges){
    vector<vector<pair<int, int>>> adj(n);

    //create adjacency list for the bidirectional graph
    for(int i=0; i<edges.size(); i++){
        adj[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
        adj[edges[i][1]].push_back(make_pair(edges[i][0], edges[i][2]));
    }

    //visited array stores the current value/key assigned to a vertex
    //initially every vertex will have value as infinity except the source vertex which has 0 value
    vector<int> visited(n, INT_MAX);

    //parent array to keep track of parent and child relation between vertices
    vector<int> parent(n, -1);

    //using elem class we can bundle up the vertex and its current value and push it in priority queue 
    class elem{
        public:
            int val;
            int wght;
            elem(int v, int w){
                val = v;
                wght = w;
            }
    };

    //Custom compare function for prioirty queue 
    class Compare{
        public:
            bool operator()(elem a, elem b){
                return a.wght > b.wght;
            }
    };

    priority_queue<elem, vector<elem>, Compare> que;

    visited[0] = 0;
    que.push(elem(0, 0));

    int cnt = -1;
    int w = 0;
    //cout<<"parent\t"<<"node\t"<<"weight\n";
    while(cnt < n-1){
        int cval = que.top().val;
        int cwght = que.top().wght;
        que.pop();
        if(visited[cval] < cwght) continue;
        //cout<<parent[cval]<<"\t"<<cval<<"\t"<<cwght<<endl;
        visited[cval] = 0;
        w += cwght;
        cnt++;
        for(auto a: adj[cval]){
            if(visited[a.first] > a.second){
                visited[a.first] = a.second;
                parent[a.first] = cval;
                que.push(elem(a.first, a.second));
            }
        }
    }
    printEdges(parent);
    return w;
}

int main(){
    int n;
    cin>>n;
    int e;
    cin>>e;
    vector<vector<int>> edges(e);
    for(int i=0; i<e; i++){
        int n1, n2, w;
        cin>>n1>>n2>>w;
        edges[i].push_back(n1);
        edges[i].push_back(n2);
        edges[i].push_back(w);
    }
    cout<<prims(n, edges)<<endl;
    return 0;
}

/*input graph
9
14
0 1 4
0 7 8
1 7 11
7 6 1
1 2 8
7 8 7
2 8 2
8 6 6
6 5 2
2 3 7
2 5 4
3 5 14
3 4 9
5 4 10

o/p: 37
*/