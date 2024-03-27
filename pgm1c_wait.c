// wait()

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
  int pid = fork();
  if(pid==0){
    printf("Child process started\n");
      for(int i=0;i<10;i++)
        printf("%d\t",i);
      printf("\nChild process ends\n");
  }
  else{
    printf("Parent process started\n");
      wait(0);
      printf("\Parent process ends\n");
  }
  return 0;
}
