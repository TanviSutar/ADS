//graph colouring using greedy approach and adjacency list data structure implemented using array of vectors
//m-colorability optimization/ chromatic number problem using greedy approach
#include<iostream>
#include<vector>
#include<set>
#define loop(i,s,e) for(int i=s;i<e;i++) 
using namespace std;

class Graph{
    vector<vector<int>> vec;
    public:
    void getNodes(int n){
        vec.resize(n);
    }
    void getEdges(int n1,int n2){
        if(n1 >= vec.size() or n2 > vec.size()){
            cout<<"Invalid vertice(s).\n";
            return;
        }
        vec[n1].push_back(n2);
        vec[n2].push_back(n1);
    }
    set<int> getAdjacentColor(int n,int nodecolor[]){//function to populate adjacency list of nth node
        set<int> arr;
        for(auto i:vec[n]){
            if(nodecolor[i] > 0) arr.insert(nodecolor[i]);
        }
        return arr;
    }
    int getColor(set<int> &arr){//function that decides the appropriate color for a node
        int color = 1;
        for(auto i:arr){
            if(color != i) return color;
            color++;
        }
        return color;
    }
    void display(int nodecolor[]){//function to display the colors of vertices
        set<int> tmp;
        cout<<endl<<"One of the ways to color the graph:\n";
        loop(i,0,vec.size()){
            cout<<"Node "<<i<<": "<<nodecolor[i]<<"\n";
            tmp.insert(nodecolor[i]);
        }
        cout<<"\nMinimum colors required: "<<tmp.size()<<endl;
    }
    void colorGraph(){//function to color the graph
        int nodecolor[vec.size()] = {0};
        loop(i,0,vec.size()){
            set<int> dummy = getAdjacentColor(i,nodecolor);
            if(dummy.size() < 1) nodecolor[i] = 1;
            else nodecolor[i] = getColor(dummy);
        }
        display(nodecolor);
    }
};

int main(){
    Graph g;
    cout<<"Enter the number of vertices: ";
    int n;
    cin>>n;
    g.getNodes(n);
    cout<<"\nNote: Vertice numbering starts from 0. Thus, the vertice range is 0-"<<(n-1)<<".\n\n";
    cout<<"Enter the number of edges: ";
    int e;
    cin>>e;
    cout<<"Enter the edge list(space-seperate the ends of the edges):\n";
    int e1,e2;
    loop(i,0,e){
        cin>>e1>>e2;
        g.getEdges(e1,e2);
    }
    g.colorGraph();
    return 0;
}