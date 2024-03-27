// Bankers 

#include<stdio.h>
#define max 10
int main(){
    int n, avail, temp[max], time[max];
    char job[max][10];
    printf("Enter the number of jobs: ");
    scanf("%d",&n);
    printf("Enter the job name and processing time: \n");
    for(int i=0;i<n;i++){
        scanf("%s%d",job[i],&time[i]);
        temp[i]=i;
    }
    printf("Enter the available resources: ");
    scanf("%d",&avail);
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(time[j]>time[j+1]){
                int tem = time[j];
                time[j] = time[j+1];
                time[j+1] = tem;
                
                tem = temp[j];
                temp[j] = temp[j+1];
                temp[j+1] = tem;
            }
        }
    }
    
    printf("Safe sequence is: ");
    int total_time=0;
    for(int i=0;i<n;i++){
        int q = temp[i];
        if(time[q]<=avail){
            printf("%s ",job[q]);
            avail -= time[q];
            total_time += time[q];
        }
        else{
            printf("\nNot enough resources for further jobs");
            return 0;
        }
    }
    return 0;
}


/*
OUTPUT

Enter the number of jobs: 3
Enter the job name and processing time: 
A 1
B 2
C 3
Enter the available resources: 3
Safe sequence is: A B 
Not enough resources for further jobs


*/
