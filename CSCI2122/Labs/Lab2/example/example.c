#include <stdio.h>
#include <stdlib.h>

int changeNumber(int number){
	int newNumber=number + 15;
	newNumber = newNumber * 12;
	newNumber =newNumber - 15;
	newNumber /=5;
	newNumber %=150;
	return newNumber;
}

int main (int argc, char** argv) {
    int one, two, three, four;

    printf("enter four intergers: ");

    scanf ("%d %d %d %d", &one, &two, &three, &four);
    printf("Numbers received: %d %d %d %d \n", one, two, three, four);
    
    one   = changeNumber(one);
    two   = changeNumber(two); 
    three = changeNumber(three); 
    four  = changeNumber(four); 
    printf("Updated numbers : %d %d %d %d \n", one, two, three, four); 
    

    char s1[10], s2[10], s3[10], s4[10];
    printf("converting integers to Strings...");
    sprintf(s1, "%d", one);
    sprintf(s2, "%d", two);  
    sprintf(s3, "%d", three);  
    sprintf(s4, "%d", four); 
    printf("done");

   printf("Testing ATOI Output: %d %s %d %d \n", atoi (s1), s2, atoi(s3), four); 


    return 0;
}


