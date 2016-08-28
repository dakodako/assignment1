//
//  List.h
//  Assignment1
//
//  Created by Didi Chi on 28/08/2016.
//  Copyright © 2016 dako. All rights reserved.
//

#ifndef List_h
#define List_h

#include <stdio.h>
#include <stdlib.h>
#include "Entry.h"
struct list_node {
    dict_t *key;
    struct list_node* next;
};
typedef struct list_node list_node_t;
typedef list_node_t *list;
//typedef struct list list_t;

//functions

list list_insert(list L, dict_t* value);
void print_list(list L);
#endif /* List_h */
