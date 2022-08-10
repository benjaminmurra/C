#include <stdio.h>
#include <string.h>

int main(){
    int i;
    int j = 0;
    int count = 0;  
    //initialize variable str to hold full string and newStr to hold individual words
    char str[200];
    char newStr[200][200];
    //get input from user
    printf("Please Enter Your Sentence: ");
    fgets(str, sizeof(str), stdin);	
 
    for(i = 0; i <= (strlen(str)); i++){
        //When a space or NULL value is found in str[], assign NULL into newStr[], and continue to next word
        if (str[i] =='\0' || str[i] ==' '){
            newStr[count][j] = '\0';
            count++; 
            j = 0;    
        }
        else {
            newStr[count][j] = str[i];
            j++;
        }
    }
     //create file 
    FILE * fPtr;
    fPtr = fopen("Output.txt", "w");

    //print individual words and insert them into .txt file
    for (i = 0; i < count; i++){
        printf("%s\n", newStr[i]);
        fputs(newStr[i], fPtr);
        fputs("\n", fPtr);
    }
    fclose(fPtr);

    return 0;
}