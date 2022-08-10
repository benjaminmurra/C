#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"
#include <stdbool.h>

Book* make_book(int maxLinesCount){
	Book* pBook = (Book*)malloc(sizeof(Book));
	if (pBook != NULL){

		pBook->characterCount = 0;
		pBook->lineCount = 0;
		pBook->maxLineCount = maxLinesCount;
		pBook->lines = malloc(maxLinesCount * sizeof(char*));
		for (int i = 0; i < maxLinesCount; i++){

			pBook->lines[i] = NULL;
		}
	}
	return pBook;
}
void burn_book(Book *pBook)
{
	if (pBook != NULL)
	{
		if (pBook->lines != NULL)
		{
			for (int i = 0; i < pBook->maxLineCount; i++)
			{
				if (pBook->lines[i] != NULL)
				{
					free(pBook->lines[i]);
					pBook->lines[i] = NULL;
				}
			}
			free(pBook->lines);
			pBook->lines = NULL;
		}
		free(pBook);
	}
}
bool save_book(Book *pBook, char* strOutFileName)
{
	if (pBook != NULL)
	{

		FILE *Out_file = fopen(strOutFileName, "w");
		if (Out_file != NULL)
		{
			for (int i = 0; i < pBook->maxLineCount; i++)
			{
				if (pBook->lines[i] != NULL)
				{

					fprintf(Out_file, "%s", pBook->lines[i]);
				}
			}

			fclose(Out_file);
			return true;
		}
	}
	return false;
}
bool fill_book(Book *pBook, char* strInFileName){
	if (pBook != NULL) {
		FILE *In_file = fopen(strInFileName, "r");

		if (In_file != NULL) {
			
			int charsPerLineCount = 0;
			 char inputBuff[200] = { '\0' };
			int count = 0;
			char c;
			for (c = getc(In_file); c != EOF; c = getc(In_file)){ 
				if (c == '\n'){ // Increment count if this character is newline 
					++pBook->lineCount;
				}
			}
			printf("Total number of lines after reading the file = %d\n", pBook->lineCount);
			printf("Total number of count after reading the file = %d\n", count);

			while ((count < pBook->lineCount) && fgets(inputBuff, sizeof(inputBuff), In_file) != NULL)  {
				
				charsPerLineCount = strlen(inputBuff);

				printf("Total number of chars after reading the file = %d\n", charsPerLineCount); 
				printf("Total number of count after reading the file = %d\n", count); 
				pBook->lines[count] = (char*)malloc(charsPerLineCount + 1 * sizeof(char));

				strncpy(pBook->lines[count], inputBuff, charsPerLineCount);

				pBook->lines[count][charsPerLineCount] = '\0';

				++count;

				pBook->characterCount += charsPerLineCount;
			}

			fclose(In_file);
			return true;
		}
		else {
		}
	}

	return false;
}

int edit_book(Book *pBook, char* inputWord){
	int charsPerLineCount = 0;
	int linesRemoved = 0;
	if (pBook != NULL)  {
		char *ptr = NULL;
		for (int i = 0; i < pBook->lineCount; i++) {
			if (pBook->lines[i] != NULL) {
				ptr = strstr(pBook->lines[i], inputWord);
				if (ptr != NULL) {

					charsPerLineCount = strlen(pBook->lines[i]);
					pBook->characterCount -= charsPerLineCount;

					 free(pBook->lines[i]);
					 pBook->lines[i] = NULL;
					 ++linesRemoved;
					 --(pBook->lineCount);
				}
			}
		}
	}

	return linesRemoved;
}

void read_book(Book *pBook)
{
	for (int i = 0; i < pBook->maxLineCount; i++)
	{
		if (pBook->lines[i] != NULL)
		{
			printf("%s", pBook->lines[i]);
		}
	}
	return;
}


