#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;

class node{
    public:
        int val;
        int hleft;
        int hright;
        node *left;
        node *right;
        node(){
            hright = 0;
            hleft = 0;
            left = NULL;
            right = NULL;
        }
};

node* insert(node *root,int val){
    if(root == NULL){
        node *n = new node();
        n->val = val;
        return n;
    }
    if(root->val == val){
        return root;
    }
    node *r = root;
    if(root->val > val){//inserting into left subtree
        root->left = insert(root->left,val);
        root->hleft = max(root->left->hleft,root->left->hright)+1;
        if(abs(root->hleft-root->hright) > 1){
            //decide whether it is ll imbalanced or lr imbalanced
            if(root->left->hleft > root->left->hright){//ll-imbalanced
                root = root->left;
                r->left = root->right;
                root->right = r;
            }
            else{//lr-imbalanced
                root = root->left->right;
                r->left->right = root->left;
                root->left = r->left;
                r->left = root->right;
                root->right = r;
            }
            r->hleft = max(r->left->hleft,r->left->hright)+1;
            if(r->right == NULL) r->hright = 0;
            else r->hright = max(r->right->hleft,r->right->hright)+1;
            root->hleft = max(root->left->hleft,root->left->hright)+1;
            root->hright = max(root->right->hleft,root->right->hright)+1;
        } 
    }
    else{//inserting into right subtree
        root->right = insert(root->right,val);
        root->hright = max(root->right->hleft,root->right->hright)+1;
        if(abs(root->hleft-root->hright) > 1){
            //decide whether it is ll imbalanced or lr imbalanced
            if(root->right->hright > root->right->hleft){//rr-imbalanced
                root = root->right;
                r->right = root->left;
                root->left = r;
            }
            else{//rl-imbalanced
                root = root->right->left;
                r->right->left = root->right;
                root->right = r->right;
                r->right = root->left;
                root->left = r;
            }
            if(r->left == NULL) r->hleft = 0;
            else r->hleft = max(r->left->hleft,r->left->hright)+1;
            r->hright = max(r->right->hleft,r->right->hright)+1;
            root->hleft = max(root->left->hleft,root->left->hright)+1;
            root->hright = max(root->right->hleft,root->right->hright)+1;
        }
    }
    return root;
}

void inorder(node *root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

int main(){
    node *root = NULL;
    while(true){
        cout<<"Enter value(-1 to stop): ";
        int ch;
        cin>>ch;
        if(ch == -1) break;
        root = insert(root,ch);
    }
    inorder(root);
    cout<<endl;
    cout<<root->val<<" "<<root->hleft<<" "<<root->hright<<endl;
    return 0;
}