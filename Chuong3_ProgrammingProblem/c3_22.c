#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


const char* NAME = "Collatz";
const int SIZE = 4096 * 30;

int main(){
  pid_t pid;
  int n;
  int shm_fd;
  void *ptr;
  printf("Enter positive integer number: ");
  scanf("%d", &n);
  pid = fork();
  shm_fd = shm_open(NAME, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
  ftruncate(shm_fd, SIZE);
  int count = 0;
  ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);

  if(pid == 0){
    // child process
    // cấp phát cho shared memory file direction
    shm_fd = shm_open(NAME,O_CREAT | O_RDWR,S_IRUSR | S_IWUSR);
    ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
    while(n != 1){
      sprintf(ptr, "%d", n);
      puts(ptr);
      ptr++;
      if(n % 2 == 0) n /= 2;
      else n = n * 3 + 1;
    }
    sprintf(ptr, "%d", n);
    ptr++;
  }else if(pid > 0){
    wait(NULL);
    printf("%s\n",(char*)ptr);
    shm_unlink(NAME);
  }
  return 0;
}
