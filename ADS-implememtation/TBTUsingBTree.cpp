#include<bits/stdc++.h>

using namespace std;

class TBTUsingBTree
{
private:
	struct Node
	{
		int data;
		Node *left,*right;
		int lbit,rbit,child;
	}*root,*head,*inseq[30];
	int n;

public:
	TBTUsingBTree()
	{
		initialize();
	}

	void initialize()
	{
		n = 0;
		root = new Node;
		root = NULL;
		head = new Node;
		head = NULL;
	}

	void setRoot(Node *r)
	{
		root = r;
	}

	Node* getRoot()
	{
		return root;
	}
	
	Node* create(Node *root)
	{
		cout<<"\nEnter data(-1 to end): ";
		Node *temp = new Node;
		cin>>temp->data;
		if(temp->data == -1)
			return NULL;
		cout<<"\nEnter the left child of "<<temp->data<<": "; 		
		temp->left = create(temp->left);
		if(temp->left != NULL)
			temp->left->child = 0;
		cout<<"\nEnter right child of "<<temp->data<<": ";
		temp->right = create(temp->right);
		if(temp->right != NULL)
			temp->right->child = 1;
		return temp;
	}
	
	void createTBTHead(Node *root)
	{
		head = new Node;
		head->left = root;
		head->right = head;
		head->rbit = head->lbit = 1;
	}	

	void inorderSequence(Node *root)
	{
		if(root == NULL)
			return;
		inorderSequence(root->left);
		Node *temp = root;
		inseq[n++] = root;
		if(temp->left == NULL)
			temp->lbit = 0;
		else
			temp->lbit = 1;
		if(temp->right == NULL)
			temp->rbit = 0;
		else
			temp->rbit = 1;
		inorderSequence(root->right);
	}

	void threadingBTree()
	{
		createTBTHead(root);
		inorderSequence(root);
		if(root == NULL)
			return;
		Node *temp = inseq[0];
		temp->left = head;
		if(temp->rbit == 0)
			temp->right = inseq[1];
		temp = inseq[n-1];
		temp->right = head;
		if(temp->lbit == 0)
			temp->left = inseq[n-2];
		for(int i=1;i<n-1;i++)
		{
			temp = inseq[i];
			if(temp->lbit == 0)
				temp->left = inseq[i-1];
			if(temp->rbit == 0)
				temp->right = inseq[i+1];
		}			
	}

	void insertRightIntoTBT(Node *root,int data)
	{
		if(root == NULL)
		{
			cout<<"Node with specified data not found."<<endl;
			return;
		}
		Node *temp = new Node;
		temp->data = data;
		temp->right = root->right;
		temp->rbit = root->rbit;
		temp->lbit = 0;
		temp->left = root;
		root->right = temp;
		root->rbit = 1;
		if(temp->rbit == 1)
		{		
			Node *dummy = temp->right;
			while(dummy->lbit == 1)
				dummy = dummy->left;
			dummy->left = temp;
		}
		temp = NULL;
		delete temp;
	}

	void insertLeftIntoTBT(Node *root,int data)
	{
		if(root == NULL)
		{
			cout<<"Node with specified data not found. "<<endl;
			return;
		}
		Node *temp = new Node;
		temp->data = data;
		temp->left = root->left;
		temp->lbit = root->lbit;
		temp->rbit = 0;
		temp->right = root;
		root->left = temp;
		root->lbit = 1;
		if(temp->lbit == 1)
		{
			Node *dummy = temp->left;
			while(dummy->rbit != 0)
			{
				cout<<dummy->data<<endl;
				dummy = dummy->right;
			}
			dummy->right = temp;
		}
		temp = NULL;
		delete temp;
	}

	void deleteFromTBT(Node *root,Node *node)
	{
		Node *parent;
		if(node->child == 1) //Is a right child
		{
			parent = node;
			while(parent->lbit == 1)
				parent = parent->left;
			parent = parent->left;
			
			while(node->rbit == 1)
				node = node->right;
			parent->right = node->right;
			parent->rbit = 0;
		}
		else
		{
			parent = node;
			while(parent->rbit == 1)
				parent = parent->right;
			parent = parent->right;
		
			while(node->lbit == 1)
				node = node->left;
			parent->left = node->left;
			parent->lbit = 0;
		}
	}

	Node* find(Node* root,int data)
	{
		if(root->data == data)
		{
			return root;
		}
		Node *temp = NULL;
		if(root->lbit == 1)
			temp = find(root->left,data);
		if(temp != NULL)
			return temp;
		if(root->rbit == 1)
			temp = find(root->right,data);
		return temp;
	}

	Node* getPreorderSuccessor(Node *root)
	{
		if(root->lbit != 0)
			return root->left;
		while(root->rbit == 0)
			root = root->right;
		return root->right;
	}

	void preorder()
	{
		if(root == NULL)
			return;
		Node *temp = root;
		while(temp != head)
		{
			cout<<temp->data<<" ";
			temp = getPreorderSuccessor(temp);
		}
	}

	Node* getInorderSuccessor(Node *root)
	{
		if(root->rbit == 0)
			return root->right;
		root = root->right;
		while(root->lbit == 1)
			root = root->left;
		return root;
	}

	void inorder()
	{
		Node *temp = root;
		while(temp->lbit != 0)
			temp = temp->left;
		while(temp != head)
		{
			cout<<temp->data<<" ";
			temp = getInorderSuccessor(temp);
		}
	}

	Node* getPostorderSuccessor(Node *root)
	{
		if(root->child == 1)
		{
			while(root->lbit == 1)
				root = root->left;
			return root->left;		
		}
		else
		{
			while(root->rbit == 1)
				root = root->right;
			root = root->right;
			if(root->rbit == 0)
				return root;
			root = root->right;
			while(root->lbit == 1 || root->rbit == 1)
			{
				if(root->lbit == 1)
					root = root->left;
				else
					root = root->right;
			}
			return root;
		}
	}

	Node* postorder()
	{
		Node *temp = new Node;
		temp = root;
		while(temp->lbit != 0 || temp->rbit != 0)
		{
			if(temp->lbit == 1)
				temp = temp->left;
			else
				temp = temp->right;
		}
		while(temp != root)
		{
			cout<<temp->data<<" ";
			temp = getPostorderSuccessor(temp);
		}
		cout<<root->data<<" ";
	}

	void preorder(Node *root)
	{
		if(root == NULL)
			return;
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}

	void inorder(Node *root)
	{
		if(root == NULL)
			return;
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);	
	}

	void postorder(Node *root)
	{
		if(root == NULL)
			return;
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";
	}

	void print(int i)
	{
		cout<<endl;
		if(i == 1)
		{
			cout<<"Preorder traversal: ";
			preorder();
		}
		else if(i == 2)
		{
			cout<<"Inorder traversal: ";
			inorder();
		}
		else
		{
			cout<<"Postorder traversal: ";
			postorder();
		}
		cout<<endl<<endl;
	}
};

int main()
{
	TBTUsingBTree obj;
	obj.setRoot(obj.create(obj.getRoot()));
	cout<<endl;
	obj.threadingBTree();
	obj.print(1);
	cout<<"1.Enter data to be inserted 2.Parent node of data 3.Insert as right child or left child(l/r): ";
	int c,p;char child;
	cin>>c>>p>>child;
	if(child == 'r' || child == 'l')
		obj.insertLeftIntoTBT(obj.find(obj.getRoot(),p),c);
	else
		obj.insertRightIntoTBT(obj.find(obj.getRoot(),p),c);
	obj.print(1);
	cout<<endl;
	return 0;
}	


