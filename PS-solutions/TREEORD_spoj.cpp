//https://www.spoj.com/problems/TREEORD/
#include <iostream>
#include <stdio.h>
using namespace std;
int ind = 0;

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

void postorder(node<int>* root,int dummy[]){
    if(root == NULL) return;
    postorder(root->left,dummy);
    postorder(root->right,dummy);
    dummy[ind++] = root->data;
    
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int pre[n],post[n],in[n];
	for(int i=0;i<n;i++) cin>>pre[i];
	for(int i=0;i<n;i++) cin>>post[i];
	for(int i=0;i<n;i++) cin>>in[i];
	
	int dummy[n];
	node<int>* root = buildTree1(pre,in,0,n-1,0,n-1);
	postorder(root,dummy);
	
	int flag = 0;
	try{
		for(int i=0;i<n;i++){
			if(dummy[i] != post[i]){
				flag = 1;
				break;
			}
		}			
	}
	catch(...){
		flag = 1;
	}
	if(flag)cout<<"no"<<endl;
	else cout<<"yes"<<endl;
	return 0;
}