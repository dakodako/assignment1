//
//  main.c
//  Assignment1
//
//  Created by Didi Chi on 27/08/2016.
//  Copyright © 2016 dako. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DictionaryBasedOnBST.h"
#include "general.h"
#define READING_MODE "r"
#define WRITING_MODE "w"


#define NUMOFFIELDS 2
#define TOTALBUFFERSIZE 1530
#define TOKENIZER ","

int main(int argc, char *argv[]){
    FILE *myFile;
    
    tree newTree;
    
    myFile = fopen_with_error_handling("test2.csv", READING_MODE);
    // read file into array
    size_t bufsize = TOTALBUFFERSIZE;
    char *buffer;
    size_t characters;
    char *sep = TOKENIZER;
    buffer = (char*)general_malloc_with_error_handling(bufsize*sizeof(char));
    int *numOfChanges = (int*)general_malloc_with_error_handling(sizeof(int));
    /* previously for error handling
     if(buffer == NULL){
        exit(1);
    }*/
    characters = getline(&buffer,&bufsize,myFile);
    printf("%zu characters were read.\n",characters);
    while(characters != -1){
        dict_t *newEntry = (dict_t*)general_malloc_with_error_handling(sizeof(dict_t));
        newEntry -> key = NULL;
        newEntry -> value = NULL;
        /* k is a counter, when k == 0, the reading is <name> field, when k == 1, the reading is <data> field*/
        int k = 0;
        char *word;
        word = strtok(buffer,sep);
        while( word != NULL){
            if(k == 0){
                //newEntry -> key = char_malloc_with_error_handling(strlen(word)+1);
                newEntry -> key = (char*)general_malloc_with_error_handling((strlen(word) + 1)*sizeof(char));
                strcpy(newEntry -> key, word);
            } else {
                //newEntry -> value = (char*)malloc((strlen(word) + 1)*sizeof(char));
                //newEntry -> value = char_malloc_with_error_handling(strlen(word) + 1);
                newEntry -> value = (char*)general_malloc_with_error_handling((strlen(word) +1)*sizeof(char));
                strcpy(newEntry->value, word);
            }
            //printf("token = %s\n", word);
            k = k + 1;
            word = strtok(NULL,sep);
        }
        //int numOfChanges = insert_numof_changes(newTree, newEntry);
       // newTree = insert(newTree, newEntry);
        newTree = insert_numof_changes(newTree, newEntry, numOfChanges);
        printf("num of compares = %d\n",*numOfChanges);
        characters = getline(&buffer,&bufsize,myFile);
    }
    
    
    
   // inOrderTreeWalk(newTree);
    /*for(i = 0; i < 100000; i ++){
     fscanf(myFile,"%d",&numberArray[i]);
     }
     for(i = 0; i < 100000; i ++){
     printf("Number is %d\n\n", numberArray[i]);
     }*/
    //dict_t *result = tree_search(newTree, "1900 Mexican Grill");
   // node_t *result_node = iterative_tree_search(newTree, "1900 Mexican Grill");
    list result_list = tree_search_locate_duplicate(newTree, "Alvin");
    //printf("%s\n",result_list->key->key);
    //printf("%s\n",result_list->key->value);
    //printf("%s\n",result_list->next->key->key);
    //printf("%s\n",result_list->next->key->value);
    print_list(result_list);
    /*printf("\n");
    if(result_node == NULL){
        printf("1900 Mexican Grill -> NOT FOUND\n");
    } else {
        printf("1900 Mexican Grill -> %s\n",result_node ->data->value);
    }*/
    
    fclose(myFile);
    
    return 0;
    
}