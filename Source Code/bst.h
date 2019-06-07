#pragma once
// this code file only implements insertion, deletion and tree traversal techniques.
// repetition of nodes/values is not implemented.

#include<iostream>
#include<conio.h>
#include<string>
using namespace std;

class List
{
public:
	string Row_ID, Order_ID, Order_Date, Customer_ID, Customer_Name, Segment, Country, City;

};

class tree_node
{
public:
	tree_node * left;
	tree_node *right;
	List *data = new List;
};

class BinarySearchTree
{
private:
	tree_node * root;

public:
	BinarySearchTree()
	{
		root = NULL;
	}

	int isempty()
	{
		return(root == NULL);
	}

	int max(int x, int y)
	{
		if (x>y)
			return x;
		else
			return y;
	}
	tree_node* getRoot()
	{
		return root;
	}

	void Insert(string Row_ID, string Order_ID, string Order_Date, string Customer_ID, string Customer_Name, string Segment, string Country, string City);
	void inorder(tree_node *);
	void postorder(tree_node *);
	void preorder(tree_node *);
	int Delete(string Row_ID);
	int height(tree_node *);
	void Search(string Row_ID);
};

void BinarySearchTree::Insert(string Row_ID, string Order_ID, string Order_Date, string Customer_ID, string Customer_Name, string Segment, string Country, string City)
{
	tree_node *p = new tree_node;
	tree_node *parent = NULL;
	p->data->Row_ID = Row_ID;
	p->data->Order_ID = Order_ID;
	p->data->Order_Date = Order_Date;
	p->data->Customer_ID = Customer_ID;
	p->data->Customer_Name = Customer_Name;
	p->data->Segment= Segment;
	p->data->Country = Country;
	p->data->City = City;
	p->left = NULL;
	p->right = NULL;
	if (isempty())
		root = p;
	else
	{
		tree_node *ptr = root;
		while (ptr != NULL)
		{
			parent = ptr;
			if (Row_ID>ptr->data->Row_ID)
				ptr = ptr->right;
			else
				ptr = ptr->left;
		}
		if (Row_ID<parent->data->Row_ID)
			parent->left = p;
		else
			parent->right = p;
	}
}


void BinarySearchTree::inorder(tree_node *ptr)
{
	if (ptr != NULL)
	{
		inorder(ptr->left);
		cout << "  " << ptr->data << "  ";
		inorder(ptr->right);
	}
}

void BinarySearchTree::postorder(tree_node *ptr)
{
	if (ptr != NULL)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		cout << "  " << ptr->data << "  ";
	}
}

void BinarySearchTree::preorder(tree_node *ptr)
{
	if (ptr != NULL)
	{
		cout << "  " << ptr->data << "  ";
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

int BinarySearchTree::Delete(string Row_ID)
{
	tree_node *back, *temp;
	tree_node *delParent;    // Parent of node to delete
	tree_node *delNode;      // Node to delete

	temp = root;
	back = NULL;

	// Find the node to delete
	cout << "Finding requried node " << endl;
	while ((temp != NULL) && (Row_ID != temp->data->Row_ID))
	{
		back = temp;
		if (Row_ID < temp->data->Row_ID)
			temp = temp->left;
		else
			temp = temp->right;
	}

	if (temp == NULL) // Didn't find the node to delete
	{
		cout << "Row ID NOT FOUND!!!.\n";
		return false;
	}
	else
	{
		if (temp == root) // Deleting the root
		{
			delNode = root;
			delParent = NULL;
		}
		else
		{
			delNode = temp;
			delParent = back;
		}
	}

	// Case 1: Deleting node with no children or one child
	if (delNode->right == NULL)
	{
		if (delParent == NULL)    // If deleting the root
		{
			root = delNode->left;
			delete delNode;
			return true;
		}
		else
		{
			if (delParent->left == delNode)
				delParent->left = delNode->left;
			else
				delParent->right = delNode->left;
			delete delNode;
			return true;
		}
	}
	else // There is at least one child
	{
		if (delNode->left == NULL)    // Only 1 child and it is on the right
		{
			if (delParent == NULL)    // If deleting the root
			{
				root = delNode->right;
				delete delNode;
				return true;
			}
			else
			{
				if (delParent->left == delNode)
					delParent->left = delNode->right;
				else
					delParent->right = delNode->right;
				delete delNode;
				return true;
			}
		}
		else // Case 2: Deleting node with two children
		{
			// Find the replacement value.  Locate the node
			// containing the largest value smaller than the
			// key of the node being deleted.
			temp = delNode->left;
			back = delNode;
			while (temp->right != NULL)
			{
				back = temp;
				temp = temp->right;
			}
			// Copy the replacement values into the node to be deleted
			delNode->data = temp->data;
			// Remove the replacement node from the tree
			if (back == delNode)
				back->left = temp->left;
			else
				back->right = temp->left;
			delete temp;
			return true;
		}
	}
}


void BinarySearchTree::Search(string Row_ID)
{
	tree_node *temp = root;
	tree_node *back = new tree_node();
	back = NULL;
	while ((temp != NULL) && (Row_ID != temp->data->Row_ID))
	{
		back = temp;
		if (Row_ID < temp->data->Row_ID)
			temp = temp->left;
		else
			temp = temp->right;
	}

	if (Row_ID == temp->data->Row_ID)
	{
		cout << "Row ID Found!" << endl;
	}
	if (temp == NULL)
	{
		cout << "Row ID Not Found!!" << endl;
	}
}
int BinarySearchTree::height(tree_node *ptr)
{
	if (ptr == NULL)
		return 0;
	else
		return 1 + max(height(ptr->left), height(ptr->right));
}


