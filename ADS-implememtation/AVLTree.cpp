#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;

class node{
    public:
        int val;
        node* left;
        node* right;
        int height;
        node(int val){
            this->val = val;
            this->left = NULL;
            this->right = NULL;
            this->height = 1;
        }
};

int height(node *root){
    if(root == NULL) return 0;
    return root->height;
}

int balanceFactor(node *root){
    if(root == NULL) return 0;
    return height(root->left)-height(root->right);
}

node* rightRotate(node *root){
    node* r = root;
    root = root->left;
    r->left = root->right;
    root->right = r;
    r->height = max(height(r->left),height(r->right))+1;
    root->height = max(height(root->left),height(root->right))+1;
    return root;
}

node* leftRotate(node *root){
    node *r = root;
    root = root->right;
    r->right = root->left;
    root->left = r;
    r->height = max(height(r->left),height(r->right))+1;
    root->height = max(height(root->left),height(root->right))+1;
    return root;
}

node* insert(node *root,int val){
    if(root == NULL) return new node(val);

    if(root->val == val) return root;
    else if(root->val > val)
        root->left = insert(root->left,val);
    else 
        root->right = insert(root->right,val);

    root->height = max(height(root->right),height(root->left))+1;

    int bf = balanceFactor(root);

    if(bf > 1 and val < root->left->val){//ll imbalance
        root = rightRotate(root);
    }
    else if(bf < -1 and val > root->right->val){//rr imbalance
        root = leftRotate(root);
    }
    else if(bf > 1 and val > root->left->val){//lr imbalance
        root->left = leftRotate(root->left);
        root = rightRotate(root);
    }
    else if(bf < -1 and val < root->right->val){//rl imbalance
        root->right = rightRotate(root->right);
        root = leftRotate(root);
    }

    return root;
}

node* mydelete(node *root,int val){
    if(root == NULL) return NULL;
    if(root->val > val)
        root->left = mydelete(root->left,val);
    else if(root->val < val)
        root->right = mydelete(root->right,val);
    else{
        if(root->left == NULL and root->right == NULL) return NULL;
        else if(root->right == NULL) root = root->left;
        else if(root->left == NULL) root = root->right;
        else{
            node *temp = root->right;
            while(temp->left != NULL) temp = temp->left;
            root->val = temp->val;
            root->right = mydelete(root->right,temp->val);
            temp = NULL;
            delete temp;
        }
    }
    
    if(root == NULL) return NULL;

    root->height = max(height(root->left),height(root->right))+1;

    int bf = balanceFactor(root);

    if(bf > 1 and height(root->left->left) >= height(root->left->right)){// ll imbalanced
        root = rightRotate(root);
    }
    else if(bf < -1 and height(root->right->right) >= height(root->right->left)){
        //rr imbalance
        root = leftRotate(root);
    }
    else if(bf > 1 and height(root->left->left) < height(root->left->right)){
        //lr imbalance
        root->left = leftRotate(root->left);
        root = rightRotate(root);
    }
    else if(bf < -1 and height(root->right->right) < height(root->right->left)){
        //rl imbalance
        root->right = rightRotate(root->right);
        root = leftRotate(root);
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
    int ch;
    while(true){
        cout<<"Enter value(-1 to stop): ";
        cin>>ch;
        if(ch == -1) break;
        root = insert(root,ch);
        //cout<<root->val<<endl;
    }
    cout<<"\nPreorder traversal: ";
    preorder(root);
    cout<<endl;
    cout<<"Enter node to be deleted: ";
    cin>>ch;
    root = mydelete(root,ch);
    preorder(root);
    cout<<endl;
    return 0;
}