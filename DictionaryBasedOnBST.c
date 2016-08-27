
#include "DictionaryBasedOnBST.h"
#include <string.h>
tree insert(tree T, dict_t *data){
	node_t *y = NULL;
	node_t *x = T;
	int cmp = strcmp(data -> key,x->key);//comparing keys
	while(x != NULL){
		y = x;
		if(cmp <= 0){
			x = x -> left;
		} else {
			x = x -> right;
		}
	}
	node_t *newNode = (node_t*)malloc(sizeof(node_t));
	newNode -> parent = y;
	newNode -> right = NULL;
	newNode -> left = NULL;
	newNode -> data = data;
	if(y == NULL){
		T = newNode;
	} else if (strcmp(newNode->data->key,y->data->key) <= 0){
		y-> left = newNode;
	} else {
		y-> right = newNode;
	}
	return T;
}

