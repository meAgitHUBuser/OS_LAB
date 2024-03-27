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


/*
OUTPUT

Child process started
0	1	2	3	4	5	6	7	8	9	
Child process ends
Parent process started
Parent process ends

*/
