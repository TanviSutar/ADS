#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;

class node{
    public:
        int val;
        int height;
        node* left;
        node* right;
        node(int val,int hgt){
            this->val = val;
            this->height = hgt;
            this->left = NULL;
            this->right = NULL;
        }
};

int height(node* root){
    if(root == NULL) return 0;
    return root->height;
}

node* rightRotate(node* root){
    node* r = root;
    root = root->left;
    r->left = root->right;
    root->right = r;
    r->height = max(height(r->left),height(r->right))+1;
    root->height = max(height(root->left),height(root->right))+1;
    return root;

    /* node newroot = root->left;
    root->left = newroot->right;
    newroot->right = root;
    root->height = max(height(root->left),height(root->right))+1;
    newroot->height = max(height(newroot->left),height(newroot->right))+1;
    return newroot; */
}

node* leftRotate(node* root){
    node *r = root;
    root = root->right;
    r->right = root->left;
    root->left = r;
    r->height = max(height(r->left),height(r->right))+1;
    root->height = max(height(root->left),height(root->right))+1;
    return root;

    /* node *newroot = root->right;
    root->right = newroot->left;
    newroot->left = root;
    root->height = max(height(root->left),height(root->right))+1;
    root->height = max(height(newroot->left),height(newroot->right))+1;
    return newroot; */
}

int balancefactor(node* root){
    if(root == NULL) return 0;
    if(root->left == NULL and root->right == NULL) return 0;
    if(root->left == NULL) return root->right->height+1;
    if(root->right == NULL) return root->left->height+1;
    return abs(root->right->height - root->left->height); 
}

node* insert(node* root,int val){
    if(root == NULL) return new node(val,0);

    if(root->val == val) return root;
    if(root->val > val) root->left =  insert(root->left,val);
    else root->right = insert(root->right,val);

    root->height = max(height(root->left),height(root->right))+1;
    //cout<<root->height<<endl;

    if(balancefactor(root) > 1){
        if(root->left and val <= root->left->val)//ll imbalanced
            root = rightRotate(root);
        else if(root->right and val >= root->right->val)//rr imbalanced
            root = leftRotate(root);
        else if(root->left and val >= root->left->val){//lr imbalanced
            root->left = leftRotate(root->left);
            root = rightRotate(root);
        }
        else if(root->right and val <= root->right->val){//rl imbalanced
            root->right = rightRotate(root->right);
            root = leftRotate(root);
        }
    }
    return root;
}

void preorder(node *root){
    if(root == NULL) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    node *root = NULL;
    while(true){
        cout<<"Enter value(-1 to stop): ";
        int ch;
        cin>>ch;
        if(ch == -1) break;
        root = insert(root,ch);
        //cout<<root->val<<endl;
    }
    cout<<"\nPreorder traversal: ";
    preorder(root);
    cout<<endl;
    return 0;
}