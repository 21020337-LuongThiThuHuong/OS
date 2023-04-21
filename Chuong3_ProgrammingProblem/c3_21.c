#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
	int n;
	pid_t pid;
	printf("Enter integer number: ");
	scanf("%d", &n);
	pid = fork();
		if(pid > 0 ){
			wait(NULL);
		}else if(pid == 0){
			while(n != 1){
				if(n % 2 == 0) n /=2;
				else n = n * 3 + 1;
				printf("%d\n", n);
		}
	}
}


// psuedo code
// nhập n và create pid
// fork parent process
// if fork == 0 -> child process
// child process:
//		if n even n : n/2
//		if n odd n : n * 3 + 1
// 		in ra


// sau khi tiến trình thực thi xong thì kết quả nhận lại luôn là 1