//constructing a binary tree given its traversal sequence
//array based implementation
#include<iostream>
#include<cmath>
using namespace std;

void buildTree1(int pre[],int in[],int arr[],int inS,int inE,int preS,int preE,int curr){
    if(inS > inE) return;
    arr[curr] = pre[preS];
    int rootInd = -1;
    for(int i=inS;i<=inE;i++){
        if(in[i] == arr[curr]){
            rootInd = i;
            break;
        }
    }
    if(rootInd == -1){
        cout<<"Invalid sequence.\n";
        return;
    }
    int lInS = inS;
    int lInE = rootInd-1;
    int lPreS = preS+1;
    int lPreE = lPreS+lInE-lInS;
    int rInS = rootInd+1;
    int rInE = inE;
    int rPreS = lPreE+1;
    int rPreE = preE;
    buildTree1(pre,in,arr,lInS,lInE,lPreS,lPreE,curr*2+1);
    buildTree1(pre,in,arr,rInS,rInE,rPreS,rPreE,curr*2+2);
}

void buildTree2(int post[],int in[],int arr[],int inS,int inE,int postS,int postE,int curr){
    if(inS > inE) return;
    arr[curr] = post[postE];
    int rootInd = -1;
    for(int i=inS;i<=inE;i++){
        if(in[i] == arr[curr]){
            rootInd = i;
            break;
        }
    }
    if(rootInd == -1){
        cout<<"Invalid sequence.\n";
        return;
    }
    int lInS = inS;
    int lInE = rootInd-1;
    int lPostS = postS;
    int lPostE = lPostS + lInE-lInS;
    int rInS = rootInd+1;
    int rInE = inE;
    int rPostS = lPostE+1;
    int rPostE = postE-1;
    buildTree2(post,in,arr,lInS,lInE,lPostS,lPostE,curr*2+1);
    buildTree2(post,in,arr,rInS,rInE,rPostS,rPostE,curr*2+2);
}

void show(int arr[],int size){
    cout<<"Tree structure stored in the array.\n";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    cout<<"Enter the height of the tree: ";
    int hgt;
    cin>>hgt;
    cout<<"Enter the number of nodes in the tree: ";
    int n;
    cin>>n;
    int size = pow(2,hgt)-1;
    int arr[size] = {-1};
    cout<<"1. Preorder and Inorder\n2. Postorder and Inorder";
    cout<<"\nEnter your choice: ";
    int ch;
    cin>>ch;
    cout<<"\nMake sure the traversal sequences are correct.\n";
    if(ch == 1){
        int pre[n],in[n];
        cout<<"Enter preorder sequence: ";
        for(int i=0;i<n;i++) cin>>pre[i];
        cout<<"Enter inorder sequence: ";
        for(int i=0;i<n;i++) cin>>in[i];
        buildTree1(pre,in,arr,0,n-1,0,n-1,0); 
        show(arr,size);
    }
    else{
        int post[n],in[n];
        cout<<"Enter postorder sequence: ";
        for(int i=0;i<n;i++) cin>>post[i];
        cout<<"Enter inorder sequence: ";
        for(int i=0;i<n;i++) cin>>in[i];
        buildTree2(post,in,arr,0,n-1,0,n-1,0); 
        show(arr,size);
    }
    return 0;
}