#include <stdio.h>
#include "pascal.h"

void pascal(int rows){
	int i, j;
	int result = 1;

	//run through loop for each row+1
	for(i = 0; i < rows + 1; i++){

		for(j = 0; j <= i; j++){

			//if i or j are 0, the result will always be 1 as it is the end of the rows
			if (j == 0 || i == 0){
				result = 1;
			}
			//if j || i !=1
			else{
				result = result * (i - j + 1) / j;
			}
			//once the loops are complete, print result
			if(i == rows){
				printf("%d ",result);
			}
		}
	}
	printf("\n");
}

