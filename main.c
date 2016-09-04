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
#include "DictionaryBasedOnBSTStage2.h"
#include "general.h"
#define READING_MODE "r"
#define WRITING_MODE "w"
#define OUTPUTFILENAME "outputfile"


#define NUMOFFIELDS 2
#define NAMESIZE 430
#define TOTALBUFFERSIZE 1530
#define TOKENIZER ","
#define MAXNAME 61
//void getFields(char *field1, char *field2, char *fileName, size_t bufsize, char *sep);
int main(int argc, char *argv[]){
    if(argc != 3){
        perror("instructions:\n");
        exit(1);
    }
    FILE *dataFile = fopen_with_error_handling(argv[1], READING_MODE);
    FILE *outputFile = fopen_with_error_handling(argv[2], WRITING_MODE);
    
    tree newTree = makeDict_stage1();
    size_t bufsize = TOTALBUFFERSIZE;
    size_t characters;
    char *sep = TOKENIZER;
    char *searchKey = (char*)general_malloc_with_error_handling(MAXNAME*sizeof(char));
    char *buffer = (char*)general_malloc_with_error_handling(bufsize*sizeof(char));
    int *numOfCmps = (int*)general_malloc_with_error_handling(sizeof(int));
    characters = getline(&buffer, &bufsize,dataFile);
    while(characters != -1){
        dict_t *newEntry = (dict_t*)general_malloc_with_error_handling(sizeof(dict_t));
        newEntry -> key = NULL;
        newEntry -> value = NULL;
        int k = 0; // k is a counter: 
        char *word = strtok(buffer,sep);
        while( word != NULL){
            if(k == 0){ // when k = 0, the input field is <name>;
                newEntry -> key = (char*) general_malloc_with_error_handling((strlen(word) + 1)*sizeof(char));
                strcpy(newEntry -> key, word);
            } else { // when k = 1, the input field is <data>
                newEntry -> value = (char*) general_malloc_with_error_handling((strlen(word) + 1)*sizeof(char));
                strcpy(newEntry->value, word);
            }
            k = k + 1;
            word = strtok(NULL,sep);
        }
        newTree = insert(newTree, newEntry);
        //newTree = insert_numof_changes(newTree, newEntry, numOfCmps);
        //printf("num of compares = %d\n",*numOfCmps);
        
        // getting data from the next line
        characters = getline(&buffer,&bufsize,dataFile);
        
    }
    free(numOfCmps);
    // search keys read from an input file in stdin
    int *numOfCompare = (int*) malloc(sizeof(int));
    while(fgets(searchKey,MAXNAME,stdin)){
        if(searchKey[strlen(searchKey)-1] == '\n'){
            searchKey[strlen(searchKey)-1] = '\0';
        }
        //printf("%s\n",searchKey );
        list result_list = tree_search_locate_duplicate_return_num_of_compares(newTree, searchKey, numOfCompare);
        printf("%s - > %d\n",searchKey,*numOfCompare);
        fprint_list(result_list,outputFile,searchKey);
        deleteAllNodes(result_list);
    }
   /*bufsize = NAMESIZE;
    int *numOfCompare = (int*) malloc(sizeof(int));
    free(buffer);
    buffer = (char*)general_malloc_with_error_handling(NAMESIZE *sizeof(char));
    if(stdin == NULL){
        perror("input file cannot be read\n");
        exit(1);
    }
    
    characters = getline(&buffer, &bufsize, myFile);
   // printf("%s\n",buffer);
    char *word = strtok(buffer, sep);

    while(word != NULL){
        //printf("search word = %s\n",word);
        list result_list = tree_search_locate_duplicate_return_num_of_compares(newTree, word, numOfCompare);
       // print_list(result_list);
        printf("%s - > %d\n",word,*numOfCompare);
        fprint_list(result_list, myFile3, word);
        deleteAllNodes(result_list);
        word = strtok(NULL, sep);
    }*/
   
    
    fclose(dataFile);
    fclose(outputFile);
    
    return 0;
    
}