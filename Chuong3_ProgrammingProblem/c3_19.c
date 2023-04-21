// Một tiến trình được gọi là zombie khi nó đã thực thi thành công nhưng một hoặc một số mục vẫn còn
// ở trong bảng tiến trình
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
int main(){
	pid_t pid;
	pid = fork(); // tạo tiến trình con
	if(pid > 0){
		printf("Parent process\n");
		sleep(10);
	}else if(pid == 0){
		exit(0);
	}
	return 0;
}
// trong tiến trình cha, cha sẽ ngủ trong vòng 10s trong khi đó tiến trình con đã chạy xong và exit, parent thì k gọi wait()
// nên tiến trình trở thành zombie process
// cách xóa là kill -9 4884