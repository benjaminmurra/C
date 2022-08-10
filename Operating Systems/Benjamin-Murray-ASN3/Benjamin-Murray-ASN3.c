#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

void *sorter(void *params);
void *merger(void *params);
int array_length;
int *list;
FILE *fileread; 
int finalArray[20];

typedef struct{
    int starting_index;
    int ending_index;
}parameters;

int *read_file(char *fname) {
    int bufsize = 200;
    char line[100];
    int index = 0;
    int *input = malloc(bufsize*sizeof(int));
    fileread = fopen(fname, "r"); // open file
    char *pt;
    fgets(line, 100, fileread);
    pt = strtok(line,",");
    while (pt != NULL) {
        input[index] = atoi(pt);
        index++;
        pt = strtok(NULL, ",");
    }
    
    fclose(fileread);  
    return input;
}

int main(int argc, const char * argv[]){

    int i;
    pthread_t thread[3];
    
    //create 2 sorting threads
    parameters *data1 = (parameters*)malloc(sizeof(parameters));
    data1->starting_index = 0;
    data1->ending_index = (20/2) - 1;
    pthread_create(&thread[0], 0, sorter, data1);

    parameters *data2 = (parameters *) malloc (sizeof(parameters));
    data2->starting_index = (20/2);
    data2->ending_index = 20 - 1;
    pthread_create(&thread[1], 0, sorter, data2);


    //wait to join threads
    for (i = 0; i < 2; i++){
        pthread_join(thread[i], NULL);
    }

    //create merging thread
    parameters *data3 = (parameters *) malloc(sizeof(parameters));
    data3->starting_index = 0;
    data3->ending_index = (20/2);

    pthread_create(&thread[2], 0, merger, data3);
    pthread_join(thread[2], NULL);
    return 0;
}

 //MERGE
void *merger(void *params){
    int r;
    parameters* para = (parameters*)(params); 
    int start = para->starting_index;
    int end = para->ending_index-1;

    for(int i = start; i < end; i++){
        for(int j=start; j < end - i; j++) {
            if(finalArray[j] > finalArray[j + 1]){
                r = finalArray[j];
                finalArray[j] = finalArray[j + 1];
                
                finalArray[j + 1] = r;
            }
        }
    }

    FILE * fPtr;
    fPtr = fopen("SortedIntegerList.txt", "w");
    int d;
    for(d=0; d<10; d++){
        fprintf(fPtr, "%d ", finalArray[d]);   
    }
    pthread_exit(0);
}

//Selection sort algorithm used 
void *sorter(void *params){
    list = read_file("IntegerList.txt");
    parameters* para = (parameters*)(params);
    int start = para->starting_index;
    int end = para->ending_index+1;
    int r;

    for(int i = start; i < end; i++){
        for(int j = start; j < end-i-1; j++){
            if(list[j] > list[j+1]){
                
                r = list[j];
                list[j] = list[j+1];
                list[j+1] = r;

            }
        }
    }

    for(int q = 0; q < end; q ++){
            finalArray[q] = list[q] ;
    }
    pthread_exit(0); 
}

