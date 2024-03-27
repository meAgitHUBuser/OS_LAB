// fork()

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
  int pid = fork();
  if(pid==0){
    printf("I am a child\n");
    printf("I am parent of a child with pid: %d\n",getppid());
    printf("I am child \t pid: %d\n",getpid());
  }
  else{
    printf("I am a parent\n");
    printf("I am parent of a parent with pid: %d\n",getppid());
    printf("I am parent \t pid: %d\n",getpid());
  }
  return 0;
}
