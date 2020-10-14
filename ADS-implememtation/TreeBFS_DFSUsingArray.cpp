#include<iostream>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;

void createHelper(int btree[],queue<int> que,int size){
    if(que.empty()) return;
    int tmp = que.front();
    que.pop();
    if(tmp*2+1 >= size) return;
    cout<<"Enter left child of "<<btree[tmp]<<".(-1 to skip): ";
    int dum;
    cin>>dum;
    if(dum != -1){
        que.push(tmp*2+1);
        btree[tmp*2+1] = dum;
    } 
    cout<<"Enter right child of "<<btree[tmp]<<".(-1 to skip): ";
    cin>>dum;
    if(dum != -1){
        que.push(tmp*2+2);
        btree[tmp*2+2] = dum;
    }
    createHelper(btree,que,size);
}

void createTree(int btree[],int size){
    cout<<"Enter root data: ";
    int tmp;
    cin>>tmp;
    btree[0] = tmp;
    queue<int> que;
    que.push(0);
    createHelper(btree,que,size);
}

//the btree is stored in BFS traversal array in the array already
//we can also just display the btree array instead of writing code for it
void BFS(int btree[],int size){
    cout<<"BFS traversal: ";
    int tmp = 0;
    queue<int> que;
    que.push(tmp);
    while(!que.empty()){
        tmp = que.front();
        que.pop();
        cout<<btree[tmp]<<" ";
        if(tmp*2+1 < size and btree[tmp*2+1] != -1) que.push(tmp*2+1);
        if(tmp*2+2 < size and btree[tmp*2+2] != -1) que.push(tmp*2+2);
    }
    cout<<endl;
}

void inorder(int btree[],int size){
    stack<int> stk;
    int tmp = 0;
    while(tmp < size and btree[tmp] != -1){//traverse to the left most node
        stk.push(tmp);
        tmp = tmp*2+1;        
    }
    while(!stk.empty()){
        tmp = stk.top();
        stk.pop();
        cout<<btree[tmp]<<" ";
        if(tmp*2+2 < size and btree[tmp*2+2] != -1){//is there a right subtree?
            tmp = tmp*2+2;
            while(tmp < size and btree[tmp] != -1){//traverse to left most node of right subtree
                stk.push(tmp);
                tmp = tmp*2+1;        
            }
        }
    }
    cout<<endl;
}

void preorder(int btree[],int size){
    stack<int> stk;
    stk.push(0);
    while(!stk.empty()){
        int tmp = stk.top();
        stk.pop();
        cout<<btree[tmp]<<" ";
        if(tmp*2+2 < size and btree[tmp*2+2] != -1) stk.push(tmp*2+2);
        if(tmp*2+1 < size and btree[tmp*2+1] != -1) stk.push(tmp*2+1);
    }
    cout<<endl;
}

//following function needs amends.
void postorder(int btree[],int size){
    int tmp = 0;
    stack<int> stk;
    while(tmp < size){//traverse till very left node of the tree
        stk.push(tmp);
        tmp = tmp*2+1;
    }
    bool flag = false;
    while(!stk.empty()){
        tmp = stk.top();
        if(flag or tmp*2+2 >= size or btree[tmp*2+2] == -1 ){
            cout<<tmp<<" ";
            stk.pop();
            if(tmp%2 == 0) flag = true;
        }
        else{
            int dummy = tmp*2+2;
            while(dummy < size and btree[dummy*2+2] != -1){
                stk.push(dummy);
                dummy = dummy*2+1;
            }
        }   
    }
}

void DFS(int btree[],int size){
    cout<<"DFS traversal:\n";
    cout<<"Inorder traversal: ";
    inorder(btree,size);
    cout<<"Preorder traversal: ";
    preorder(btree,size);
}

void showTree(int btree[],int size){
    for(int i=0;i<size;i++) cout<<btree[i]<<" ";
    cout<<endl;
}

int main(){
    cout<<"Enter the height of the tree: ";
    int h;
    cin>>h;
    int size = pow(2,h)-1;
    int btree[size] = {-1};
    createTree(btree,size);
    showTree(btree,size);
    BFS(btree,size);
    DFS(btree,size);
    return 0;
}