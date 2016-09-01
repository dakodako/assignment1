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
    //FILE *myFile = fopen_with_error_handling(argv[3], READING_MODE);
    FILE *myFile2 = fopen_with_error_handling(argv[1], READING_MODE);
    FILE *myFile3 = fopen_with_error_handling(argv[2], WRITING_MODE);
    
    tree newTree;
   // tree_stage2 newTree_stage2;
    // read file into array
    size_t bufsize = TOTALBUFFERSIZE;
    //int numberArray[100000];
    //int i;
    char *buffer;
    size_t characters;
    char *sep = TOKENIZER;

    char *searchKey = (char*)general_malloc_with_error_handling(MAXNAME*sizeof(char));
    //char searchKey[61];
    
    //buffer = (char*)malloc(bufsize*sizeof(char));
    //buffer = char_malloc_with_error_handling(bufsize);
    buffer = (char*)general_malloc_with_error_handling(bufsize*sizeof(char));
    //int *numOfChanges = (int*)malloc(sizeof(int));
    int *numOfChanges = (int*)general_malloc_with_error_handling(sizeof(int));
    /* previously for error handling
     if(buffer == NULL){
        exit(1);
    }*/
    //characters = getline(&buffer,&bufsize,myFile);
    characters = getline(&buffer, &bufsize,myFile2);
    //printf("%zu characters were read.\n",characters);
    while(characters != -1){
        dict_t *newEntry = (dict_t*)general_malloc_with_error_handling(sizeof(dict_t));
        //dict_t *newEntry = (dict_t*)malloc(sizeof(dict_t));
        newEntry -> key = NULL;
        newEntry -> value = NULL;
        int k = 0;
        //char *field = buffer;
        //printf("buffer = %s\n", buffer);
        char *word;
        word = strtok(buffer,sep);
        while( word != NULL){
            if(k == 0){
                //newEntry -> key = (char*)malloc((strlen(word) + 1)*sizeof(char));
                //newEntry -> key = char_malloc_with_error_handling(strlen(word)+1);
                newEntry -> key = (char*) general_malloc_with_error_handling((strlen(word) + 1)*sizeof(char));
                strcpy(newEntry -> key, word);
            } else {
                //newEntry -> value = (char*)malloc((strlen(word) + 1)*sizeof(char));
                //newEntry -> value = char_malloc_with_error_handling(strlen(word) + 1);
                newEntry -> value = (char*) general_malloc_with_error_handling((strlen(word) + 1)*sizeof(char));
                strcpy(newEntry->value, word);
            }
            //printf("token = %s\n", word);
            k = k + 1;
            word = strtok(NULL,sep);
        }
        //int numOfChanges = insert_numof_changes(newTree, newEntry);
        //newTree = insert(newTree, newEntry);
        newTree = insert_numof_changes(newTree, newEntry, numOfChanges);
       // newTree_stage2 = insert_stage2(newTree_stage2, newEntry);
        
        printf("num of compares = %d\n",*numOfChanges);
        //characters = getline(&buffer,&bufsize,myFile);

        characters = getline(&buffer,&bufsize,myFile2);
        
    }
    //free(numOfChanges);
    // search keys read from an input file in stdin
    int *numOfCompare = (int*) malloc(sizeof(int));
    while(fgets(searchKey,61,stdin)){
        if(searchKey[strlen(searchKey)-1] == '\n'){
            searchKey[strlen(searchKey)-1] = '\0';
        }
        //printf("%s\n",searchKey );
        list result_list = tree_search_locate_duplicate_return_num_of_compares(newTree, searchKey, numOfCompare);
        printf("%s - > %d\n",searchKey,*numOfCompare);
        fprint_list(result_list,myFile3,searchKey);
        
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
   
    
    fclose(myFile2);
    fclose(myFile3);
    
    return 0;
    
}