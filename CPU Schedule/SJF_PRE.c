#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
struct Process{
      int pid;
      int arrival_time;
      int burst_time;
};
typedef struct Process process;
void findWaitingTime(process pro[], int n, int wt[]){
    int tmp[n];
  
    // copy burst time
    for (int i = 0; i < n; i++)
        tmp[i] = pro[i].burst_time;
  
    int count = 0, t = 0, minm = INT_MAX;
    int shortest = 0, finish_time;
    int check = 0;
  
    while (count != n) {
  
        // tìm tiến trình có burst time nhỏ nhất hiện đang có trong queue và cpu
        for (int j = 0; j < n; j++) {
            if ((pro[j].arrival_time <= t) &&
            (tmp[j] < minm) && tmp[j] > 0) {
                minm = tmp[j];
                shortest = j;
                check = 1;
            }
        }
        // nếu hiện tại đang k có tiến trình nào trong queue thì sẽ tăng thời gian và continue
        if (check == 0) {
            t++;
            continue;
        }
  
        // giảm burst time xuống
        tmp[shortest]--;
  
        // Update minimum
        minm = tmp[shortest];
        if (minm == 0)
            minm = INT_MAX;
  
       // nếu một tiến trình đã chạy xong
        if (tmp[shortest] == 0) {
  
           // tăng count
            count++;
            check = 0;
  
            // thời gian kết thúc
            finish_time = t + 1;
  
            // tính wait time
            wt[shortest] = finish_time -
                        pro[shortest].burst_time -
                        pro[shortest].arrival_time;
  
        }
       // tăng t
        t++;
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
      printf(" P\t\t|\tBurst time\t|\tWait time\t|\tTotal time\n");
      for(int i = 0; i < n; i++){
            total_wt += wt[i];
            total_tat += tat[i];
            printf(" P[%d]\t\t|\t%d\t\t|\t%d\t\t|\t%d\t\n", pro[i].pid, pro[i].burst_time, wt[i], tat[i]);
      }
      printf("\nAverage watting time %lf\n", (float)total_wt/n);
      printf("\nAverage turn around time %lf\n", (float)total_tat/n);
}
int main(){
      int n;
      printf("Enter number of Processes: ");
      scanf("%d", &n);
      process pro[n];
      printf("Enter Details of %d Process\n", n);
      for(int i = 0; i < n; i++){
            pro[i].pid = i + 1;
            printf("Enter arrival time: ");
            scanf("%d", &pro[i].arrival_time);
            printf("Enter burst time: ");
            scanf("%d", &pro[i].burst_time);
      }
      findavgTime(pro, n);
}
