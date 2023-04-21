#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MIN_PID 300
#define MAX_PID 5000	
struct PID{
	int PID;
	int check;
};
typedef struct PID pid;
int size = MAX_PID - MIN_PID + 1;
pid* pId;
int allocate_map(){
	pId = (pid*)calloc(size, sizeof(pid));
	if(pId == NULL) return -1;
	pId[0].PID = MIN_PID;
	pId[0].check = 1;
	for(int i = 1; i < size; i++){
		pId[i].PID = pId[i - 1].PID + 1;
		pId[i].check = 1;
	}
	return 1;
}

int allocate_pid(){
	int i = 0;
	for(i ; i < size; i++){
		if(pId[i].check == 1){
			pId[i].check = 0;
			return pId[i].PID;
		}
	}
	if(i == size){
		return -1;// đánh dấu đã hết
	}
}
void release_pid(int pid){
	pId[pid - MIN_PID].check = 1;
}
int main(){
	int map = allocate_map();
	if(map == 1){
		printf("init successfully\n");
		int id = 0, i = 0;
		while(i < 15){
			int val = allocate_pid();
			printf("\nProcess %d: pid = %d", i + 1, val);
			i++;		
		}
		release_pid(503); printf("\nProcess 503 released.");
        release_pid(505); printf("\nProcess 505 released.");
        int val = allocate_pid(); printf("\nProcess %d : pid = %d\n", i+1, val);

	}
}