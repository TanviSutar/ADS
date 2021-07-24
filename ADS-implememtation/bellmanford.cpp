#include<bits/stdc++.h>
using namespace std;

int bellmanford(bool bidirec, int n, int e, int src, int dest, vector<vector<int>> edges){
    vector<int> visited(n, INT_MAX);
    visited[src] = 0;

    for(int i=0; i<n-1; i++){
        for(int i=0; i<e; i++){
            if(visited[edges[i][0]] != INT_MAX and visited[edges[i][0]] + edges[i][2] < visited[edges[i][1]])
                visited[edges[i][1]] = visited[edges[i][0]] + edges[i][2];
            else if(bidirec and visited[edges[i][1]] != INT_MAX and visited[edges[i][1]] + edges[i][2] < visited[edges[i][0]])
                visited[edges[i][0]] = visited[edges[i][1]] + edges[i][2];
        }
    }

    //check negative weight cycle
    for(int i=0; i<e; i++){
        for(int i=0; i<e; i++){
            if(visited[edges[i][0]] != INT_MAX and visited[edges[i][0]] + edges[i][2] < visited[edges[i][1]]){
                cout<<"Negative weight cycle detected.\n";
                return -1;
            }
            else if(bidirec and visited[edges[i][1]] != INT_MAX and visited[edges[i][1]] + edges[i][2] < visited[edges[i][0]]){
                cout<<"Negative weight cycle detected.\n";
                return -1;
            }
        }
    }
    for(int i=0; i<n; i++) cout<<i<<" "<<visited[i]<<endl;
    return visited[dest];
}

int main(){
    bool bidirec;
    cin>>bidirec;
    int n;
    cin>>n;
    int e;
    cin>>e;
    vector<vector<int>> edges(e);
    int n1, n2, w;
    for(int i=0; i<e; i++){
        cin>>n1>>n2>>w;
        edges[i].push_back(n1);
        edges[i].push_back(n2);
        edges[i].push_back(w);
    }
    cin>>n1>>n2;
    cout<<bellmanford(bidirec, n, e, n1, n2, edges)<<endl;
    return 0;
}

/*
i/p:
1
9
14
0 1 4
0 7 8
1 7 11
1 2 8
7 8 7
7 6 1
3 2 7
5 2 4
6 5 2
8 2 2
8 6 6
3 5 14
3 4 9
4 5 10
2 0

o/p: 
0 12
1 8
2 0
3 7
4 14
5 4
6 6
7 7
8 2
12
*/