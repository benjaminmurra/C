#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Book
{
	int characterCount;
	int lineCount;
	int maxLineCount;
	char **lines;
}Book;
