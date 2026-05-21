#include <stdio.h>

int main() {
    int pages[] = {1,2,3,4,1,2,5,1,2,3,4,5};
    int n=12, frames[3], last[3], faults=0;

    for(int i=0;i<3;i++) frames[i]=-1, last[i]=0;

    for(int i=0;i<n;i++) {
        int found=0, empty=-1;

        for(int j=0;j<3;j++) {
            if(frames[j]==pages[i]) { found=1; last[j]=i; break; }
            if(frames[j]==-1) empty=j;
        }

        if(!found) {
            faults++;
            int pos = (empty!=-1) ? empty : 0;
            if(empty==-1)
                for(int j=1;j<3;j++)
                    if(last[j] < last[pos]) pos=j;
            frames[pos]=pages[i];
            last[pos]=i;
        }

        printf("Frames: %d %d %d\n", frames[0], frames[1], frames[2]);
    }

    printf("Page Faults: %d\n", faults);
    return 0;
}
