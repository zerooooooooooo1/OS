#include <stdio.h>

int main() {
    int n, bt[10], pr[10], wt[10], tat[10], p[10];
    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        p[i] = i+1;
        printf("Burst Time P%d: ", p[i]); scanf("%d", &bt[i]);
        printf("Priority P%d: ", p[i]);   scanf("%d", &pr[i]);
    }

    // sort by priority (bubble sort)
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++)
            if(pr[i] > pr[j]) {
                int t;
                t=pr[i]; pr[i]=pr[j]; pr[j]=t;
                t=bt[i]; bt[i]=bt[j]; bt[j]=t;
                t=p[i];  p[i]=p[j];  p[j]=t;
            }

    wt[0] = 0;
    for(int i = 1; i < n; i++)
        wt[i] = wt[i-1] + bt[i-1];
    for(int i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];

    printf("\nProcess\tBT\tPR\tWT\tTAT\n");
    for(int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\n", p[i], bt[i], pr[i], wt[i], tat[i]);

    return 0;
}
