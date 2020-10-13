#include<iostream>
#include<cmath>
#include<stdio.h>
#define EMPTY -1
#define MAX_HGHT 6
using namespace std;

//Binary tree with height h has 2^h-1 nodes at max. and h nodes min. 
//Binary tree with height h has 2^(h-1) leaf nodes at max. i.e. number of nodes if it is a complete binary tree

void createTree(int arr[],int size,int curr){
    int tmp;
    cin>>tmp;
    arr[curr] = tmp;
    if(arr[curr] == -1 or curr*2+1 >= size) return;
    cout<<"Enter left child of "<<arr[curr]<<"(-1 to skip): ";
    createTree(arr,size,curr*2+1);
    cout<<"Enter right child of "<<arr[curr]<<"(-1 to skip): ";
    createTree(arr,size,curr*2+2);
}

void show(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void inorder(int arr[],int size,int curr){
    if(arr[curr] == -1) return;
    if(curr*2+1 < size) inorder(arr,size,curr*2+1);
    cout<<arr[curr]<<" ";
    if(curr*2+2 < size) inorder(arr,size,curr*2+2);
}

void preorder(int arr[],int size,int curr){
    if(arr[curr] == -1) return;
    cout<<arr[curr]<<" ";
    if(curr*2+1 < size) preorder(arr,size,curr*2+1);
    if(curr*2+2 < size) preorder(arr,size,curr*2+2);
}

void postorder(int arr[],int size,int curr){
    if(arr[curr] == -1) return;
    if(curr*2+1 < size) postorder(arr,size,curr*2+1);
    if(curr*2+2 < size) postorder(arr,size,curr*2+2);
    cout<<arr[curr]<<" ";
}

int main(){
    //ios_base.sync_with_stdio(NULL);
    cout<<"Enter the height of the tree: ";
    int hgt;
    cin>>hgt;
    if(hgt > MAX_HGHT){
        cout<<"Greater than valid height.";
        return 0;
    }
    int size = pow(2,hgt)-1;
    int arr[size] = {-1};
    cout<<"Enter the tree node values starting with root:\n";
    createTree(arr,size,0);
    cout<<"Inorder traversal:\n";
    inorder(arr,size,0);
    cout<<"\nPreorder traversal:\n";
    preorder(arr,size,0);
    cout<<"\nPostorder traversal:\n";
    postorder(arr,size,0);
    cout<<endl;
    return 0;
}