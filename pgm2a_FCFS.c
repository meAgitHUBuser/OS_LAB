// FCFS CPU Scheduling

#include<stdio.h>

void findWT(int processes[], int n, int bt[], int wt[]){
  wt[0]=0;
  for(int i=1;i<n;i++){
    wt[i] = bt[i-1] + wt[i-1];
  }
}
void findTAT(int processes[], int n, int bt[], int wt[], int tat[]){
  for(int i=0;i<n;i++){
    tat[i] = bt[i] + wt[i];
  }
}
void findAvgTime(int processes[], int n, int bt[]){
  int wt[n], tat[n], total_wt = 0, total_tat = 0;
  findWT(processes, n, bt, wt);
  findTAT(processes, n, bt, wt, tat);
  printf("Processes Burst Time Waiting Time Turn Around Time");
  for(int i=0;i<n;i++){
    total_wt += wt[i];
    total_tat += tat[i];
    printf("\n%d\t%d\t%d\t%d",i+1,bt[i],wt[i],tat[i]);
  }
  printf("\nAverage waiting time: %.4f",(float)total_wt/(float)n);
  printf("\nAverage turn around time: %.4f",(float)total_tat/(float)n);
}
int main(){
  int processes[] = {1,2,3};
  int n = sizeof processes/sizeof processes[0];
  int bt[] = {10, 5, 8};
  findAvgTime(processes, n, bt);
  return 0;
}
