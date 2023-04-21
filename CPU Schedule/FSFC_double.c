#include<stdio.h>
#include<limits.h>
double a_time[1000]; // arrival time
double b_time[1000]; // burst time
double wait_Time_Sum = 0 ;
double turn_Time_Sum = 0;
int main(){
	double time = 0;
	int smallest, n, count = 0;
	printf("Enter number of processes: ");
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		printf("Enter arrival time for process P%d : ", i + 1);
		scanf("%lf", &a_time[i]);
		printf("Enter burst time for process P%d : ", i + 1);
		scanf("%lf", &b_time[i]);
	}
	a_time[999] = 100000000;
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
		printf("P[%d]\t|\t%lf\t|\t%lf\n", smallest + 1, time - a_time[smallest], time - a_time[smallest]
			- b_time[smallest]);
		b_time[smallest] = 0;
		count++;
	}
	printf("\n average waiting time = %lf",wait_Time_Sum/n);
	printf("\n average turnaround time = %lf\n",turn_Time_Sum*1.0/n);
	return 0;
}