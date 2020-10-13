//constructing binary tree from the traversal sequence
//linked list implementation
#include<iostream>
using namespace std;

template<class t>
class node{
    public:
        t data;
        node *left;
        node *right; 
        node(){};
};

node<int>* buildTree1(int pre[],int in[],int preS,int preE,int inS,int inE){
    if(inS > inE) return NULL;
    node<int>* root = new node<int>();
    root->data = pre[preS];
    int rootInd = -1;
    for(int i=inS;i<=inE;i++){
        if(in[i] == root->data){
            rootInd = i;
            break;
        }
    }
    if(rootInd == -1){
        cout<<"Invalid sequence.\n";
        return NULL;
    }
    int lInS = inS;
    int lInE = rootInd-1;
    int lPreS = preS+1;
    int lPreE = lPreS + lInE-lInS;
    int rInS = rootInd+1;
    int rInE = inE;
    int rPreS = lPreE+1;
    int rPreE = preE;
    root->left = buildTree1(pre,in,lPreS,lPreE,lInS,lInE);
    root->right = buildTree1(pre,in,rPreS,rPreE,rInS,rInE);
    return root;
}

node<int>* buildTree2(int post[],int in[],int postS,int postE,int inS,int inE){
    if(inS > inE) return NULL;
    node<int>* root = new node<int>();
    root->data = post[postE];
    int rootInd = -1;
    for(int i=inS;i<=inE;i++){
        if(in[i] == root->data){
            rootInd = i;
            break;
        }
    }
    if(rootInd == -1){
        cout<<"Invalid sequence.\n";
        return NULL;
    }
    int lInS = inS;
    int lInE = rootInd-1;
    int lPostS = postS;
    int lPostE = lPostS + lInE-lInS;
    int rInS = rootInd+1;
    int rInE = inE;
    int rPostS = lPostE+1;
    int rPostE = postE-1;
    root->left = buildTree2(post,in,lPostS,lPostE,lInS,lInE);
    root->right = buildTree2(post,in,rPostS,rPostE,rInS,rInE);
    return root;
}

void inorder(node<int>* root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node<int>* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node<int>* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    cout<<"Program to build binary tree given its traversal sequence.\n";
    cout<<"\nEnter the number of nodes in the tree: ";
    int size;
    cin>>size;
    cout<<"1.Preorder and inorder traversal\n2.Postorder and inorder traversal\n";
    cout<<"Enter your choice: ";
    int ch;
    cin>>ch;
    if(ch == 1){
        int pre[size],in[size];
        cout<<"Enter preorder sequence: ";
        for(int i=0;i<size;i++) cin>>pre[i];
        cout<<"Enter inorder sequence: ";
        for(int i=0;i<size;i++) cin>>in[i];
        node<int>* root = buildTree1(pre,in,0,size-1,0,size-1); 
        cout<<"Postorder traversal of the built tree:\n";
        postorder(root);cout<<endl;
    }
    else{
        int post[size],in[size];
        cout<<"Enter postorder sequence: ";
        for(int i=0;i<size;i++) cin>>post[i];
        cout<<"Enter inorder sequence: ";
        for(int i=0;i<size;i++) cin>>in[i];
        node<int>* root = buildTree2(post,in,0,size-1,0,size-1); 
        cout<<"Preorder traversal of built tree:\n";
        preorder(root);cout<<endl;
    }
    return 0;
}