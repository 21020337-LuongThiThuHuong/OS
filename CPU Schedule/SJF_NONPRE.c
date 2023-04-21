#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct Process{
    int pid;
    int burst_time;
    int arrival_time;
} process;
void findWaitingTime(process pro[], int n, int wt[]){
    int count = 0, time = 0, finish_time = 0;
    int tmp[n];
    for(int i = 0; i < n; i++){
        tmp[i] = pro[i].burst_time;
    }
    int index = 0;
    int flag = 0;
    while(count != n){
        int time_burst_min = INT_MAX;
        for(int i = 0; i < n; i++){
            if(pro[i].arrival_time <= time && tmp[i] > 0 && tmp[i] < time_burst_min){
                time_burst_min = tmp[i];
                index = i;
                flag = 1;
            }
        }
        if(flag == 0){
            time++;
            continue;
        }
        time += pro[index].burst_time;
        printf("%d\n", time);
        tmp[index] = 0;
        flag = 0;
        count++;
        wt[index] = time - pro[index].arrival_time - pro[index].burst_time;
    }
}
void findTurnAroundTime(process pro[], int n, int wt[], int tat[]){
      for(int i = 0; i < n; i++){
            tat[i] = pro[i].burst_time + wt[i];
      }
}
void findavgTime(process pro[], int n){
      int wt[n], tat[n], total_wt = 0, total_tat = 0;
      findWaitingTime(pro, n, wt);
      findTurnAroundTime(pro, n, wt, tat);
      printf(" P\t\t|\tArrival time\t|\tBurst time\t|\tWait time\t|\tTotal time\n");
      for(int i = 0; i < n; i++){
            total_wt += wt[i];
            total_tat += tat[i];
            printf(" P[%d]\t\t|\t%d\t\t|\t%d\t\t|\t%d\t\t|\t%d\t\n", pro[i].pid, pro[i].arrival_time,pro[i].burst_time, wt[i], tat[i]);
      }
      printf("\nAverage watting time %lf\n", (float)total_wt/n);
      printf("\nAverage turn around time %lf\n", (float)total_tat/n);
}
int main(){
    int n;
    printf("Enter number of Processes: ");
    scanf("%d", &n);
    printf("Enter details for process\n");
    process pro[n];
    for(int i = 0; i < n; i++){
        pro[i].pid = i + 1;
        printf("Enter arrival time: ");
        scanf("%d", &pro[i].arrival_time);
        printf("Enter burst time: ");
        scanf("%d", &pro[i].burst_time);
    }   
    findavgTime(pro, n);
}