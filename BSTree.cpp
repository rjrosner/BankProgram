#include <iostream>
#include "BSTree.h"
using namespace std;

BSTree::BSTree()
{
	root = NULL;
}

BSTree::~BSTree()
{
	Empty();
}

bool BSTree::Insert(Account *acc)
{
	if (root == NULL)
	{
		root = new Node();
		root->pAcct = acc;
		root->left = NULL;
		root->right = NULL;
		return true;
	}
	return Insert(root, acc);
}

bool BSTree::Retrieve(const Account &info, Account * &acc) const
{
	return Retrieve(root, info, acc);
}

void BSTree::Display() const
{
	DisplayNode(root);
}

void BSTree::Empty()
{
	DelNode(root);
	root = NULL;
}

bool BSTree::isEmpty() const
{
	return root == NULL;
}

bool BSTree::Retrieve(Node *nd, const Account &info, Account * &acc) const
{
	if (nd == NULL)
	{
		acc = NULL;
		return false;
	}

	if (nd->pAcct->GetNumber() < info.GetNumber())
	{
		return Retrieve(nd->right, info, acc);
	}
	else if (nd->pAcct->GetNumber() > info.GetNumber())
	{
		return Retrieve(nd->left, info, acc);
	}

	acc = nd->pAcct;
	return true;
}

bool BSTree::Insert(Node *nd, Account *acc)
{
	if (nd->pAcct->GetNumber() == acc->GetNumber())
		return false;
	Node* pnew = NULL;
	if (nd->pAcct->GetNumber() < acc->GetNumber())
	{
		if (nd->right == NULL)
		{
			nd->right = new Node();
			pnew = nd->right;
		}
		else
		{
			return Insert(nd->right, acc);
		}
	}
	else
	{
		if (nd->left == NULL)
		{
			nd->left = new Node();
			pnew = nd->left;
		}
		else
		{
			return Insert(nd->left, acc);
		}
	}
	pnew->left = NULL;
	pnew->right = NULL;
	pnew->pAcct = acc;
	return true;
}

void BSTree::DisplayNode(Node* nd) const
{
	if (nd == NULL)
		return;
	DisplayNode(nd->left);
	nd->pAcct->Display();
	DisplayNode(nd->right);
}

void BSTree::DelNode(Node* nd)
{
	if (nd == NULL)
		return;
	DelNode(nd->left);
	DelNode(nd->right);
	delete nd->pAcct;
	delete nd;
}
