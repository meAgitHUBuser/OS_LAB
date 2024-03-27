// SJF CPU Scheduling

#include<stdio.h>

void findWT(int bt[], int wt[], int n) {   
  wt[0] = 0;
    for (int i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
    }
}

void findTAT(int bt[], int wt[], int tat[], int n) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void findAvgTime(int bt[], int n) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(bt[i]>bt[j]){
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }
    findWT(bt, wt, n);
    findTAT(bt, wt, tat, n);
    printf("Processes\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }
    printf("Average waiting time: %.2f\n", (float)total_wt / n);
    printf("Average turnaround time: %.2f\n", (float)total_tat / n);
}

int main() {
  int n;
  printf("Enter the number of processes: ");
  scanf("%d",&n);
  int bt[n];
  printf("Enter the burst time of the processes: \n");
  for(int i=0;i<n;i++){
    scanf("%d",&bt[i]);
  }
    findAvgTime(bt, n);
    return 0;
}


/*
OUTPUT

Enter the number of processes: 3
Enter the burst time of the processes: 
14
58
12
Processes	Burst Time	Waiting Time	Turnaround Time
1		12		0		12
2		14		12		26
3		58		26		84
Average waiting time: 12.67
Average turnaround time: 40.67

*/
