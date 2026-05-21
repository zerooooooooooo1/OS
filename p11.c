#include <stdio.h>

int main() {
    int n=3, m=3;
    int alloc[3][3] = {{0,1,0},{2,0,0},{3,0,2}};
    int max[3][3]   = {{7,5,3},{3,2,2},{9,0,2}};
    int need[3][3];

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            need[i][j] = max[i][j] - alloc[i][j];

    printf("Need Matrix:\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++)
            printf("%d ", need[i][j]);
        printf("\n");
    }
    return 0;
}