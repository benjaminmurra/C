#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define TRUE 1
#define BUFFER_SIZE 5

typedef int buffer_item;
buffer_item buffer[BUFFER_SIZE];
pthread_mutex_t mutex;
sem_t empty;
sem_t full;

int insertP = 0;
int removeP = 0;

int insert_item(buffer_item item)
{
	sem_wait(&empty);
	
	pthread_mutex_lock(&mutex);
	buffer[insertP++] = item;

	insertP =insertP % 5;

	pthread_mutex_unlock(&mutex);
    sem_post(&full);

	return 0;
}

int remove_item(buffer_item *item)
{
	sem_wait(&full);

	pthread_mutex_lock(&mutex);
	*item = buffer[removeP];

	buffer[removeP++] = -1;
	removeP = removeP % 5;

	pthread_mutex_unlock(&mutex);
	sem_post(&empty);

	return 0;
}

void *producer(void *param)
{
	buffer_item random;
	int sleepRand;

	while(TRUE)
	{
		sleepRand = rand() % 5;
		sleep(sleepRand);
		random = rand();

		insert_item(random);

        printf("Producer %d: produced %d into buffer[%d] \n", *((int *)param), random, insertP);
	}

}

void *consumer(void *param)
{
	buffer_item random;
	int sleepRand;

	while(TRUE)
	{
		sleepRand = rand() % 5;
		sleep(sleepRand);

		remove_item(&random);
		printf("Consumer %d: consumed %d from buffer[%d] \n", *((int *)param), random, removeP);
	}
}

int main(int argc, char *argv[])
{
	int sleepTime, producerN, consumerN, i, j, k;
    int prodNumber[producerN], consNumber[consumerN];
    pthread_t prod[producerN], con[consumerN];

	sleepTime = atoi(argv[1]);
	producerN = atoi(argv[2]);
	consumerN = atoi(argv[3]);

    //Initalize buffer slots to -1
    for(i = 0; i < BUFFER_SIZE; i++){
        buffer[i] = -1;
    } 


	//Initialize the the locks
	pthread_mutex_init(&mutex, NULL);
	sem_init(&empty, 0, 1); 
	sem_init(&full, 0, 0);

	//Generate producer threads
	for(i = 0; i < producerN; i++)
	{
        prodNumber[i] = i;
		pthread_attr_t attr;
		pthread_attr_init(&attr);
		pthread_create(&prod[i], &attr, producer, (void *)&prodNumber[i]);
	}

    //generate consumer threads

	for(j = 0; j < consumerN; j++)
	{
        consNumber[j] = j;
		pthread_attr_t attr;
		pthread_attr_init(&attr);
		pthread_create(&con[j], &attr, consumer, (void *)&consNumber[j]);
	}

	//Sleep specified time
	sleep(sleepTime);
	return 0;
}
