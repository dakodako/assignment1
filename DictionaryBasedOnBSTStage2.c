//
//  DictionaryBasedOnBSTStage2.c
//  Assignment1
//
//  Created by Didi Chi on 31/08/2016.
//  Copyright © 2016 dako. All rights reserved.
//

#include "DictionaryBasedOnBSTStage2.h"
#include "general.h"
#include <string.h>

tree_stage2 insert_stage2(tree_stage2 T, dict_t* data){
    node_stage2_t *y = NULL;
    node_stage2_t *x = T;
    
    while(x != NULL){
        y = x;
        if(strcmp(data ->key, x -> data->key->key) == 0){
            x = x;
            printf("find an identical node\n");
            break;
        } else if(strcmp(data -> key, x ->data ->key->key) < 0){
            x = x -> left;
        } else {
            x = x -> right;
        }
                
    }
    
    node_stage2_t *newNode = (node_stage2_t*)general_malloc_with_error_handling((sizeof(node_stage2_t)));
    newNode -> right = NULL;
    newNode -> parent = y;
    newNode -> left = NULL;
    list newList = (list_node_t*)general_malloc_with_error_handling(sizeof(list_node_t));
    newList -> key = data;
    newList -> next = NULL;
    newNode -> data = newList;
    if(y == NULL){
        T = newNode;
    } else if(strcmp(newNode -> data -> key ->key, y -> data->key->key)== 0){
        //y -> data -> next = newList;
        y -> data = list_insert(y->data, data);
    } else{
        
        if(strcmp(newNode -> data -> key -> key, y -> data -> key -> key) < 0){
            y -> left = newNode;
        }else {
            y -> right = newNode;
        }
    }
    //newNode -> data = data;
    
    
    return T;
}
tree_stage2 insert_stage2_num_of_cmps(tree_stage2 T, dict_t* data,int* numOfCompare){
    *numOfCompare = 0;
    node_stage2_t *y = NULL;
    node_stage2_t *x = T;
    
    while(x != NULL){
        *numOfCompare = *numOfCompare + 1;
        y = x;
        if(strcmp(data ->key, x -> data->key->key) == 0){
            x = x;
            printf("find an identical node\n");
            break;
        } else if(strcmp(data -> key, x ->data ->key->key) < 0){
            x = x -> left;
        } else {
            x = x -> right;
        }
        
    }
    
    node_stage2_t *newNode = (node_stage2_t*)general_malloc_with_error_handling((sizeof(node_stage2_t)));
    newNode -> right = NULL;
    newNode -> parent = y;
    newNode -> left = NULL;
    list newList = (list_node_t*)general_malloc_with_error_handling(sizeof(list_node_t));
    newList -> key = data;
    newList -> next = NULL;
    newNode -> data = newList;
    if(y == NULL){
        T = newNode;
    } else if(strcmp(newNode -> data -> key ->key, y -> data->key->key)== 0){
        //y -> data -> next = newList;
        y -> data = list_insert(y->data, data);
    } else{
        
        if(strcmp(newNode -> data -> key -> key, y -> data -> key -> key) < 0){
            y -> left = newNode;
        }else {
            y -> right = newNode;
        }
    }
    //newNode -> data = data;
    
    
    return T;
}

node_stage2_t *search(node_stage2_t *T, char *k){
    
    while(T != NULL){
        if(strcmp(k, T->data->key->key) == 0){
            return T;
        } else if(strcmp(k, T->data->key->key) < 0){
            T = T -> left;
        } else {
            T = T -> right;
        }
    }
    return T;
}

