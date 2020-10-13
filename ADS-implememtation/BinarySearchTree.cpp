#include <bits/stdc++.h>

using namespace std;

class BST
{
private:
	struct Node
	{
		int data;
		Node *left,*right;
	}*root;
public:
	BST()
	{
		initialize();
	}

	void initialize()
	{
		root = NULL;
	}

	Node* getRoot()
	{
		return root;
	}

	void setRoot(Node *root)
	{
		this->root = root;
	}

	Node* insert(Node *root,int data)
	{
		if(root == NULL)
		{
			Node *temp = new Node;
			temp->data = data;
			temp->left = temp->right = NULL;
			return temp;
		}
		if(root->data == data)  //to prevent repetition
			return root;
		if(data < root->data)
		{
			root->left = insert(root->left,data);
			return root;		
		}		
		else
		{
			root->right = insert(root->right,data);
			return root;
		}
	}

	void create()
	{
		int ch = 1;
		while(ch != -1)
		{
			cout<<"Enter data(-1 to end): ";
			int i;
			cin>>i;
			if(i == -1)
				break;
			root = insert(root,i);
		}
	}

	Node* find(Node *root,int data)
	{
		if(root == NULL)
			return NULL;
		if(root->data == data)
			return root;
		if(data < root->data)
			find(root->left,data);
		else
			find(root->right,data);
	}

	int findMin()
	{
		Node *temp = root;
		while(temp->left != NULL)
			temp = temp->left;
		return temp->data;
	}

	int findMax()
	{
		Node *temp = root;
		while(temp->right != NULL)
			temp = temp->right;
		return temp->data;
	}

	void makeEmpty(Node *root)
	{
		if(root == NULL)
			return;
		makeEmpty(root->left);
		makeEmpty(root->right);
		delete root;
	}

	Node* deleteNode(Node *root,int data)
	{
		if(root == NULL)
			return root;
		if(root->data == data)
		{
			if(root->left == NULL && root->right == NULL)
			{	
				delete root;
				return NULL;
			}
			if(root->left == NULL)
			{
				Node *temp = root;
				delete temp;
				return root->right;
			}
			if(root->right == NULL)
			{
				Node *temp = root;
				delete temp;
				return root->left;
			}
			Node *temp = root->right;
			while(temp->left != NULL)
				temp = temp->left;
			root->data = temp->data;
			root->right = deleteNode(root->right,temp->data);
			return root;
		}
		root->left = deleteNode(root->left,data);
		root->right = deleteNode(root->right,data);
	}

	void deleteMultiple()
	{
		int i = 0;
		while(true)
		{	
			cout<<"Enter the value to be deleted(-1 to stop): ";
			cin>>i;
			if(i == -1)
				return;
			root = deleteNode(root,i);
		}
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
		switch(i)
		{
			case 1:
				preorder(root);
				cout<<endl;
				break;

			case 2:
				inorder(root);
				cout<<endl;
				break;

			default:
  				postorder(root);
				cout<<endl;
				break;
		}
	}
};

int main()
{
	BST obj;
	obj.create();
	obj.print(1);
	obj.deleteMultiple();
	obj.print(1);
	return 0;	
}




