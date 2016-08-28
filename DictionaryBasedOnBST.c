
#include "DictionaryBasedOnBST.h"
#include <string.h>
tree insert(tree T, dict_t *data){
    node_t *y = NULL;
    node_t *x = T;
    /*for testing*/
    if(x == NULL){
        printf("tree is empty\n");
    }
    //int cmp = strcmp(data -> key,x -> data ->key);//comparing keys
    while(x != NULL){
        y = x;
       // printf("add node\n");
        if(strcmp(data -> key,x -> data ->key) <= 0){
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
tree insert_numof_changes(tree T, dict_t *data, int *numOfChanges){
    *numOfChanges = 0;
    node_t *y = NULL;
    node_t *x = T;
    /*for testing*/
    if(x == NULL){
        printf("tree is empty\n");
    }
    //int cmp = strcmp(data -> key,x -> data ->key);//comparing keys
    while(x != NULL){
        *numOfChanges = *numOfChanges + 1;
        y = x;
        //printf("add node\n");
        if(strcmp(data -> key,x -> data ->key) <= 0){
            // printf("less\n");
            x = x -> left;
        } else {
             //printf("more\n");
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

void inOrderTreeWalk(tree T){
    if(T != NULL){
        inOrderTreeWalk(T->left);
        printf("the key is %s\n",T -> data->key);
        printf("the value is %s\n",T -> data -> value);
        inOrderTreeWalk(T->right);
    }
}
dict_t* tree_search(node_t *x, char *k){
    if(x == NULL){
        return NULL;
    }
    if(strcmp(k, x->data->key) == 0){
        return x->data;
    }
    if(strcmp(k, x->data->key) <= 0){
        return tree_search(x->left, k);
    } else {
        return tree_search(x->right, k);
    }
}
node_t* iterative_tree_search(node_t*x, char *k){
    while(x != NULL && strcmp(k, x->data->key) != 0){
        if(strcmp(k, x->data->key)<=0){
            x = x ->left;
        } else {
            x = x -> right;
        }
    }
    return x;
}

