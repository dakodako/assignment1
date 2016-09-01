#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char** argv){
	char *searchKey = (char*)malloc(61*sizeof(char));

	while(fgets(searchKey,61,stdin)){
		if(searchKey[strlen(searchKey)-1] == '\n'){
			searchKey[strlen(searchKey)-1] = '\0';
		}
		printf("%s\n",searchKey );
	}
	/*fgets(searchKey,61,stdin);
	if(searchKey[strlen(searchKey)-1] == '\n'){
		searchKey[strlen(searchKey)-1] = '\0' ;
	}
	//scanf("%s",searchKey);
	printf("%s\n", searchKey);*/
	/*size_t characters;
	char *buffer;
	buffer = (char*)malloc(61*sizeof(char));
	size_t bufsize = 61;
	while(fgets(buffer,60,stdin)){
		printf("%s\n",buffer );
	}*/
}
