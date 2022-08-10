#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINE		80 /* 80 chars per line, per command */
#define BUFFER MAX_LINE*sizeof(char)


char history[10][100];

//shift history by 1
void moveHist() {
    for (int i = 9; i > 0; --i){
		strcpy(history[i], history[i - 1]);
	}
}

//display history
void displayHistory() {
	if(strcmp(history[0]," ")==0){
        printf("History is empty\n"); 
    } 
	else {
		printf("%s", "ID  PID  Command\n");
		for (int i = 0; i < 10; ++i){
			if(!strcmp(history[i]," ")==0) {
			
			printf("%i  %s ", i+1, history[i]);
			printf("\n");
            }
		}
    }
}

//create fork and execute command
void execute(char **argv){
    pid_t pid = fork();
	

    if (pid < 0) { 
          printf("*Unable to fork child process\n");
          exit(1);
    }
    else if (pid == 0) {  
        if (execvp(argv[0], argv) == -1) { 
               printf("Invalid command\n");
               exit(1);
        }
    }
    else { 
        wait(NULL);   
	}
}

//function to parse through user input and separate into tokens. Code was referenced and adapted from http://www.csl.mtu.edu/cs4411.ck/www/NOTES/process/fork/exec.html
void parse(char *input, char **argv){
    while(*input != '\0') {
		while(*input == ' ' || *input == '\t' || *input == '\n'|| *input == '&'){
			*input++ = '\0'; 
		}

        *argv++ = input;

        while(*input != '\0'&& *input != ' ' && *input !='\t' && *input != '\n'&& *input != '&') {
        	input++;    
		}  
    }
    *argv = '\0'; 
}

int main(void) {
	char *args[MAX_LINE/2 + 1];
    int should_run = 1;	

    for (int i = 0; i < 10; ++i){
    	strcpy(history[i]," ");

    }
	
    while (should_run){   
        printf("CSCI3120 >> ");

        char* input = (char*) malloc(sizeof(char*));

	    scanf("%[^\n]%*c", input);
        int length = strlen(input);

		//if user inputs a string that is not a history or ! command, add to history
	    if ((input[0]!='!') && strcmp(input,"history") != 0){
	    	moveHist(); 
		    strcpy (history[0],input);	
    	} 

		//if user enters history, call display function
		if (strcmp(input,"history") == 0 ) {
         	displayHistory();
        }

		//if command is empty
		else if (strcmp(input,"") == 0){
    	    printf("No command entered! \n");
						should_run = 0; 

        }

		//if user wants to exit
		else if (strcmp(input,"exit") == 0){
    	    printf("Exiting... \n");
			should_run = 0; 
        }

		//if user enters !!, print most recent command and execute it
	    else if (strcmp(input,"!!")==0){
			char* temp[50];

	    	printf(history[0]);
			printf("\n");
			moveHist(); 
			strcpy (history[0],history[1]);
	    	strcpy(temp, history[0]);

		    parse(temp, args);
			execute(args);
		}

		//handling "!N requests"
    	else if (((input[0]=='!')==1 && (input[1]=='!') == 0)){
			int n;

			//isolate value n from input
			for (int i = 0; i < 10; ++i){
				if(input[length - 1] == i+'0'){ 
					n = i - 1;
				}
			}
			
        	if (strcmp(history[n], " ") == 0) {
        		printf("Such a commandis NOT in history!\n"); 
			}
        
       		else if (n > 10) {
        		printf("history not recorded his far"); 
			}
        	       

    		else {
           		char* temp[50];
    	   		strcpy(temp, history[n]);
		    	moveHist(); 
		   		strcpy (history[0],temp);


	    		parse(temp, args);
				execute(args);
			}
		}
		//for all other commands, parse and execute as normal
    	else {
			parse(input, args);
			execute(args);
		}
	}

	return 0;
}