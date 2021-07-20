#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<sstream>
using namespace std;

class Node{
	public:
		int data;
		Node *left;
		Node *right;
		Node(){
			this->left = this->right = NULL;
		}
		Node(int data){
			this->data = data;
			this->left = this->right = NULL;
		}
		static Node* getNode(int data){
			Node *node = new Node(data);
			return node;
		} 
}*root = NULL;

void build(string str){
	istringstream strm(str);
	vector<string> vec;
	string s;
	while(strm){
		strm >> s;
		if(strm) vec.push_back(s);
	}

	if(!vec[0].compare("N")) return;

	root = new Node(stoi(vec[0]));

	queue<Node*> que;
	que.push(root);

	int size = vec.size();

	int i=0;
	while(!que.empty()){
		Node *curr = que.front();
		que.pop();
		if(++i >= size or !vec[i].compare("N")) curr->left = NULL;
		else curr->left = new Node(stoi(vec[i]));
		if(++i >= size or !vec[i].compare("N")) curr->right = NULL;
		else curr->right = new Node(stoi(vec[i]));
		if(curr->left) que.push(curr->left);
		if(curr->right) que.push(curr->right);
	}
}

void inorder(Node *root){
	if(root == NULL) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int main(){
	string str;
	getline(cin,str);
	build(str);
	inorder(root);
	return 0;
}