#ifndef inputnoutput_h
#define inputnoutput_h

#include <stdio.h>
#include "Entry.h"
struct node
{
    struct node *left; /*left child of the node*/
    struct node *right; /* right child of the node*/
    struct node *parent; // still thinking whether should add parent node or not
    dict_t *data;
};

typedef struct node node_t;
typedef node_t *tree; // the root of the tree

// functions

tree insert(tree T, dict_t *data);
tree insert_numof_changes(tree T, dict_t *data,int *numOfChanges);
dict_t* tree_search(node_t *x, char *k);
node_t* iterative_tree_search(node_t *x, char *k);

// test functions

void inOrderTreeWalk(tree T);
#endif /* inputnoutput_h */
