//https://www.spoj.com/problems/BUGLIFE/
#include<iostream>
#include<vector>
#include<unordered_set>
#define ERROR 2
#define RED 0
#define BLACK 1
using namespace std;

//enum Color{RED,BLACK,ERROR};

class Graph{
    private:
        vector<int> vec[2000];
        vector<int> visited;
        int n,e;
    public:
        Graph(int n,int e){
            this->n = n;
            this->e = e;
            visited.reserve(n);
        }

        void clearVisistedVector(){
            for(int i=0;i<n;i++) visited[i] = 0;
        }

        void addEdge(){
            int v1,v2;
            for(int i=0;i<e;i++){
                cin>>v1>>v2;
                v1--;v2--;
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

        bool colorGraph(){
            vector<int>::iterator itr;
            vector<int> color(n,-1);
            unordered_set<int> set1;
            unordered_set<int>::iterator sitr;
            for(int i=0;i<n;i++){
                itr = vec[i].begin();
                set1.clear();
                while(itr != vec[i].end()){
                    if(color[*itr] != -1){
                        set1.insert(color[*itr]);
                    }
                    itr++;
                }
                if(set1.size() >= 2) return false;
                if(set1.size() == 0)
                    color[i] = RED;
                else{
                    sitr = set1.begin();
                    color[i] = (*sitr == RED)?BLACK:RED;
                }
            }
            return true;
        }
};

int main(){
    int t,n,e;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>e;
        Graph g(n,e);
        g.addEdge();
        if(g.colorGraph()) cout<<"Scenario #"<<i<<":"<<endl<<"No suspicious bugs found!"<<endl;
        else cout<<"Scenario #"<<i<<":"<<endl<<"Suspicious bugs found!"<<endl;
    }
    return 0;
}

