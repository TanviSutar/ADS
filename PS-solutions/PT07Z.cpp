//https://www.spoj.com/problems/PT07Z/
#include<iostream>
#include<vector>
using namespace std;

class Graph{
    private:
        vector<int> vec[10000];
        vector<int> visited;
        int n,e;
    public:
        Graph(int n){
            this->n = n;
            this->e = n-1;
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
                v1--;v2--;
                vec[v1].push_back(v2);
                vec[v2].push_back(v1);
            }
            //cout<<vec[0].size()<<endl;
        }

        // int DFSHelper(int strtV,int maxv,int &node){
        //     vector<int>::iterator itr = vec[strtV].begin();
        //     int m = maxv;
        //     bool flag = false;
        //     while(itr != vec[strtV].end()){
        //         if(!visited[*itr]){
        //             flag = true;
        //             visited[*itr] = 1;
        //             m = std::max(m,DFSHelper(*itr,maxv+1,node));
        //         }
        //         itr++;
        //     }
        //     if(!flag) node = strtV;
        //     return m;
        // }

        void DFS(){
            int pathlen = 0,val = 0;
            visited[0] = 1;
            DFSHelper(0,0,pathlen,val);
            clearVisitedVec();
            visited[val] = 1;
            pathlen = 0;
            DFSHelper(val,0,pathlen,val);
            cout<<ceilpathlen/2<<endl;
        }

        void DFSHelper(int strtV,int len,int &mlen,int &val){
            vector<int>::iterator itr = vec[strtV].begin();
            if(vec[strtV].size() == 1 and visited[*itr]){//leaf node
                if(len > mlen){
                    mlen = len;
                    val = strtV;
                }
                return;
            }
            while(itr != vec[strtV].end()){
                if(!visited[*itr]){
                    visited[*itr] = 1;
                    DFSHelper(*itr,len+1,mlen,val);
                }
                itr++;
            }
        }
};

int main(){
    int n;
    cin>>n;
    Graph g(n);
    g.addEdges();
    g.DFS();
    return 0;
}