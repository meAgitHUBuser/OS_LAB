// SCAN Disk Scheduling Algorithm

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 20
int main() {
    int queue[MAX], head, num, max, queue1[MAX], queue2[MAX];
    int count1 = 0, count2 = 0, seek = 0;
    float avg;
    printf("Enter the max range of disk: ");
    scanf("%d", &max);
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    printf("Enter the size of queue request: ");
    scanf("%d", &num);
    printf("Enter the queue of disk positions to be read: \n");
    for(int i = 0; i < num; i++) {
        int temp;
        scanf("%d", &temp);
        if(temp >= head) {
            queue1[count1] = temp;
            count1++;
        } else {
            queue2[count2] = temp;
            count2++;
        }
    }
    for(int i = 0; i < count1-1; i++) {
        for(int j = i+1; j < count1; j++) {
            if(queue1[i] > queue1[j]) {
                int temp = queue1[i];
                queue1[i] = queue1[j];
                queue1[j] = temp;
            }
        }
    }
    for(int i = 0; i < count2-1; i++) {
        for(int j = i+1; j < count2; j++) {
            if(queue2[i] > queue2[j]) { 
                int temp = queue2[i];
                queue2[i] = queue2[j];
                queue2[j] = temp;
            }
        }
    }
    // Merge queue1 and queue2 into queue
    int i;
    for(i = 1; i <= count1; i++)
        queue[i] = queue1[i-1];
    queue[i] = max;
    for(int j = count1+2; j < num + count1 + 2; j++)
        queue[j] = queue2[j-count1-2];
    queue[0] = head;
    for(int j = 0; j <= num; j++) { 
        int diff = abs(queue[j+1] - queue[j]);
        seek += diff;
        printf("Disk head moves from %d to %d with seek %d\n", queue[j], queue[j+1], diff);
    }
    printf("Total seek time is %d\n", seek);
    avg = (float)seek / num; 
    printf("Average seek time is %f\n", avg);
    return 0;
}
