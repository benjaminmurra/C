#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *file;

typedef struct task
{
    char name[5];
    int arrival;
    int burst;
    int wait;
    int flag;
} task;

// FCFS Algorithm
void FCFS(task T[], int n, FILE *fPtr)
{
    task tasks[10];
    int waitTot = 0;
    float waitAvg = 0.0;

    for (int i = 0; i < n; i++)
    {
        tasks[i] = T[i];
    }
    tasks[0].wait = 0;

    for (int i = 1; i < n; i++)
    {
        tasks[i].wait = (tasks[i - 1].burst + tasks[i - 1].arrival + tasks[i - 1].wait) - tasks[i].arrival;
        waitTot += tasks[i].wait;
    }
    waitAvg = (float)waitTot / n;

    fprintf(fPtr, "FCFS: ");
    for (int i = 0; i < n; i++)
    {
        fprintf(fPtr, "\n%s\t%d\t%d", tasks[i].name, tasks[i].arrival, tasks[i].burst);
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(fPtr, "\nWaiting time %s: %d", tasks[i].name, tasks[i].wait);
    }

    fprintf(fPtr, "\nAverage waiting time: %0.2f\n", waitAvg);
}

//Round Robin Scheduling
void RR(task T[], int n, FILE *fPtr)
{
    int counter = 0;
    int curTime = 0;
    int quantum = 4;
    int waitTot = 0;
    float waitAvg = 0.0;
    int y;
    task final[10];
    task temp[10];

    fprintf(fPtr, "\nRR: \n");

    for (int i = 0; i < n; i++)
    {
        final[i] = T[i];
        temp[i] = final[i];
    }

    for (y = 0;; y++)
    {
        if (y > n - 1)
        {
            y = 0;
        }

        if (final[y].burst >= 1)
        {
            fprintf(fPtr, "%s\t%d\t%d\n", final[y].name, curTime, curTime + quantum);
        }

        int k = 0;
        while (k < quantum && final[y].burst >= 1)
        {
            k++;
            final[y].burst--;
            curTime++;
        }
        if (final[y].burst <= 0 && final[y].flag != 1)
        {
            counter++;
            final[y].wait = curTime - temp[y].burst - final[y].arrival;
            final[y].flag = 1;
            waitTot += final[y].wait;
        }

        if (counter == n)
        {
            break;
        }
    }

    waitAvg = (float)waitTot / n;
    fprintf(fPtr, "%s\t%d\t%d\n", final[y].name, curTime, curTime + quantum);

    for (int i = 0; i < n; i++)
    {
        fprintf(fPtr, "Waiting time %s: %d\n", final[i].name, final[i].wait);
    }

    fprintf(fPtr, "Average waiting time: %0.2f\n ", waitAvg);
}

//Non-preemptive Shortest-Job-First algorithm
void NSJF(task T[], int n, FILE *fPtr)
{
    task tasks[10];
    task t;
    int waitTot = 0;
    float waitAvg = 0.0;
    int i, j;

    for (i = 0; i < n; i++){
        tasks[i] = T[i];
        }


    for (i = 2; i < n; i++){
        for (j = 1; j < n - i + 1; j++)
        {
            if (tasks[j].burst > tasks[j + 1].burst)
            {
                t = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = t;
            }
        }
    }

    waitTot = 0; 
    tasks[0].wait = 0;

    for (i = 1; i < n; i++)
    {
        tasks[i].wait = (tasks[i - 1].burst + tasks[i - 1].wait + tasks[i - 1].arrival) - tasks[i].arrival;
        waitTot = waitTot+tasks[i].wait;
    }

    waitAvg = (float)waitTot / n;
    fprintf(fPtr, "\nNSJF: ");
    for (i = 0; i < n; i++)
    {
        fprintf(fPtr, "\n%s\t%d\t%d", tasks[i].name, tasks[i].arrival, tasks[i].burst);
    }
    for (i = 0; i < n; i++)
    {
        fprintf(fPtr, "\nWaiting time %s: %d", tasks[i].name, tasks[i].wait);
    }

    fprintf(fPtr, "\nAverage waiting time: %0.2f\n", waitAvg);
}

//Preemptive Shortest-Job-First algorithm
void PSJF(task T[], int n, FILE *fPtr)
{
    int j = 0, k = 0;
    int t_total = 0;
    int curTime;
    int burst[10];
    int waitTot = 0;
    float waitAvg = 0.0;
    task tasks[10];

    for (int i = 0; i < n; i++)
    {
        tasks[i] = T[i];
        t_total += T[i].burst;
        burst[i] = tasks[i].burst;
    }

    int i =  0;
    fprintf(fPtr, "\nPSJF: \n");
    fprintf(fPtr, "%s\t%d", tasks[i].name, i);

    //loop for each seconds, printing only when i!=j
    for (curTime = 0; curTime < t_total; curTime++)
    {
        if (i != j){
            fprintf(fPtr, "\t%d\n%s\t%d", curTime, tasks[i].name, curTime);
        }

        if (burst[i] > 0 && tasks[i].arrival <= curTime){
            burst[i]--;
        }
        
        if (burst[i] <= 0 && tasks[i].flag != 1)
        {
            tasks[i].flag = 1;
            tasks[i].wait = (curTime + 1) - tasks[i].burst - tasks[i].arrival;
            waitTot += tasks[i].wait;
        }

        j = i;
        int burstMin = 1000;
        //find minimum burst
        for (k = 0; k < n; k++)
        {
            if (tasks[k].arrival <= (curTime + 1) && tasks[k].flag != 1)
            {
                if (burstMin != burst[k] && burstMin >= burst[k])
                {
                    burstMin = burst[k];
                    i = k;
                }
            }
        }
    }
    
    //print results

    fprintf(fPtr, "\t%d", curTime);
    waitAvg = (float)waitTot / n;
    for (i = 0; i < n; i++)
    {
        fprintf(fPtr, "\nWaiting time %s: %d", tasks[i].name, tasks[i].wait);
    }
    fprintf(fPtr, "\nAverage waiting time = %0.2f\n ", waitAvg);
}

int main(int argc, const char *argv[])
{

    char *fname = "TaskSpec.txt";

    char line[100];
    task tasks[10];
    int index = 0;

    file = fopen(fname, "r"); // open file
    char *pt;

    while (fgets(line, sizeof(line), file))
    {
        pt = strtok(line, ",");
        if (pt != NULL)
        {
            strcpy(tasks[index].name, pt);
        }
        pt = strtok(NULL, ",");
        if (pt != NULL)
        {
            tasks[index].arrival = atoi(pt);
        }
        pt = strtok(NULL, ",");
        if (pt != NULL)
        {
            tasks[index].burst = atoi(pt);
        }
        index++;
    }
    fclose(file);
    FILE *fPtr;
    fPtr = fopen("Output.txt", "w");

    FCFS(tasks, index, fPtr);
    RR(tasks, index, fPtr);
    NSJF(tasks, index, fPtr);
    PSJF(tasks, index, fPtr);

    return 0;
}