#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int allocation[n], max[n], need[n];
    int available;

    printf("\nEnter Allocation for each process:\n");
    for(i = 0; i < n; i++) {
        printf("P%d: ", i);
        scanf("%d", &allocation[i]);
    }

    printf("\nEnter Max for each process:\n");
    for(i = 0; i < n; i++) {
        printf("P%d: ", i);
        scanf("%d", &max[i]);
    }


    printf("\nEnter Available resources: ");
    scanf("%d", &available);


    for(i = 0; i < n; i++) {
        need[i] = max[i] - allocation[i];
    }

    int finished[n];
    for(i = 0; i < n; i++) {
        finished[i] = 0;
    }

    int safeSequence[n];
    int count = 0;

    while(count < n) {
        int found = 0;

        for(i = 0; i < n; i++) {
            if(finished[i] == 0 && need[i] <= available) {


                available += allocation[i];
                safeSequence[count++] = i;
                finished[i] = 1;
                found = 1;
            }
        }

        if(found == 0) {
            printf("\nSystem is NOT in safe state!\n");
            return 0;
        }
    }


    printf("\nSystem is in SAFE state.\nSafe sequence: ");
    for(i = 0; i < n; i++) {
        printf("P%d ", safeSequence[i]);
    }

    printf("\n");
    return 0;
}
