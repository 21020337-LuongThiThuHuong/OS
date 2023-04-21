#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct Process{
	int pid;
	int burst_time;
	int arrival_time;
	int priority;
} process;

void findWaitingTime(process pro[], int n, int wt[]){
	int count = 0, time = 0, finish_time = 0;
	int index = 0;
	int flag = 0;
	int temp_priority[n];
	for(int i = 0; i < n; i++){
		temp_priority[i] = pro[i].priority;
	}
	while(count != n){
		int min_prio = INT_MAX;
		for(int i = 0; i < n; i++){
			if(pro[i].arrival_time <= time && pro[i].burst_time > 0 && temp_priority[i] < min_prio){
				min_prio = temp_priority[i];
				index = i;
				flag = 1;
			}
		}
		if(flag == 0){
			time++;
			continue;
		}
		time += pro[index].burst_time;
		temp_priority[index] = INT_MAX;
		flag = 0;
		count ++;
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
      printf(" P\t|Arrival time\t|Burst time\t|Priority\t|Wait time\t|Total time\n");
      for(int i = 0; i < n; i++){
            total_wt += wt[i];
            total_tat += tat[i];
            printf(" P[%d]\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t\n", pro[i].pid, pro[i].arrival_time,pro[i].burst_time, pro[i].priority, wt[i], tat[i]);
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
        printf("Enter priority: ");
        scanf("%d", &pro[i].priority);
    }   
    findavgTime(pro, n);
}