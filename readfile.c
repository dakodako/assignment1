#include<stdio.h>

int main(int argc, char *argv[]){
	FILE *myFile;

	myFile = fopen("inputs.txt","r");//r: opens for reading
	// read file into array

	int numberArray[100000];
	int i;

	for(i = 0; i < 100000; i ++){
		fscanf(myFile,"%d",&numberArray[i]);
	}
	for(i = 0; i < 100000; i ++){
		printf("Number is %d\n\n", numberArray[i]);
	}
	fclose(myFile);

	return 0;

}