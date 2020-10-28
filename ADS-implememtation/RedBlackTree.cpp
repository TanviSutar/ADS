//might need some fixes
//deleteion operation not included
#include<iostream>
using namespace std;

enum Color {RED,BLACK};

class node{
    public:
        int val;
        node *left,*right,*parent;
        int color;
        node(int val){
            this->val = val;
            left = right = parent = NULL;
            this->color = RED;
        }
};

void rotateRight(node *&root,node *&pt){
    node *ptleft = pt->left;
    if(pt->parent == NULL) root = ptleft;
    else if(pt->parent->left == pt) pt->parent->left = ptleft;
    else pt->parent->right = ptleft;
    ptleft->parent = pt->parent;
    pt->left = ptleft->right;
    if(pt->left) pt->left->parent = pt;
    ptleft->right = pt;
    pt->parent = ptleft;
}

void rotateLeft(node *&root,node *&pt){
    node *ptright = pt->right;
    if(pt->parent == NULL) root = ptright;
    else if(pt->parent->left == pt) pt->parent->left = ptright;
    else pt->parent->right = ptright;
    ptright->parent = pt->parent;
    pt->right = ptright->left;
    if(pt->right) pt->right->parent = pt;
    ptright->left = pt;
    pt->parent = ptright;
}

void fixViolations(node *&root,node *&pt){
    if(root == NULL) return;
    if(pt == root){
        root->color = BLACK;
        return;
    }
    node *prnt = pt->parent;
    node *gprnt = pt->parent->parent;
    if(prnt != root and pt->color == RED and prnt->color == RED){
        node *uncle;
        bool left1,left2;
        if(gprnt->left == prnt){
            uncle = gprnt->right;
            left1 = true;
        }
        else{
            uncle = gprnt->left;
            left1 = false;
        }
        if(prnt->left == pt) left2 = true;
        else left2 = false;
        if(uncle and uncle->color == RED){//case 1
            uncle->color = prnt->color = BLACK;
            gprnt->color = RED;
            pt = gprnt;
        }
        else{//case 2
            if(left1){
                //case lr
                if(!left2){
                    rotateLeft(root,prnt);
                    pt = prnt;
                    prnt = pt->parent;
                }
                //ll case
                rotateRight(root,gprnt);
                swap(prnt->color,gprnt->color);
                pt = gprnt;
            }
            else{
                //rl case
                if(left2){
                    rotateRight(root,prnt);
                    pt = prnt;
                    prnt = pt->parent;
                }
                //rr case
                rotateLeft(root,gprnt);
                swap(prnt->color,gprnt->color);
                pt = gprnt;
            }
        }
    }
    root->color = BLACK;
    //cout<<"ok, in fix.\n";
}

node* BSTInsert(node *root,node *pt){
    if(root == NULL) return pt;
    if(pt->val < root->val){
        root->left = BSTInsert(root->left,pt);
        root->left->parent = root;
    }
    else if(pt->val > root->val){
        root->right = BSTInsert(root->right,pt);
        root->right->parent = root;
    }
    //cout<<"ok,in bstinsert.\n";
    return root;
}

node* insert(node *&root,int val){
    //cout<<"in insert.\n";
    node *tmp = new node(val);

    root = BSTInsert(root,tmp);

    fixViolations(root,tmp);
    //cout<<"ok, in insert.\n";
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
        cout<<"Enter value(-1 to exit): ";
        int ch;
        cin>>ch;
        if(ch == -1) break;
        root = insert(root,ch); 
    }
    cout<<"Preorder taversal: ";
    preorder(root);
    return 0;
}