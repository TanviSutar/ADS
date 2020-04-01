#include <bits/stdc++.h>

using namespace std;

class TBT
{
private:
	struct Node
	{
		int data;
		int lbit,rbit;
		int child;//required for postorder traversal
		Node *left,*right;
	}*root,*head,*inseq[30];
	int n;

public:
	TBT()
	{
		initialize();
	}	

	void initialize()
	{
		root = head = NULL;
		n=0;
	}

	Node* getRoot()
	{
		return root;
	}

	Node* insertIntoBST(Node *root,int data)
	{
		if(root == NULL)
		{
			Node *temp = new Node;
			temp->data = data;
			temp->left = temp->right = NULL;
			temp->lbit = temp->rbit = 1;
			return temp;
		}
		if(root->data == data)
			return root;
		if(data < root->data)
		{
			root->left = insertIntoBST(root->left,data);
			if(root->left != NULL)			
				root->left->child = 0;
			return root;
		}
		else
		{
			root->right = insertIntoBST(root->right,data);
			if(root->right != NULL)			
				root->right->child = 1;
			return root;
		}
	}

	void createBST()//creates a BST by making recursive calls to insert method
	{
		int ch = 0;
		while(true)
		{
			cout<<"Enter data(-1 to end): ";
			cin>>ch;
			if(ch == -1)
				return;
			root = insertIntoBST(root,ch);
		}
	}

	void createTBTHead()
	{
		head = new Node;
		head->data = 999;
		head->left = root;
		head->right = head;
		head->lbit = head->rbit = 1;
	}

	void inorderSequence(Node *root)//required for creating inorder threaded binary tree
	{
		if(root == NULL)
			return;
		inorderSequence(root->left);
		inseq[n++] = root;
		if(root->left == NULL)
			root->lbit = 0;
		else
			root->lbit = 1;
		if(root->right == NULL)
			root->rbit = 0;
		else
			root->rbit = 1;
		inorderSequence(root->right);
	}

	void threadingBST()
	{
		createTBTHead();
		inorderSequence(root);
		Node *temp = new Node;
		temp = inseq[0];
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
		cout<<"Reached\n";
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
			cout<<endl<<root->data<<" found\n";
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


	Node* preorderSuccessor(Node *root)
	{
		if(root->lbit == 1)
			return root->left;
		while(root->rbit == 0)
			root = root->right;
		return root->right;
	}

	void preorder()
	{
		Node *temp = root;
		while(temp != head)
		{
			cout<<temp->data<<" ";
			temp = preorderSuccessor(temp);
		}
	}

	Node* inorderSuccessor(Node *root)
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
		while(temp->lbit == 1)
			temp = temp->left;
		while(temp != head)
		{
			cout<<temp->data<<" ";
			temp = inorderSuccessor(temp);
		}
	}

	Node* postorderSuccessor(Node *root)
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
			temp = postorderSuccessor(temp);
		}
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
	TBT obj;
	obj.createBST();
	obj.threadingBST();
	obj.print(1);
	cout<<"Enter node to be deleted: ";
	int i;
	cin>>i;
	obj.deleteFromTBT(obj.getRoot(),obj.find(obj.getRoot(),i));
	obj.print(1);
	return 0;
}



