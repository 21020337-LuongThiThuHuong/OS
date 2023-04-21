#include<stdio.h>
#include<limits.h>
int a_time[1000]; // arrival time
int b_time[1000]; // burst time
int wait_Time_Sum = 0 ;
int turn_Time_Sum = 0;
int main(){
	int time = 0, n, smallest, count = 0;
	printf("Enter number of processes: ");
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		printf("Enter arrival time for process P%d : ", i + 1);
		scanf("%d", &a_time[i]);
		printf("Enter burst time for process P%d : ", i + 1);
		scanf("%d", &b_time[i]);
	}
	a_time[999] = INT_MAX;
	printf("\n\nProcess\t|Turnaround Time| Waiting Time\n\n");
	while(count != n){
		smallest = 999;
		for(int i = 0; i < n; i++){
			if(a_time[i] < a_time[smallest] && b_time[i] > 0){
				smallest = i; 
			}
		}
		// lấy được tiến trình có thời gian đến nhỏ nhất
		time += b_time[smallest];
		wait_Time_Sum += time - a_time[smallest] - b_time[smallest];
		turn_Time_Sum += time - a_time[smallest];
		printf("P[%d]\t|\t%d\t|\t%d\n", smallest + 1, time - a_time[smallest], time - a_time[smallest]
			- b_time[smallest]);
		b_time[smallest] = 0;
		count++;
	}
	printf("\n average waiting time = %f",wait_Time_Sum*1.0/n);
	printf("\n average turnaround time = %f\n",turn_Time_Sum*1.0/n);
	return 0;
}