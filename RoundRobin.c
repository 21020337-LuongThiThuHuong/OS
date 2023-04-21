#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct Process{
	int pid;
	int burst_time;
	int arrival_time;
} process;

void findWaitingTime(process pro[], int n, int wt[]){
	int q;
	printf("Enter quantumns: ");
	scanf("%d", &q);
	
	int remain = n, temp_burst_time[n];
	for(int i = 0; i < n; i++){
		temp_burst_time[i] =  pro[i].burst_time;
	}
	int flag = 0, time, i;
	for(time = 0, i = 0; remain != 0;){
		if(temp_burst_time[i] <= q && temp_burst_time[i] > 0){
			time += temp_burst_time[i];
			temp_burst_time[i] = 0;
			flag = 1; // đánh dấu là đã process đã kết thúc
		}else if(temp_burst_time[i] > 0){
			// nếu burst time hiện tại > quantumns thì trừ đi và đẩy procmdcess hiệ tại về cuối
			temp_burst_time[i] -= q;	
			time += q;
		}
		if(temp_burst_time[i] == 0 && flag == 1){
			// 1 tiến trình đã hoàn thành
			remain--;
			// giảm remain, tính wt và đánh dấu = 0
			wt[i] = time - pro[i].burst_time - pro[i].arrival_time;
			flag = 0;
		}
		if(i == n - 1){
			i = 0;
		}else if(pro[i + 1].arrival_time <= time){
			i++;
		}else i = 0;
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
      printf(" P\t|Arrival time\t|Burst time\t|Wait time\t|Total time\n");
      for(int i = 0; i < n; i++){
            total_wt += wt[i];
            total_tat += tat[i];
            printf(" P[%d]\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t\n", pro[i].pid, pro[i].arrival_time,pro[i].burst_time, wt[i], tat[i]);
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