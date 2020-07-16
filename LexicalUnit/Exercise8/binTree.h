#pragma once
#include "lexicalUnitt.h"

//--------------------------------------------------------------------------------------------------------
struct node {
	lexicalUnit lu;
	lexicalUnit key_value;
	node *left;
	node *right;
};
class btree {
private:
	void destroy_tree(node *leaf);
	void insert(lexicalUnit &lu, node *leaf);
	node *search(char *pIdentificator, node *leaf);
	void print(node *leaf, int delta);
	node *root;
public:
	btree();
	~btree();
	void insert(lexicalUnit &lu);
	node *search(char *pIdentificator);
	void destroy_tree();
	void print();
};