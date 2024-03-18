// FIFO page replacement algorithm

#include <stdio.h>
#define FRAMESIZE 3
void display(int frame[])
{
    for (int i = 0; i < FRAMESIZE; i++)
    {
        printf("%d\t", frame[i]);
    }
    printf("\n");
}
int main()
{
    int pageReferences[] = {2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2};
    int frame[FRAMESIZE];
    int pageFaults = 0; 
    int top = 0;
    for (int i = 0; i < FRAMESIZE; i++)
    {
        frame[i] = -1;
    }
    for (int j = 0; j < 12; j++)
    {
        int currentPage = pageReferences[j];
        int found = 0;
        for (int i = 0; i < FRAMESIZE; i++)
        {
            if (frame[i] == currentPage)
            {
                found = 1;
                break;
            }
        }
        if (!found)
        {
            frame[top] = currentPage;
            top = (top + 1) % FRAMESIZE;
            pageFaults++;
        }
        display(frame);
    }
    printf("\nNumber of page faults: %d\n", pageFaults);
    return 0;
}
