#ifndef BSTree_H
#define BSTree_H

#include "Account.h"

class BSTree
{
public:
	BSTree();
	~BSTree();
	bool Insert(Account *);
	// retrieve object, first parameter is object to retrieve
	// second parameter holds pointer to found object, NULL if not found
	bool Retrieve(const Account &, Account * &) const;
	// displays the contents of a tree to cout
	void Display() const;
	void Empty();
	bool isEmpty() const;
private:
	struct Node
	{
		Account *pAcct;
		Node *right;
		Node *left;
	};

	bool Retrieve(Node *, const Account &, Account * &) const;
	bool Insert(Node *, Account *);
	void DisplayNode(Node *) const;
	void DelNode(Node *);

	Node *root;
};
#endif
