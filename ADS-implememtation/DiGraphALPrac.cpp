#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

class DiGraph{
    private:
        vector<vector<int>> vec;
        vector<int> visited;
        int n,e;
    public:
        DiGraph(int n,int e){
            this->n = n;
            this->e = e;
            vec.reserve(n);
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
                itr = vec[i].begin();
                cout<<i+1<<": ";
                while(itr != vec[i].end()){
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

        void DFSHelper(int strtV){
            vector<int>::iterator itr = vec[strtV].begin();
            while(itr != vec[strtV].end()){
                if(!visited[*itr]){
                    visited[*itr] = 1;
                    cout<<*itr+1<<" ";
                    DFSHelper(*itr);
                }
                itr++;
            }
        }

        void DFS(int strtV){
            if(strtV > n) return;
            strtV--;
            visited[strtV] = 1;
            cout<<strtV+1<<" ";
            DFSHelper(strtV);
            for(int i=0;i<n;i++){
                if(!visited[i]){
                    visited[i] = 1;
                    cout<<i+1<<" ";
                    DFSHelper(i);
                }
            }
            cout<<endl;
            clearVisitedVec();
        }

        void SCCKojaraju(){
            
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
    cout<<"Enter start vertex for DFS traversal: ";
    cin>>v;
    g.DFS(v);
    return 0;
}