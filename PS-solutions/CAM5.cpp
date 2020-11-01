//https://www.spoj.com/problems/CAM5/
#include<iostream>
#include<vector>
using namespace std;

class Graph{
    private:
        vector<int> vec[100000];
        vector<int> visited;
        int n,e;
    public:
        Graph(int n,int e){
            this->n = n;
            this->e = e;
            visited.reserve(n);
            clearVisitedVec();
        }

        void clearVisitedVec(){
            for(int i=0;i<n;i++) visited[i] = 0;
        }
        
        void addEdges(){
            int v1,v2;
            for(int i=0;i<e;i++){
                cin>>v1>>v2;
                vec[v1].push_back(v2);
                vec[v2].push_back(v1);
            }
            //showAdjList();
        }

        void showAdjList(){
            vector<int>::iterator itr;
            for(int i=0;i<n;i++){
                itr = vec[i].begin();
                cout<<i<<": ";
                while(itr != vec[i].end()){
                    cout<<*itr<<" ";
                    itr++;
                }
                cout<<endl;
            }
        }

        void DFSHelper(int strtV){
            vector<int>::iterator itr = vec[strtV].begin();
            while(itr != vec[strtV].end()){
                if(!visited[*itr]){
                    visited[*itr] = 1;
                    DFSHelper(*itr);
                }
                itr++;
            }
        }

        void DFS(){
            int cnt = 0;
            for(int i=0;i<n;i++){
                if(!visited[i]){
                    visited[i] = 1;
                    cnt++;
                    DFSHelper(i);
                }
            }
            cout<<cnt<<endl;
            clearVisitedVec();
        }
};

int main(){
    int t,n,e;
    cin>>t;
    while(t--){
        cin>>n>>e;
        Graph g(n,e);
        g.addEdges();
        g.DFS();
    }
    return 0;
}