//array based binary tree for lowest common ancestor
#include<iostream>
#include<cmath>
#define EMPTY -1
#define MAX_HGHT 6
using namespace std;

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

int lca(int arr[],int no1,int no2,int size,int curr){
    if(arr[curr] == -1) return -1;//invalid node
    if(arr[curr] == no1 or arr[curr] == no2) return arr[curr];//one of value found at current node
    if(curr*2+1 > size){//leaf node
        if(arr[curr] == no1 or arr[curr] == no2)
            return arr[curr];
        else return -1;
    }
    int l = lca(arr,no1,no2,size,curr*2+1);
    int r = lca(arr,no1,no2,size,curr*2+2);
    if((l==no1 and r==no2) or (l==no2 and r==no1)) return arr[curr];
    else if(l != -1) return l;
    else if(r != -1) return r;
    else return -1;
}

int main(){
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
    //show(arr,size);
    for(int i=0;i<3;i++){
        cout<<"Enter the node values to obtain their LCA: ";
        int no1,no2;
        cin>>no1>>no2;
        cout<<"LCA of "<<no1<<" and "<<no2<<" is:"<<lca(arr,no1,no2,size,0)<<endl;
    }
    return 0;
}