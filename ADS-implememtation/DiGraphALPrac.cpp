#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

class DiGraph{
    private:
        vector<vector<int>> vec,v;
        vector<int> visited;
        int n,e;
    public:
        DiGraph(int n,int e){
            this->n = n;
            this->e = e;
            vec.reserve(n);
            v.reserve(n);//for transpose needed for kosaraju's algo
            visited.reserve(n);
            clearVisitedVec();
        }

        void clearVisitedVec(){
            for(int i=0;i<n;i++) visited[i] = 0;
        }

        void addEdges(){
            cout<<"Enter start and end vertices of all the edges one by one:\n";
            int v1,v2;
            for(int i=0;i<e;i++){
                cin>>v1>>v2;
                v1--;v2--;
                vec[v1].push_back(v2);
            }
        }

        void showAdjacencyList(){
            vector<int>::iterator itr;
            for(int i=0;i<n;i++){
                itr = v[i].begin();
                cout<<i+1<<": ";
                while(itr != v[i].end()){
                    cout<<*itr+1<<" ";
                    itr++;
                }
                cout<<endl;
            }
        }

        void BFSHelper(queue<int> &q){
            if(!q.empty()){
                int tmp = q.front();
                q.pop();
                vector<int>::iterator itr = vec[tmp].begin();
                while(itr != vec[tmp].end()){
                    if(!visited[*itr]){
                        cout<<*itr+1<<" ";
                        visited[*itr] = 1;
                        q.push(*itr);
                    }
                    itr++;
                }
                BFSHelper(q);
            }
        }

        void BFS(int strtV){
            if(strtV > n) return;
            queue<int> q;
            strtV--;
            q.push(strtV);
            cout<<strtV+1<<" ";
            visited[strtV] = 1;
            BFSHelper(q);
            for(int i=0;i<n;i++){
                if(!visited[i]){
                    while(!q.empty()) q.pop();
                    q.push(i);
                    cout<<i+1<<" ";
                    visited[i] = 1;
                    BFSHelper(q);
                }
            }
            cout<<endl;
            clearVisitedVec();
        }

        //following DFS functions are modeled as per the need of the kosaraju algo
        void DFSHelper(vector<vector<int>> &vec,int strtV,stack<int> &s,bool op){
            vector<int>::iterator itr = vec[strtV].begin();
            while(itr != vec[strtV].end()){
                if(!visited[*itr]){
                    visited[*itr] = 1;
                    if(op) cout<<*itr+1<<" ";
                    DFSHelper(vec,*itr,s,op);
                }
                itr++;
            }
            if(itr == vec[strtV].end()) s.push(strtV);
        }

        void DFS(vector<vector<int>> &vec,int strtV,stack<int> &s,bool op){
            if(strtV > n) return;
            strtV--;
            visited[strtV] = 1;
            //cout<<strtV+1<<" ";
            DFSHelper(vec,strtV,s,op);
            for(int i=0;i<n;i++){
                if(!visited[i]){
                    visited[i] = 1;
                    //cout<<i+1<<" ";
                    DFSHelper(vec,i,s,op);
                }
            }
            cout<<endl;
            clearVisitedVec();
        }

        void transpose(){
            vector<int>::iterator itr;
            for(int i=0;i<n;i++){
                itr = vec[i].begin();
                while(itr != vec[i].end()){
                    v[*itr].push_back(i);
                    itr++;
                }
            }
        }

        void SCCKosaraju(){
            cout<<"\nStrongly connected components of the digraph are:";
            stack<int> s;
            DFS(vec,1,s,false);
            transpose();
            stack<int> dum;
            int i = 1;
            while(!s.empty()){
                int tmp = s.top();
                if(!visited[tmp]){
                    cout<<"Component "<<i<<": ";
                    visited[tmp] = 1;
                    cout<<tmp+1<<" ";
                    DFSHelper(v,tmp,dum,true);
                    s.pop();
                    i++;
                    cout<<endl;
                }
                else s.pop();
            }
            clearVisitedVec();
        }
};

int main(){
    cout<<"Enter the number of vertices and edges: ";
    int n,e;
    cin>>n>>e;
    DiGraph g(n,e);
    g.addEdges();
    //g.showAdjacencyList();
    cout<<"Enter start vertex for BFS traversal: ";
    int v;
    cin>>v;
    g.BFS(v);
    g.SCCKosaraju();
    return 0;
}