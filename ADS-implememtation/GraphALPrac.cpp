//Unweighted graph
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class Graph{
    private:
        vector<vector<int>> vec;
        vector<int> visited;
        int n,e;
    public:
        Graph(int n,int e){
            this->n = n;
            this->e = e;
            vec.reserve(n);
            visited.reserve(n);
        }

        void addEdges(){
            cout<<"Enter the start and end vertex of the all the edges one by one:\n";
            int v1,v2;
            for(int i=0;i<e;i++){
                cin>>v1>>v2;
                v1--;v2--;//bcoz indexes start with 0
                vec[v1].push_back(v2);
                vec[v2].push_back(v1);
                visited[v1] = 0;
                visited[v2] = 0;
            }
        }
        void displayADJList(){
            vector<int>::iterator itr;
            for(int i=0;i<e;i++){
                itr = vec[i].begin();
                cout<<i+1<<": ";
                while(itr != vec[i].end()){
                    cout<<*itr+1<<" ";
                    itr++;
                }
                cout<<endl;
            }
        }

        void clearVisitedVec(){
            for(int i=0;i<n;i++) visited[i] = 0;
        }

        void BFS(int strtV){
            if(strtV > n) return;
            cout<<"BFS traversal: ";
            strtV--;
            queue<int> q;
            q.push(strtV);
            //print the node value immediately as you visit it
            //That is the below two statments must occur consecutively
            visited[strtV] = 1;
            cout<<strtV+1<<" ";
            vector<int>::iterator itr;
            while(!q.empty()){
                int tmp = q.front();
                q.pop();
                itr = vec[tmp].begin();
                while(itr != vec[tmp].end()){
                    if(!visited[*itr]){
                        visited[*itr] = 1;
                        cout<<*itr+1<<" ";
                        q.push(*itr);
                    }
                    itr++;
                }
            }
            cout<<endl;
            clearVisitedVec();
        }

        void BFSRecursiveH(int strtV){
            queue<int> q;
            cout<<strtV;
            BFSRecursiveH(strtV);
            clearVisitedVec();
            cout<<endl;
        }

        void BFSRecursive(int strtV,queue<int> &q){
            strtV--;
            int tmp = -1;
            if(!visited[strtV]){
                cout<<strtV+1<<" ";
                visited[strtV] = 1;
                tmp = strtV;
            }
            else if(!q.empty()){
                tmp = q.front();
                q.pop();
            }
            if(tmp != -1){
                vector<int>::iterator itr = vec[tmp].begin();
                while(itr != vec[tmp].end()){
                    if(!visited[*itr]){
                        cout<<*itr+1<<" ";
                        visited[*itr] = 1;
                        q.push(*itr);
                    }
                    itr++;
                }
                BFSRecursive(strtV+1,q);
            }
        }

        //Graph DFS is similar to tree preorder traversal
        void DFS(int strtV){
            if(strtV > n) return;
            cout<<"DFS traversal is: ";
            strtV--;
            stack<int> s;
            vector<int>::iterator itr;
            //print the node value immediately as you visit it
            //That is the below two statments must occur consecutively
            visited[strtV] = 1;
            cout<<strtV+1<<" ";
            s.push(strtV);
            while(!s.empty()){
                int tmp = s.top();
                itr = vec[tmp].begin();
                while(itr != vec[tmp].end()){
                    if(!visited[*itr]){
                        visited[*itr] = 1;
                        cout<<*itr+1<<" ";
                        s.push(*itr);
                        break;
                    }
                    itr++;
                }
                if(itr == vec[tmp].end()) s.pop();
            }
            cout<<endl;
            clearVisitedVec();
        }

        void DFSRecursive(int strtV){
            if(strtV > n) return;
            strtV--;
            cout<<strtV+1<<" ";
            visited[strtV] = 1;
            vector<int>::iterator itr = vec[strtV].begin();
            while(itr != vec[strtV].end()){
                if(!visited[*itr])
                    DFSRecursive(*itr+1);
                itr++;
            } 
        }

        void connectedComponents(){
            int j=1;
            queue<int> q;
            for(int i=0;i<n;i++){
                if(!visited[i]){
                    cout<<"Component "<<j++<<": ";
                    BFSRecursive(i+1,q);
                    cout<<endl;
                }
            }
            clearVisitedVec();
        }
};

int main(){
    int n,e;
    cout<<"Enter the number of vertices and edges:\n";
    cin>>n>>e;
    Graph graph(n,e);
    graph.addEdges();
    //graph.displayADJList();
    cout<<"Enter the vertex from which to start the BFS traversal: ";
    int v;
    cin>>v;
    graph.BFS(v);
     queue<int> q;
    /*graph.BFSRecursive(v,q);
    graph.clearVisitedVec();
    cout<<endl; */
    cout<<"Enter the vertex from which to start the DFS traversal: ";
    cin>>v;
    graph.DFSRecursive(v);
    graph.clearVisitedVec();
    /* stack<int> s;
    graph.DFSRecursive(v,s);
    graph.clearVisitedVec();
    cout<<endl; */   
    cout<<"BFS of connected components:\n"; 
    graph.connectedComponents();
    return 0;
}