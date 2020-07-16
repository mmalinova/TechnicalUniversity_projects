#include "stdafx.h"
#include "lexicalUnitt.h"
#include "binTree.h"
#include <string.h>
#include <iostream>

using namespace std;
//--------------------------------------------------------------------------------------------------------
btree::btree()
{
	root = NULL;
}
//--------------------------------------------------------------------------------------------------------
btree::~btree()
{
	destroy_tree();
}
//--------------------------------------------------------------------------------------------------------
void btree::insert(lexicalUnit &lu)
{
	if (root != NULL)
		insert(lu, root);
	else
	{
		root = new node;
		root->key_value = lu;
		root->left = NULL;
		root->right = NULL;
	}
}
//--------------------------------------------------------------------------------------------------------
void btree::insert(lexicalUnit &lu, node *leaf)
{
	if (strcmp(lu.getIdentificator(), leaf->key_value.getIdentificator()) < 0)
	{
		if (leaf->left != NULL)
			insert(lu, leaf->left);
		else
		{
			leaf->left = new node;
			leaf->left->key_value = lu;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}
	else if (strcmp(lu.getIdentificator(), leaf->key_value.getIdentificator()) >= 0)
	{
		if (leaf->right != NULL)
			insert(lu, leaf->right);
		else
		{
			leaf->right = new node;
			leaf->right->key_value = lu;
			leaf->right->left = NULL;
			leaf->right->right = NULL;
		}
	}
}
//--------------------------------------------------------------------------------------------------------
node *btree::search(char *pIdentificator)
{
	return search(pIdentificator, root);
}
//--------------------------------------------------------------------------------------------------------
node *btree::search(char *pIdentificator, node *leaf)
{
	if (leaf != NULL)
	{
		if (strcmp(pIdentificator, leaf->lu.getIdentificator()) == 0)
			return leaf;
		if (strcmp(pIdentificator, leaf->lu.getIdentificator()) < 0)
			return search(pIdentificator, leaf->left);
		else
			return search(pIdentificator, leaf->right);
	}
	else return NULL;
}
//--------------------------------------------------------------------------------------------------------
void btree::destroy_tree()
{
	destroy_tree(root);
}
//--------------------------------------------------------------------------------------------------------
void btree::destroy_tree(node *leaf)
{
	if (leaf != NULL)
	{
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}
//--------------------------------------------------------------------------------------------------------
void btree::print()
{
	print(root, 0);
}
//--------------------------------------------------------------------------------------------------------
void btree::print(node *leaf, int delta)
{
	int i;
	if (leaf != NULL)
	{
		if (leaf->right)
			print(leaf->right, delta + 1);
		for (i = 1; i <= delta; i++)
			cout << "\t";
		leaf->key_value.print();
		cout << endl;
		if (leaf->left)
			print(leaf->left, delta + 1);
	}
}
//--------------------------------------------------------------------------------------------------------