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