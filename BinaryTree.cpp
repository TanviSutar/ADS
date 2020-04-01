#include <bits/stdc++.h>

using namespace std;

class BTree
{
private:
	struct Node
	{
		int data;
		Node *left,*right;
	}*root;

public:
	void initialize()
	{
		root = new Node;
		root = NULL;
	}

	Node* create()
	{
		Node *temp = new Node;
		cout<<"Enter data(-1 to end): ";
		cin>>temp->data;
		if(temp->data == -1)
			return NULL;
		cout<<"\nEnter left-child of "<<temp->data<<endl;
		temp->left = create();
		cout<<"\nEnter right-child of "<<temp->data<<endl;
		temp->right = create();
		return temp;
	}	

	void setRoot(Node *r)
	{
		root = r;
	}

	Node* getRoot()
	{
		return root;
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

	void preorderNonRecursive(Node *root)
	{
		stack<Node*> s;
		Node *temp = root;
		while(temp != NULL)
		{
			cout<<temp->data<<" ";
			s.push(temp);
			temp = temp->left;
		}

		while(!s.empty())
		{
			temp = s.top();
			s.pop();
			temp = temp->right;

			while(temp != NULL)
			{
				cout<<temp->data<<" ";
				s.push(temp);
				temp = temp->left;
			}
		}
		cout<<endl;	
	}

	void inorderNonRecursive(Node *root)
	{
		stack<Node*> s;
		Node *temp = root;
		while(temp != NULL)
		{
			s.push(temp);
			temp = temp->left;
		}

		while(!s.empty())
		{
			temp = s.top();
			s.pop();
			cout<<temp->data<<" ";
			temp = temp->right;

			while(temp != NULL)
			{
				s.push(temp);
				temp = temp->left;
			}
		}
		cout<<endl;
	}

	void postorderNonRecursive(Node *root)
	{
		stack<Node*> s;
		stack<int> i;
		Node *temp = root;

		while(temp != NULL)
		{
			s.push(temp);
			i.push(0);
			temp = temp->left;
		}

		while(!s.empty())
		{
			while(i.top() == 1)
			{
				temp = s.top();
				s.pop();
				i.pop();
				cout<<temp->data<<" ";
				if(i.empty())
					return;
			}
			i.pop();
			i.push(1);
			temp = s.top();
			temp = temp->right;
					
			while(temp != NULL)
			{
				s.push(temp);
				i.push(0);
				temp = temp->left;
			}
		}
		cout<<endl;
	}

	int countNodes(Node* root)
	{
		if(root == NULL)
			return 0;
		int count  = 1 + countNodes(root->left) + countNodes(root->right);
		return count;
	}

	int countLeafNodes(Node* root)
	{
		if(root->left == NULL and root->right == NULL)
			return 1;
		int count = 0;		
		if(root->left != NULL && root->right != NULL)
			count = countLeafNodes(root->left) + countLeafNodes(root->right);
		else if(root->left == NULL)
			count = countLeafNodes(root->right);
		else
			count = countLeafNodes(root->left);
		return count;
	}

	int countNodesOfDegree1(Node* root)
	{
		if(root == NULL || (root->left == NULL && root->right == NULL))
			return 0;
		int count = 0;
		if(root->left != NULL && root->right != NULL)
			count = countNodesOfDegree1(root->left) + countNodesOfDegree1(root->right);
		else if(root->left == NULL)
			count = 1 + countNodesOfDegree1(root->right);
		else
			count = 1 + countNodesOfDegree1(root->left);
		return count;
	}

	int countNodesOfDegree2(Node* root)
	{
		int count = 0;
		if(root->left  != NULL && root->right != NULL)
			count = 1 + countNodesOfDegree2(root->left) + countNodesOfDegree2(root->right);
		else
			return 0;
		return count;
	}

	Node* copy(Node *root)
	{
		if(root == NULL)
			return NULL;

		Node *temp = new Node;
		temp->data = root->data;
		temp->left = copy(root->left);
		temp->right = copy(root->right);
		return temp;
	}

	bool checkEquivalenceOfTrees(Node *root1,Node *root2) //root1 and root2 represent two different trees
	{
		if(root1 == NULL && root2 == NULL)
			return true;
		else if (root1 == NULL || root2 == NULL)
			return false;
		else if(root1->data != root2->data)
			return false;
		return (checkEquivalenceOfTrees(root1->left,root2->left) && checkEquivalenceOfTrees(root1->right,root2->right));
	}

	int heightOfTree(Node* root)
	{
		if(root == NULL || (root->left == NULL && root->right == NULL))
			return 0;
		int hl = heightOfTree(root->left);
		int hr = heightOfTree(root->right);
		return (1+(hl>hr)?(hl+1):(hr+1)); 
	}

	void swapChildren(Node *root)
	{
		if(root == NULL || (root->left == NULL && root->right == NULL))
			return;
		Node *temp1 = root->left;
		Node *temp2 = root->right;
		root->right = temp1;
		root->left = temp2;
		swapChildren(root->right);
		swapChildren(root->left);
	}
	
	void print(int i)
	{
		if(i == 1)
		{
			cout<<"Preorder traversal: \n";
			preorder(root);
			cout<<endl<<endl;
		}
		else if(i == 2)
		{
			cout<<"Inorder traversal: \n";
			inorder(root);
			cout<<endl<<endl;
		}
		else
		{
			cout<<"Postorder traversal: \n";
			postorder(root);
			cout<<endl<<endl;
		}
	}		
};

int main()
{
	BTree obj;
	obj.initialize();
	obj.setRoot(obj.create());
	obj.print(1);
	obj.swapChildren(obj.getRoot());
	obj.print(1);
	return 0;
}


