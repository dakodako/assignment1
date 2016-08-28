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
#define NUMOFFIELDS 2
#define TOTALBUFFERSIZE 1530

//void getFields(char *field1, char *field2, char *fileName, size_t bufsize, char *sep);
int main(int argc, char *argv[]){
    FILE *myFile;
    
    tree newTree;
    
    myFile = fopen("test2.csv","r");//r: opens for reading
    //myFile = fopen("yelp_academic_dataset_business_alternative.csv","r");
    // read file into array
    size_t bufsize = TOTALBUFFERSIZE;
    //int numberArray[100000];
    //int i;
    char *buffer;
    size_t characters;
    char *sep = ",";
    
    buffer = (char*)malloc(bufsize*sizeof(char));
    int *numOfChanges = (int*)malloc(sizeof(int));
    if(buffer == NULL){
        exit(1);
    }
    characters = getline(&buffer,&bufsize,myFile);
    printf("%zu characters were read.\n",characters);
    while(characters != -1){
        dict_t *newEntry = (dict_t*)malloc(sizeof(dict_t));
        newEntry -> key = NULL;
        newEntry -> value = NULL;
        int k = 0;
        //char *field = buffer;
        //printf("buffer = %s\n", buffer);
        char *word;
        word = strtok(buffer,sep);
        while( word != NULL){
            if(k == 0){
                newEntry -> key = (char*)malloc((strlen(word) + 1)*sizeof(char));
                strcpy(newEntry -> key, word);
            } else {
                newEntry -> value = (char*)malloc((strlen(word) + 1)*sizeof(char));
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
    
    
    
    //inOrderTreeWalk(newTree);
    /*for(i = 0; i < 100000; i ++){
     fscanf(myFile,"%d",&numberArray[i]);
     }
     for(i = 0; i < 100000; i ++){
     printf("Number is %d\n\n", numberArray[i]);
     }*/
    dict_t *result = tree_search(newTree, "1st Care Family");
    if(result == NULL){
        printf("1st Care Family Medicine -> NOT FOUND\n");
    } else {
        printf("1st Care Family Medicine -> %s\n",result->value);
    }
    fclose(myFile);
    
    return 0;
    
}