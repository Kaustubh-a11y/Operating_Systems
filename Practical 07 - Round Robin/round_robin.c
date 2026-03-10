#include <stdio.h>

int main() {
    int n, i;

    printf("Enter number of processes:\n");
    scanf("%d", &n);

    int at[n], bt[n], rem_bt[n];
    int ct[n], tat[n], wt[n], rt[n];
    int first_exec[n];   // To track first execution time

    for(i = 0; i < n; i++) {
        printf("Enter arrival time of process %d:\n", i+1);
        scanf("%d", &at[i]);

        printf("Enter burst time of process %d:\n", i+1);
        scanf("%d", &bt[i]);

        rem_bt[i] = bt[i];
        ct[i] = tat[i] = wt[i] = rt[i] = 0;
        first_exec[i] = -1;  // Not executed yet
    }

    int tq;
    printf("Enter time quantum:\n");
    scanf("%d", &tq);

    int time = 0;
    int completed = 0;
    int done;

    while(completed < n) {
        done = 1;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && rem_bt[i] > 0) {
                done = 0;

                // If first time executing, record response time
                if(first_exec[i] == -1) {
                    first_exec[i] = time;
                    rt[i] = first_exec[i] - at[i];
                }

                if(rem_bt[i] <= tq) {
                    time += rem_bt[i];
                    rem_bt[i] = 0;
                    ct[i] = time;
                    completed++;
                }
                else {
                    time += tq;
                    rem_bt[i] -= tq;
                }
            }
        }

        if(done == 1) {
            time++;
        }
    }

    float total_tat = 0, total_wt = 0, total_rt = 0;

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        total_tat += tat[i];
        total_wt += wt[i];
        total_rt += rt[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i], tat[i], wt[i], rt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", total_tat/n);
    printf("\nAverage Waiting Time = %.2f", total_wt/n);
    printf("\nAverage Response Time = %.2f\n", total_rt/n);

    return 0;
}
