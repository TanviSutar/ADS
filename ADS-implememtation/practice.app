#include<iostream>
#include<array>
using namespace std;

struct Node{
    int val;
    Node* parent;
}

int main(){
    array<Node,20> arr;
    array<Node,20>::iterator itr;
    itr = arr.begin();
    itr->val = 34;
    itr->parent = itr;
    cout<<itr->val<<endl;
    return 0;
}