/*
Print the following keywords in capital letters with the row and column number
STRUCT
CHAR
INT
IF
DEFAULT
FLOAT
DO
DOUBLE
ELSE
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
	int ca, cb;
	FILE *fa, *fb;

	fa = fopen("testFile.c", "r"); //Open input file

	if(fa == NULL){
		printf("Cannot open file\n");
		exit(0);
	}

	//fb = fopen("testThree.c", "w");
	ca = getc(fa);
	char s[10];
	int row = 1, col = 0;//Initialise the row and column variables

	while(ca != EOF){

		//printf("row %d col %d\n", row, col);
		//cb = getc(fa);
		if(isalpha(ca)){//If current character is an alphabet, it might be a word
			//printf("In IF\n");
			fseek(fa, -1, SEEK_CUR);//Backspace one character
			fgets(s, sizeof(s), fa);//Get the next 10 characters
			//ca = getc(fa);

			//Check for a possibility

			if((strncmp(s, "default ", 8) == 0)){
				printf("DEFAULT %d %d\n", row, col);
			}
			else if((strncmp(s, "struct ", 7) == 0)){
				printf("STRUCT %d %d\n", row, col);
			}
			else if((strncmp(s, "double ", 7) == 0)){
				printf("DOUBLE %d %d\n", row, col);
				//fseek(fa, -7, SEEK_CUR);
			}
			else if((strncmp(s, "float ", 6) == 0)){
				printf("FLOAT %d %d\n", row, col);
			}
			else if((strncmp(s, "char ", 5) == 0)){
				printf("CHAR %d %d\n", row, col);
			}
			else if((strncmp(s, "else ", 5) == 0)){
				printf("ELSE %d %d\n", row, col);
			}
			else if((strncmp(s, "int ", 4) == 0)){
				printf("INT %d %d\n", row, col);
				//fseek(fa, -4, SEEK_CUR);
			}
			else if((strncmp(s, "if ", 3) == 0)){
				printf("IF %d %d\n", row, col);
			}
			else if((strncmp(s, "do ", 3) == 0)){
				printf("DO %d %d\n", row, col);
			}
			fseek(fa, -1, SEEK_CUR);//Pointer is moved, move one position back
		}
		//printf("row %d col %d\n", row, col);
		ca = getc(fa);
		//printf("%c\n", ca);
		col++;//On reading a new character, column value increases
		if(ca == '\n'){
			row += 1;//On the beginning of a line, row value has to be increased
			col = 0;//On the beginning of a new line, column value is Initialised to 022
		}
		//printf("row %d\n", row);
	}

	return 0;
}
