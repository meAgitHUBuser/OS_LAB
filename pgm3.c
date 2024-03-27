// Producer consumer

#include<stdio.h>
int main(){
  int buffer[10], buff_size=10, in=0, out=0, produce, consume, choice =0;
  while(choice!=3){
  printf("\nEnter your choice:\n\t1. Produce\n\t2. Consume\n\t3. Exit\n");
  scanf("%d",&choice);
    switch(choice){
      case 1: 
        if((in+1)%buff_size == out){
          printf("Buffer is full");
        }
        else{
          printf("\nEnter value to produce: ");
          scanf("%d",&produce);
          buffer[in]=produce;
          in=(in+1)%buff_size;
        }
        break;
      case 2:
        if(in==out){
          printf("Buffer is empty");
        }
        else{
          consume=buffer[out];
          printf("\nConsumed: %d",consume);
          out=(out+1)%buff_size;
        }
        break;
    }
  }
  return 0;
}
