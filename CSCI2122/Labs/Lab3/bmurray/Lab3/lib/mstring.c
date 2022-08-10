#include <stdio.h>
#include "mstring.h"

void strrev(char *str) {
	//calcualte the length of str and store in int
	int length=0;
	while(str[length]!='\0'){
		length++;
	}


	int i=0 ,j=length - 1;
	//reverse order of letters based on position of letter
	while(i < j) {
		char temp=str[i];
		str[i]=str[j];
		str[j]=temp;
		i++;
		j--;
	}
}
