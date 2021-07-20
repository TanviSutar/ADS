#include<bits/stdc++.h>
using namespace std;

class Node{
    public: 
        int data;
        Node *left, *right;
        Node(){
            this->left = this->right = NULL;
        }
        Node(int data){
            this->data = data; 
            this->left = this->right = NULL;
        }
};

Node* build(string str, int &index){
    if(str[index] == ')' or index >= str.size()) return NULL;
    Node *node = new Node(str[index]-'0');
    if(index+1 < str.size() and str[index+1] == '(') node->left = build(str, index += 2);
    if(index+1 < str.size() and str[index+1] == '(') node->right = build(str, index += 2);
    index++;
    return node;
}
void inorder(Node *root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(Node *root){
    if(!root) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    string str;
    cin>>str;
    int index = 0;
    Node *root = build(str, index);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    return 0;
}
