#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;

class Node{
	public:	
		int data; 
		Node *left;
		Node *right;
		Node(int data){
			this->data = data;
			this->left = this->right = NULL;
		}
}*root = NULL;

void inorder(Node* root){
	if(root == NULL) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void preorder(Node* root){
	if(root == NULL) return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(Node* root){
	if(root == NULL) return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

void inorder(){
	stack<Node*> stk;
	Node *node = root;
	cout<<"Inorder: ";
	while(!stk.empty() or node){
		if(node){
			stk.push(node);
			node = node->left;
		}
		else{
			Node *curr = stk.top();
			stk.pop();
			cout<<curr->data<<" ";
			node = curr->right;
		}
	}
	cout<<endl;
}

void preorder(){
	stack<Node*> stk;
	Node *node = root;
	while(!stk.empty() or node){
		if(node){
			cout<<node->data<<" ";
			stk.push(node);
			node = node->left;
		}
		else{
			Node *curr = stk.top();
			stk.pop();
			node = curr->right;
		}
	}
	cout<<endl;
}

void postorder(){
	stack<Node*> stk;
	stack<int> flag;
	Node *node = root;
	while(!stk.empty() or node){
		if(node){
			stk.push(node);
			flag.push(0);
			node = node->left;
		}
		else{
			if(!flag.top()){
				node = stk.top()->right;
				flag.pop();
				flag.push(1);
			}
			else{
				cout<<stk.top()->data<<" ";
				stk.pop();
				flag.pop();
			}
		}
	}
	cout<<endl;
}

int height(Node *root){
	if(!root) return 0;
	return max(height(root->left),height(root->right)) +1;
}

void width(Node *root, int *minim, int *maxim, int curr){
	if(!root) return;
	if(curr < *minim) *minim = curr;
	if(curr > *maxim) *maxim = curr;
	width(root->left, minim, maxim, curr-1);
	width(root->right, minim, maxim, curr+1);
}


int findwidth(Node *root){
	int minim = 0, maxim = 0;
	width(root, &minim, &maxim, 0);
	return maxim-minim+1;
}

void build(vector<string> vec){
	if(!vec[0].compare("N")) return;
	
	root = new Node(stoi(vec[0]));

	queue<Node*> que;
	que.push(root);

	int i = 0;
	int size = vec.size();

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

void rightview(Node *root, int *cnt, int curr, vector<int> &vec){
	if(!root) return;
	if(*cnt < curr){
		*cnt = curr;
		vec.push_back(root->data);
	}
	rightview(root->right, cnt, curr+1, vec);
	rightview(root->left, cnt, curr-1, vec);
}


vector<int> topView(Node *root)
{
	int cnt = 1;
	vector<int> vec;
	
	if(!root) return vec;

	cnt = 0;
	rightview(root->right, &cnt, 1, vec);
	
	return vec;
}

bool path(Node *root, int val, vector<int> &vec){
	if(!root) return false;
	if(root->data == val){
		vec.push_back(root->data);
		return true;
	}
	bool left = path(root->left, val, vec);
	bool right = path(root->right, val, vec);
	if(left or right){
		vec.push_back(root->data);
		return true;
	} 
	return false;
}


void func(Node *root, int sum, int &maxsum){
	if(!root) return;
	if(!root->left and !root->right){
		maxsum = max(maxsum, sum+root->data);
		return;
	}
	func(root->left, sum+root->data, maxsum);
	func(root->right, sum+root->data, maxsum);
}

int maxPathLeaftoRoot(){
	int maxsum = 0;
	func(root, 0, maxsum);
	return maxsum;
}

void findleaves(Node *root, vector<int> &leaves){
	if(!root) return;
	if(!root->left and !root->right){
		leaves.push_back(root->data);
		return;
	} 
	findleaves(root->left, leaves);
	findleaves(root->right, leaves);
}
void findpathsum(Node *root, map<int,int> &pathsum, int sum){
	if(!root) return;
	pathsum[root->data] = sum = sum + root->data;
	findpathsum(root->left, pathsum, sum);
	findpathsum(root->right, pathsum, sum);
}
bool findlca(Node *root, int a, int b, int *lca){
	if(!root) return false;
	if(root->data == a or root->data == b) return true;
	bool left = findlca(root->left, a, b, lca);
	bool right = findlca(root->right, a, b, lca);
	if(left and right){
		*lca = root->data;
		return true;
	}
	return (left or right);
}	

int maxPathSum(Node* root)
{
	// code here
	int maxsum = 0;
	vector<int> leaves;
	findleaves(root, leaves);
	map<int,int> pathsum;
	findpathsum(root, pathsum, 0);
	int lca = 0;
	for(int i=0;i<leaves.size();i++){
		for(int j=i+1;j<leaves.size();j++){
			int lca = -1;
			findlca(root, leaves[i], leaves[j], &lca);
			maxsum = max(maxsum, pathsum[leaves[i]] + pathsum[leaves[j]] - 2*pathsum[lca] + lca);
			/* cout<<leaves[i]<<" "<<pathsum[leaves[i]]<<endl;
			cout<<leaves[j]<<" "<<pathsum[leaves[j]]<<endl;
			cout<<lca<<" "<<pathsum[lca]<<endl<<endl; */
		}
	} 
	return maxsum;
}


int main(){
	string str;
	getline(cin,str);
	istringstream strm(str);
	vector<string> vec;
	string s;int i=0;
	while(strm){
		strm >> s;
		if(strm) {
			vec.push_back(s);
		}
	}
	build(vec);
	cout<<maxPathSum(root);
	return 0;
}

