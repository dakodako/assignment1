#include <stdlib.h>
#include <stdio.h>
struct dict
{
	char *key; /* in yelp database, the key will be <name>*/
	char *value; /* in yelp database, the value will be <data>*/
};
typedef struct dict dict_t;
