/* #include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char** argv){
	
	int fd;
	int ret;
	fd = open("out.txt",O_CREAT | O_APPEND |O_WRONLY);
	if(fd < 0){
		perror("open");
		exit(1);
	}
	ret = dup2(fd,1);
	if(ret <0){
		perror("dup2");
		exit(1);
	}
	system("ls /tmp");
	close(fd);
	return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFERSIZE 200


int main (int argc, char **argv){
	/*char buffer[BUFFERSIZE];
	fgets(buffer, BUFFERSIZE, stdin);
	printf("Read: %s\n",buffer );*/
	FILE *myFile ,*myFile2;
	
	myFile2 = fopen(argv[1],"w");
	size_t bufsize = 1529;
	char *buffer;
	size_t characters;
	char *sep = ",";
	buffer = (char*)malloc(bufsize *sizeof(char));
	if(buffer == NULL){
		exit(1);
	}
	characters = getline(&buffer, &bufsize, stdin);
	printf("%zu characters were read\n", characters);
	while(characters != -1){
		char *word;
		word = strtok(buffer,sep);
		int k = 0;
		while(word != NULL){
			if(k == 0){
				fprintf(myFile2, "%s->", word);
			} else {
				fprintf(myFile2, "%s", word);
			}
			//fprintf(myFile2, "%s\n", word);
			word = strtok(NULL,sep);
			k = k + 1;
		}
		printf("%zu characters were read\n",characters );
		characters = getline(&buffer,&bufsize,stdin);
	}
	/*char *name;
	char *value;

	name = (char*)malloc(430*sizeof(char));
	value = (char*)malloc(1100*sizeof(char));

	if(stdin == NULL){
		fprintf(stderr, "Can't open input file stdin\n" );
	}


	while (fscanf(stdin, "%s ,%s", name, value) != EOF){
  		fprintf(myFile2, "%s %s\n", name, value);
  	}*/
   







	return 0;
}