//
//  DictionaryBasedOnBSTStage2.h
//  Assignment1
//
//  Created by Didi Chi on 31/08/2016.
//  Copyright © 2016 dako. All rights reserved.
//

#ifndef DictionaryBasedOnBSTStage2_h
#define DictionaryBasedOnBSTStage2_h

#include <stdio.h>
#include "List.h"
struct node_stage2 {
    struct node_stage2 *left;
    struct node_stage2 *right;
    struct node_stage2 *parent;
    list data;
};

typedef struct node_stage2 node_stage2_t;
typedef node_stage2_t* tree_stage2;



/* functions */
tree_stage2 insert_stage2(tree_stage2 T, dict_t* data);
tree_stage2 insert_stage2_num_of_cmps(tree_stage2 T, dict_t* data, int* numOfCompare);
node_stage2_t *search(tree_stage2 T, char *key);
#endif /* DictionaryBasedOnBSTStage2_h */
