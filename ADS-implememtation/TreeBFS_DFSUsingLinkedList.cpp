#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
        int data;
        node *left;
        node *right;
        node(){
            this->left = NULL;
            this->right = NULL;
        };
        node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

/* 
two different types of create functions. Very naive though.(;
void createTree(node *root){
    int tmp;
    cout<<"Enter left child of "<<root->data<<": ";
    cin>>tmp;
    if(tmp != -1){
        node *lft = new node();
        root->data = tmp;
        createTree(lft);
    }
    cout<<"Enter right child of "<<root->data<<": ";
    cin>>tmp;
    if(tmp != -1){
        node *rght = new node();
        root->data = tmp;
        createTree(rght);
    }
}
  
node* createTree(){
    node *root = new node();
    int tmp;
    cin>>tmp;
    if(tmp == -1) return NULL;
    root->data = tmp;
    cout<<"Enter left child of "<<root->data<<". (Enter -1 to skip):";
    root->left = createTree();
    cout<<"Enter right child of "<<root->data<<". (Enter -1 to  skip): ";
    root->right = createTree();
    return root;
} */

void BFS(node *root){
    queue<node*> que;
    que.push(root);
    while(!que.empty()){
        node *tmp = que.front();
        que.pop();
        cout<<tmp->data<<" ";
        if(tmp->left != NULL) que.push(tmp->left);
        if(tmp->right != NULL) que.push(tmp->right);
    }
    cout<<endl;
}

void inorder(node *root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node *root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void DFS(node *root){
    cout<<"Inorder traversal:\n";
    inorder(root);cout<<endl;
    cout<<"Preorder traversal:\n";
    preorder(root);cout<<endl;
    cout<<"Postorder traversal:\n";
    postorder(root);cout<<endl;
}

void createhelper(queue<node*> que){
    if(que.empty()) return;
    node *tmp = que.front(); 
    que.pop();
    cout<<"Enter the left child of "<<tmp->data<<".(-1 to skip): ";
    int dummy;
    cin>>dummy;
    if(dummy != -1){
        node *lft = new node(dummy);
        tmp->left = lft;
        que.push(lft);
    }
    cout<<"Enter the right child of "<<tmp->data<<".(-1 to skip): ";
    cin>>dummy;
    if(dummy != -1){
        node *rght = new node(dummy);
        tmp->right = rght;
        que.push(rght);
    }
    createhelper(que);
}

node* createTree(){
    queue<node*> que;
    node *root = new node();
    cout<<"Enter root value: ";
    int tmp;
    cin>>tmp;
    root->data = tmp;
    que.push(root);
    createhelper(que);
    return root;
}

int main(){
    node *root = new node();
    root = createTree();
    cout<<"\nBFS traversal:\n";
    BFS(root);
    cout<<"\nDFS taversals:\n";
    DFS(root);
    return 0;
}