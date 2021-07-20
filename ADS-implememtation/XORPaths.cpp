//all simple paths

#include<bits/stdc++.h>
using namespace std;


//using vector implementation of graph
/* void dfs(int curr, vector<pair<int, vector<int>>> adjlst, int target, map<int, bool> &visited, int bit, vector<int> &left, vector<int> &rght, int &sum){
       visited[curr] = true;

       int b = 0;
       vector<int> l, r;

       for(auto a: adjlst[curr].second){
           if(!visited[a]) dfs(a, adjlst, target, visited, b, l, r, sum);
           b++;
       }

       vector<int> tmp;

       for(int i=0; i<l.size(); i++){
           tmp.push_back(l[i]^adjlst[curr].first);
           if(l[i]^adjlst[curr].first == target) sum++;
       }

       for(int i=0; i<r.size(); i++){
           tmp.push_back(r[i]^adjlst[curr].first);
           if(r[i]^adjlst[curr].first == target) sum++;
       }

       for(auto a: l){
           for(auto b: r){
               if((a^b)^adjlst[curr].first == target) sum++;
           }
       }

       if(bit == -1) return;

       if(bit) left = tmp;
       else right = tmp;
}

long long xor_paths (int n, vector<int> w, int x, vector<vector<int> > edges) {

   vector<pair<int, vector<int>>> adjlst(n+1);

   for(int i=1; i<=n; i++){
       adjlst[i].first = w[i-1];
   }
   for(int i=0; i<(n-1); i++){
       adjlst[edges[i][0]].second.push_back(edges[i][1]);
   }
   for(int i=0; i<n; i++){
       cout<<adjlst[i+1].first<<": ";
       for(auto a : adjlst[i+1].second) cout<<a<<" "; cout<<endl;
   }

   map<int, bool> visited(n+1);
   for(int i=0; i<=n; i++) visited[i] = false;

   int sum = 0;
   vector<int> left, right;

   dfs(1, adjlst, x, visited, -1, left, right, sum);

    return sum;
}
 */

class Node{
    public: 
        int data;
        Node *left, *right;
 
        Node(){
            left = right = NULL;
        }
        Node(int data){
            this->data = data;
            left = right = NULL;
        }
};


void dfs(Node *root, vector<int> &fill, int &cnt, int target){
    if(!root) return;
    vector<int> ltree, rtree;
    dfs(root->left, ltree, cnt, target);
    dfs(root->right, rtree, cnt, target);
    for(int i=0; i<ltree.size(); i++){
        int tmp = ltree[i]^root->data;
        fill.push_back(tmp);
        if(tmp == target){
            cnt++;
            //cout<<ltree[i]<<" *** "<<root->data<<endl;
        } 
    }
    for(int i=0; i<rtree.size(); i++){
        int tmp = rtree[i]^root->data;
        fill.push_back(tmp);
        if(tmp == target){
            cnt++;
            //cout<<rtree[i]<<" *** "<<root->data<<endl;
        }
    }
    fill.push_back(root->data);
    for(auto a: ltree){
        for(auto b: rtree){
            if(((a^b)^root->data) == target) {
                cnt++;
                //cout<<a<<" "<<b<<" "<<root->data<<endl;
            }
        }
    }
}

long long xor_paths (int n, vector<int> w, int x, vector<vector<int> > edges) {
    map<int, Node*> lst;
    for(int i=0; i<n; i++){
        Node *n = new Node(w[i]);
        lst[i+1] = n;
    }
    for(int i=0; i<(n-1); i++){
        if(!lst[edges[i][0]]->left) lst[edges[i][0]]->left = lst[edges[i][1]];
        else lst[edges[i][0]]->right = lst[edges[i][1]]; 
    }
    /* int i=0;
    for(auto a: lst){
        cout)<<a.second->data<<" ";
        if(a.second->left) cout<<a.second->left->data<<" ";
        if(a.second->right) cout<<a.second->right->data<<" ";
        cout<<endl;
    } */

    vector<int> fill;
    int cnt = 0;
    dfs(lst[1], fill, cnt, x);

    return cnt;

}


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int n;
        cin >> n;
        vector<int> w(n);
        for(int i_w = 0; i_w < n; i_w++)
        {
        	cin >> w[i_w];
        }
        int x;
        cin >> x;
        vector<vector<int> > edges(n-1, vector<int>(2));
        for (int i_edges = 0; i_edges < n-1; i_edges++)
        {
        	for(int j_edges = 0; j_edges < 2; j_edges++)
        	{
        		cin >> edges[i_edges][j_edges];
        	}
        }

        long long out_;
        out_ = xor_paths(n, w, x, edges);
        cout << out_;
        cout << "\n";
    }
}




/*
1
5
2 1 3 1 1
1
1 2
1 3
3 4
3 5

o/p: 3
*/