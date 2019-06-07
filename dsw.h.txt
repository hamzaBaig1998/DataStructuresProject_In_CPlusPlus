#pragma once

#include<iostream>
#include<string>
#include<math.h>
using namespace std;

class List
{
public:
	string Row_ID, Order_ID, Order_Date, Customer_ID, Customer_Name, Segment, Country, City;

};

class dsw_node
{
public:
	dsw_node * left;
	dsw_node *right;
	List *data = new List;
};

class DSW
{
private:
	dsw_node * root;

public:
	DSW()
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
	dsw_node* getRoot()
	{
		return root;
	}

	void Insert(string Row_ID, string Order_ID, string Order_Date, string Customer_ID, string Customer_Name, string Segment, string Country, string City);
	void inorder(dsw_node *);
	void postorder(dsw_node *);
	void preorder(dsw_node *);
	void Delete(string Row_ID);
	int height(dsw_node *);
	void heightBalanced(dsw_node *, int);
	void rightRotate(dsw_node*);
	void leftRotate(dsw_node*);
	dsw_node* createBackbone(dsw_node*);
	int getNodeCount(dsw_node*);
	void Search(string Row_ID);
};

void DSW::Insert(string Row_ID, string Order_ID, string Order_Date, string Customer_ID, string Customer_Name, string Segment, string Country, string City)
{
	dsw_node *p = new dsw_node;
	dsw_node *parent;
	p->data->Row_ID = Row_ID;
	p->data->Order_ID = Order_ID;
	p->data->Order_Date = Order_Date;
	p->data->Customer_ID = Customer_ID;
	p->data->Customer_Name = Customer_Name;
	p->data->Segment = Segment;
	p->data->Country = Country;
	p->data->City = City;
	p->left = NULL;
	p->right = NULL;
	parent = NULL;
	if (isempty())
		root = p;
	else
	{
		dsw_node *ptr;
		ptr = root;
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

void DSW::inorder(dsw_node *ptr)
{
	if (ptr != NULL)
	{
		inorder(ptr->left);
		cout << "  " << ptr->data << "  ";
		inorder(ptr->right);
	}
}


void DSW::postorder(dsw_node *ptr)
{
	if (ptr != NULL)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		cout << "  " << ptr->data << "  ";
	}
}

void DSW::preorder(dsw_node *ptr)
{
	if (ptr != NULL)
	{
		cout << "  " << ptr->data << "  ";
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void DSW::Delete(string Row_ID)
{
	dsw_node *back, *temp;
	dsw_node *delParent;    // Parent of node to delete
	dsw_node *delNode;      // Node to delete

	temp = root;
	back = NULL;

	// Find the node to delete
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
		cout << "Row ID NOT FOUND!!. Nothing deleted.\n";
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
		}
		else
		{
			if (delParent->left == delNode)
				delParent->left = delNode->left;
			else
				delParent->right = delNode->left;
			delete delNode;
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
				return;
			}
			else
			{
				if (delParent->left == delNode)
					delParent->left = delNode->right;
				else
					delParent->right = delNode->right;
				delete delNode;
				return;
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
			return;
		}
	}
}

int DSW::height(dsw_node *ptr)
{
	if (ptr == NULL)
		return 0;
	else
		return 1 + max(height(ptr->left), height(ptr->right));
}


int DSW::getNodeCount(dsw_node* current)
{
	int count = 0;
	if (current == NULL)
		return count;
	count++;
	while (current->right != NULL)
	{
		current = current->right;
		count++;
	}
	return count;
}

dsw_node* DSW::createBackbone(dsw_node* current)
{
	while (current->left != NULL)
	{
		rightRotate(current);
	}
	if (current->right != NULL)
		current->right = createBackbone(current->right);
	return current;
}

void DSW::rightRotate(dsw_node* current)
{
	if (current->left != NULL)
	{
		dsw_node *tempLeftChild = current->left;
		current->left = tempLeftChild->left;
		tempLeftChild->left = tempLeftChild->right;
		tempLeftChild->right = current->right;
		current->right = tempLeftChild;
		//swap content of root
		string temp = current->data->Row_ID;
		string temp1 = current->data->Order_ID;
		string temp2 = current->data->Order_Date;
		string temp3 = current->data->Customer_ID;
		string temp4 = current->data->Customer_Name;
		string temp5 = current->data->Segment;
		string temp6 = current->data->Country;
		string temp7 = current->data->City;


		current->data->Row_ID = tempLeftChild->data->Row_ID;
		current->data->Order_ID = tempLeftChild->data->Order_ID;
		current->data->Order_Date = tempLeftChild->data->Order_Date;
		current->data->Customer_ID = tempLeftChild->data->Customer_ID;
		current->data->Customer_Name = tempLeftChild->data->Customer_Name;
		current->data->Segment = tempLeftChild->data->Segment;
		current->data->Country = tempLeftChild->data->Country;
		current->data->City = tempLeftChild->data->City;

		tempLeftChild->data->Row_ID = temp;
		tempLeftChild->data->Order_ID = temp1;
		tempLeftChild->data->Order_Date = temp2;
		tempLeftChild->data->Customer_ID = temp3;
		tempLeftChild->data->Customer_Name = temp4;
		tempLeftChild->data->Segment = temp5;
		tempLeftChild->data->Country = temp6;
		tempLeftChild->data->City = temp7;
	}
}
void DSW::leftRotate(dsw_node* current)
{
	if (current->right != NULL)
	{
		dsw_node*tempRightChild = current->right;
		current->right = tempRightChild->right;
		tempRightChild->right = tempRightChild->left;
		tempRightChild->left = current->left;
		current->left = tempRightChild;
		//swap content of root
		string temp = current->data->Row_ID;
		string temp1 = current->data->Order_ID;
		string temp2 = current->data->Order_Date;
		string temp3 = current->data->Customer_ID;
		string temp4 = current->data->Customer_Name;
		string temp5 = current->data->Segment;
		string temp6 = current->data->Country;
		string temp7 = current->data->City;


		current->data->Row_ID = tempRightChild->data->Row_ID;
		current->data->Order_ID = tempRightChild->data->Order_ID;
		current->data->Order_Date = tempRightChild->data->Order_Date;
		current->data->Customer_ID = tempRightChild->data->Customer_ID;
		current->data->Customer_Name = tempRightChild->data->Customer_Name;
		current->data->Segment = tempRightChild->data->Segment;
		current->data->Country = tempRightChild->data->Country;
		current->data->City = tempRightChild->data->City;

		tempRightChild->data->Row_ID = temp;
		tempRightChild->data->Order_ID = temp1;
		tempRightChild->data->Order_Date = temp2;
		tempRightChild->data->Customer_ID = temp3;
		tempRightChild->data->Customer_Name = temp4;
		tempRightChild->data->Segment = temp5;
		tempRightChild->data->Country = temp6;
		tempRightChild->data->City = temp7;
	}
}

void DSW::heightBalanced(dsw_node* current, int nodeCount)
{
	int power = (int)log2(nodeCount + 1);
	int times = pow(2, power) - 1;
	int initialRotation = nodeCount - times;
	for (int i = 0; i<initialRotation; i++)
	{
		leftRotate(current);
		current = current->right;
	}
	while (times>1)
	{
		times = times / 2;
		current = root;
		for (int i = 0; i<times; i++)
		{
			leftRotate(current);
			current = current->right;
		}
	}
}

void DSW::Search(string Row_ID)
{
	dsw_node *temp = root;
	dsw_node *back = new dsw_node();
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