#include <stdio.h>
#include <stdlib.h>

int main(){

	int ca, cb;
	FILE *fa, *fb;

	fa = fopen("test.c", "r"); //Open input file

	if(fa == NULL){
		printf("Cannot open file\n");
		exit(0);
	}

	fb = fopen("testOne.c", "w");//Open output file
	ca = getc(fa);
	while(ca != EOF){
		if(ca == '\t'){ //Check for tabs
			cb = ' ';
			putc(cb, fb);
		}
		else if(ca == ' '){ //Check for the first space of blank space
			putc(ca, fb);
			cb = getc(fa);
			while(cb == ' '){
				cb = getc(fa); //Skip the rest of the blank space
			}
			putc(cb, fb); //Put the character after the last space in the blank space
		}
		else
			putc(ca, fb);
		ca = getc(fa);
}
	fclose(fa);
	fclose(fb);

	return 0;
}
