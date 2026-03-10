#include <stdio.h>

int main() {
    int n, i;
    int bt[10], wt[10], tat[10], ct[10], rt[10];
    float avg_wt = 0, avg_tat = 0, avg_rt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time of each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Waiting time for first process is 0
    wt[0] = 0;

    // Calculate waiting time
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    // Calculate completion time, turnaround time, response time
    for (i = 0; i < n; i++) {
        ct[i] = wt[i] + bt[i];   // Completion Time
        tat[i] = ct[i];          // Turnaround Time
        rt[i] = wt[i];           // Response Time (FCFS)

        avg_wt += wt[i];
        avg_tat += tat[i];
        avg_rt += rt[i];
    }

    avg_wt /= n;
    avg_tat /= n;
    avg_rt /= n;

    printf("\nProcess\tBT\tWT\tRT\tCT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, bt[i], wt[i], rt[i], ct[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f", avg_tat);
    printf("\nAverage Response Time = %.2f\n", avg_rt);

    return 0;
}
s
