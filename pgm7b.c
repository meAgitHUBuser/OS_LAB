// LRU page replacement algorithm

#include <stdio.h>
#define FRAMES 3
#define PAGES 12
int main() {
    int pages[] = {2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2};
    int frames[FRAMES] = {-1, -1, -1}; // -1 indicates an empty frame
    int pageFaults = 0;
    int time = 1; // Start time from 1
    int lastUsed[FRAMES] = {0, 0, 0}; // Initialize lastUsed with 0
    for (int i = 0; i < PAGES; i++) {
        int page = pages[i];
        int found = 0;
        // Check if the page is already in a frame
        for (int j = 0; j < FRAMES; j++) {
            if (frames[j] == page) {
                found = 1;
                lastUsed[j] = time++;
                break;
            }
        }
        // If not found in frames, find the least recently used frame
        if (!found) {
            int lruIndex = 0;
            int minLastUsed = lastUsed[0];
            for (int j = 1; j < FRAMES; j++) {
                if (lastUsed[j] < minLastUsed) {
                    lruIndex = j;
                    minLastUsed = lastUsed[j];
                }
            }
            frames[lruIndex] = page;
            lastUsed[lruIndex] = time++;
            pageFaults++;
        }
        printf("\n");
        for (int j = 0; j < FRAMES; j++) {
            printf("\t%d", frames[j]);
        }
    }
    printf("\nNumber of page faults: %d\n", pageFaults);
    return 0;
}
