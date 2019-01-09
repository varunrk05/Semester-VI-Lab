/*
	Check for #include, #define, #if preprocessor directives adn remove them
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int ca, cb;
	FILE *fa, *fb, *fc;

	fa = fopen("test.c", "r"); //Open input file

	if(fa == NULL){
		printf("Cannot open file\n");
		exit(0);
	}

	//char *s1 = "include", *s2 = "define", *s3 = "if";

	fb = fopen("testTwo.c", "w");//Open output file
	ca = getc(fa);
	//printf("Before loop\n");
	while(ca != EOF){
		if(ca == '#'){
			//printf("# found\n");
			// cb = getc(fa);
			// fc = fopen("appendWord.c", "w");
			// while(cb != ' '){
			// 	putc(cb, fc);
			// 	cb = getc(fa);
			// }

			//int cc = fseek(fc, 0, SEEK_SET);
			char s[8];
			fgets(s, sizeof(s), fa);//Get the next 8 characters
			// while(cc != EOF || cc != ' ')
			// 	s += (char)cc;
			printf("%s\n", s);

			if((strncmp(s,"include",7) == 0) || (strncmp(s,"define",6) == 0) || (strncmp(s,"if",2) == 0)){//Check for a possible case
				while(ca != '\n')
					ca = getc(fa);
				putc(ca, fb);
			}
			else{
				ca = fseek(fa, 0, SEEK_SET);//If not a preprocessor directive, copy the entire line
				putc(ca, fb);
			}
		}
		else
			putc(ca, fb);
		ca = getc(fa);
	}

	return 0;
}
