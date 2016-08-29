//
//  general.c
//  Assignment1
//
//  Created by Didi Chi on 29/08/2016.
//  Copyright © 2016 dako. All rights reserved.
//

#include "general.h"
#include <stdlib.h>

char* char_malloc_with_error_handling(size_t s){
    char *newChar = (char*)malloc(s * sizeof(char));
    if(newChar == NULL){
        perror("error, characters cannot be initialized");
        exit(1);
        
    }
    
    return newChar;
}

void* general_malloc_with_error_handling(size_t s){
    void* newSpace = malloc(s);
    if(newSpace == NULL){
        perror("error, malloc failed\n");
        exit(1);
    }
    return newSpace;
}
FILE *fopen_with_error_handling(const char* filename, const char* mode){
    FILE *myFile = fopen(filename, mode);
    if(myFile == NULL){
        perror("the file could not be opened\n");
        exit(1);
    }
    return myFile;
}