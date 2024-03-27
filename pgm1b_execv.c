// execv()

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
  char *temp[3];
  temp[0] = "ls";
  temp[1] = "-l";
  temp[2] = (char *)0;
  execv("/bin/ls",temp);
  printf("This will print\n");
  return 0;
}



/*
OUTPUT

total 24
-rwxr-xr-x 1 root root 16792 Mar 27 10:47 Main
-rw-r--r-- 1 root root   229 Mar 27 10:47 Main.c

*/
