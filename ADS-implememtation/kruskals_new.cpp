//kruskals for undirected graph (Can be easily converted to )
#include<bits/stdc++.h>
using namespace std;

int find(int n1, vector<int> vec){//without optimization
    //this function returns parent of n1
    if(vec[n1] == -1)
        return n1;
    return find(vec[n1], vec);
}

void myunion(int n1, int n2, vector<int> &vec){//without optimization
    //this function merges two trees, trees to which n1 and n2 belong
    vec[find(n1, vec)] = find(n2, vec);
}

//optimized version of find and union
int findOpt(int n1, vector<int> vec){//optimized version of find
    //this function returns parent of n1
    if(vec[n1] == -1)
        return n1;
    return vec[n1] = find(vec[n1], vec); //path compression
}

int myunionOpt(int n1, int n2, vector<int> &vec, vector<int> &rank){//optimized union
    //this function merges two trees, trees to which n1 and n2 belong
    int n1p = find(n1, vec);//find parent of n1
    int n2p = find(n2, vec);//find parent of n2

    if(rank[n2p] > rank[n1p])//n2p has higher rank
        vec[n1p] = n2p;
    else if(rank[n1p] > rank[n2p])//n1p has higher rank
        vec[n2p] = n1p;
    else{//both have same rank
        vec[n1p] = n2p;
        rank[n2p]++;//increase rank of n2p
    }
}

int kruskals(int n, vector<vector<int>> edges){
    //to create elements to push into priority queue
    class edge{
        public:
            int n1;
            int n2;
            int w;
            edge(int n1, int n2, int w){
                this->n1 = n1;
                this->n2 = n2;
                this->w = w;
            }
    };
    class Compare{
        public:
            bool operator()(edge a, edge b){
                return a.w > b.w;
            }
    };

    priority_queue<edge, vector<edge>, Compare> que;

    for(auto a: edges){
        que.push(edge(a[0], a[1], a[2]));
    }

    vector<int> vec(n, -1);
    vector<int> rank(n, 0);//initialize all ranks to 0
    int cnt = 0;
    int wght = 0;
    while(cnt < n-1){
        edge e = que.top();
        que.pop();
        if(findOpt(e.n1, vec) == findOpt(e.n2, vec)) continue;//if belong to same set/tree
        cnt++;
        wght += e.w;
        //cout<<e.n1<<" "<<e.n2<<" "<<e.w<<endl;
        myunionOpt(e.n1, e.n2, vec, rank);
    }

    return wght;
}

int main(){
    int n;
    cin>>n;
    int e;
    cin>>e;
    vector<vector<int>> vec(e);
    for(int i=0; i<e; i++){
        int n1, n2, w;
        cin>>n1>>n2>>w;
        vec[i].push_back(n1);
        vec[i].push_back(n2);
        vec[i].push_back(w);
    }
    cout<<kruskals(n, vec)<<endl;
}