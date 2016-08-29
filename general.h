//
//  general.h
//  Assignment1
//
//  Created by Didi Chi on 29/08/2016.
//  Copyright © 2016 dako. All rights reserved.
//

#ifndef general_h
#define general_h

#include <stdio.h>

char* char_malloc_with_error_handling(size_t s);
void* general_malloc_with_error_handling(size_t s);
FILE *fopen_with_error_handling(const char* filename, const char* mode);

#endif /* general_h */
