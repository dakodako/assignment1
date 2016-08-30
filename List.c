//
//  List.c
//  Assignment1
//
//  Created by Didi Chi on 28/08/2016.
//  Copyright © 2016 dako. All rights reserved.
//

#include "List.h"
// Given an dictionary entry value, the list_insert procedure splices value onto the front of the linked list
list list_insert(list L, dict_t* value){
    //printf("insert happening\n");
    
    list_node_t *newListNode = (list_node_t*)malloc(sizeof(newListNode));
    newListNode -> key = value;
    if(L == NULL){
      //  printf("starts to build a list\n");
        L = newListNode;
        L ->next = NULL;
    } else {
        //printf("add a node\n");
        newListNode->next = L;
        L = newListNode;
    }
   
    return L;
}
void print_list(list L){
    
    list_node_t *currentNode = L;
    if(currentNode == NULL){
        printf("NOT FOUND\n");
        return;
    }
    while(currentNode != NULL){
        printf("%s -> %s\n",currentNode->key->key,currentNode->key->value);
        currentNode = currentNode ->next;
    }
}
void deleteAllNodes(list L){
    
    while(L != NULL){
        list_node_t *temp = L;
        free(temp);
        L = L ->next;
    }
}

void fprint_list(list L, FILE* myFile,char*search){
    list_node_t *currentNode = L;
    if(currentNode == NULL){
        fprintf(myFile, "%s",search);
        fprintf(myFile, " -> ");
        fprintf(myFile, "NOTFOUND\n");
        return;
    }
    while(currentNode != NULL){
        //printf("writing\n");
        fprintf(myFile, "%s",currentNode->key->key);
        fprintf(myFile, " -> ");
        fprintf(myFile, "%s",currentNode->key->value);
        currentNode = currentNode -> next;
    }
}

/*void deleteAllNodes(node* start)
{
    while (start != null)
    {
        node* temp = start;
        free(temp);
        start = start -> next;
    }
}*/

