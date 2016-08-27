#include "Entry.h"
struct node
{
	struct node *left; /*left child of the node*/
	struct node *right; /* right child of the node*/
	struct node *parent; // still thinking whether should add parent node or not
	dict_t data;
};

typedef struct node node_t;
typedt node_t *tree; // the root of the tree

// functions

tree insert(tree T, dict_t *data);