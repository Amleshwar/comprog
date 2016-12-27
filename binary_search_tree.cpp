#include <string.h>
#include <iostream>
#include <iomanip>
#include <utility>
#include <cstdio>
#include <vector>
#include <utility>
#include <math.h>
#include <algorithm>
#include <math.h>
#include <cstdlib>
#define rep(i, a, b) for(__typeof(a) i = (a); i < (b); ++i)
#define all(c) c.begin(), c.end() 
#define iter(it, c) for(__typeof((c).begin)it = (c).begin; it != (c).end(); it++)
using namespace std;

struct tree
{
	int data;
	struct tree* left;
	struct tree* right;
	struct tree* parent;
	tree(int data, tree* left, tree* right, tree* parent)
		: data(data), left(left), right(right), parent(parent){}
};

tree* searchTree(tree *t, int val);
void insert(tree** root, int val, tree* parent);
void deleteNode(tree** root, int val);
tree** rightAncestor(tree** root);
tree** leftDescendant(tree** root);
tree** findNext(tree** root);
void printTree(tree** root);

void printTree(tree** root)
{
	if(*root == NULL)
		return;
	else
	{
		printTree(&((*root)->left));
		cout << (*root)->data << "  "  << endl;
		printTree(&((*root)->right));
	}
}

tree* searchTree(tree *t, int val)
{
	if(t == NULL)
		return NULL;
	else
	{
		if(val == (t->data))
			return t;
		else if(val < (t->data))
			return searchTree(t->left, val);
		else
			return searchTree(t->right, val);
	}
}

void insert(tree** root, int val, tree* parent)
{
	if(*root == NULL)
		*root = new tree(val, NULL, NULL, parent);
	else
	{
		if(val > (*root)->data)
			insert(&((*root)->right), val, *root);
		else
			insert(&((*root)->left), val, *root);
	}
}


void deleteNode(tree** root, int val)
{
	if((*root) == NULL)
	{
		cout << "ERROR: The tree is empty: " << endl;
		return;
	}
	else 
	{
		if(val > (*root)->data)
			deleteNode(&((*root)->right), val);
		else if(val < (*root)->data)
			deleteNode(&((*root)->left), val);
		else
		{
			if((*root) -> right == NULL && ((*root)->parent)->left == (*root))
			{
				((*root)-> parent)->left = (*root)->left;
				((*root)->left)->parent = (*root)->parent;
				(*root) = NULL;
				return;
			}
			else if((*root) -> right == NULL && ((*root)->parent)->right == (*root))
			{
				((*root)-> parent)->right = (*root)->left;
				((*root)->left)->parent = (*root)->parent;
				(*root) = NULL;
				return;
			}
			else
			{
				tree** temp = leftDescendant(&(*root));
				if((*temp)->right != NULL)
				{
				    ((*temp)->right)->parent = (*temp)->parent;
					((*temp)->parent)->left = (*temp)->right; 
				}
				(*temp)->parent = (*root)->parent;
				if(((*root)->parent)->right == (*root))
					((*root)->parent)->right = (*temp);
				else
				((*root)->parent)->left = (*temp);
				(*temp)->left = (*root)->left;
				(*temp)->right = (*root)->right;
				(*root) = NULL;
				return;
			}
		}
	}
}

tree** rightAncestor(tree** root)
{
	if((*root)->data < ((*root)->parent)->data)
		return &((*root)->parent);
	else
		return rightAncestor(&((*root)->parent));
}


tree** leftDescendant(tree** root)
{
	if((*root)->left == NULL)
		return &(*root);
	else 
		return leftDescendant(&((*root)->left));
}

tree** findNext(tree** root)
{
	if((*root)->right == NULL)
		return rightAncestor(&(*root));
	else
		return leftDescendant(&((*root)->right));
}

int main()
{
	int n;
	cout << "Enter the number of elements in your tree" << endl;
	cin >> n;
	cout << "Enter the elements" << endl;
	int val;
	cin >> val;
	tree* node = new tree(val, NULL, NULL, NULL);
	rep(i, 0, n-1)
	{
		cin >> val;
		insert(&node,val,node);
	}

	printTree(&node);
	cout << "Enter the element you want to delete:" << endl;
	cin >> val;
	tree* res = searchTree(node, val);
	if(res == NULL)
		cout << "Element not found" << endl;
	else
	{
		deleteNode(&node, val);
		printTree(&node);
	}
}

