// FCFS CPU Scheduling

#include<stdio.h>

void findWT(int n, int bt[], int wt[]){
  wt[0]=0;
  for(int i=1;i<n;i++){
    wt[i] = bt[i-1] + wt[i-1];
  }
}
void findTAT(int n, int bt[], int wt[], int tat[]){
  for(int i=0;i<n;i++){
    tat[i] = bt[i] + wt[i];
  }
}
void findAvgTime(int n, int bt[]){
  int wt[n], tat[n], total_wt = 0, total_tat = 0;
  findWT(n, bt, wt);
  findTAT(n, bt, wt, tat);
  printf("Processes Burst Time Waiting Time Turn Around Time");
  for(int i=0;i<n;i++){
    total_wt += wt[i];
    total_tat += tat[i];
    printf("\n%d\t%d\t%d\t%d",i+1,bt[i],wt[i],tat[i]);
  }
  printf("\nAverage waiting time: %.4f",(float)total_wt/n);
  printf("\nAverage turn around time: %.4f",(float)total_tat/n);
}
int main(){
  int n=3;
  int bt[] = {10, 5, 8};
  findAvgTime(n, bt);
  return 0;
}


/*
OUTPUT

Processes BurstTime WaitingTime TurnAroundTime
1	          10	          0	          10
2	          5	            10	        15
3	           8	          15	        23      
Average waiting time: 8.3333
Average turn around time: 16.0000

*/
