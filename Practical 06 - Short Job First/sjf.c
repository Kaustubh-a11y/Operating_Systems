#include <stdio.h>

#define MAX_PROCESSES 10

// Function to find waiting time (Preemptive SJF / SRTF)
void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    int remaining_bt[MAX_PROCESSES];
    
    for (int i = 0; i < n; i++)
        remaining_bt[i] = bt[i];

    int complete = 0, current_time = 0;
    int shortest = 0, finish_time;
    int done;

    while (complete != n) {
        int min_bt = 9999;
        done = 0;

        for (int i = 0; i < n; i++) {
            if (remaining_bt[i] > 0 && remaining_bt[i] < min_bt) {
                min_bt = remaining_bt[i];
                shortest = i;
                done = 1;
            }
        }

        if (done == 0) {
            current_time++;
            continue;
        }

        remaining_bt[shortest]--;

        if (remaining_bt[shortest] == 0) {
            complete++;
            finish_time = current_time + 1;

            wt[shortest] = finish_time - bt[shortest];

            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }

        current_time++;
    }
}

// Function to find turnaround time
void findTurnaroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

// Function to find average time
void findAverageTime(int processes[], int n, int bt[]) {
    int wt[MAX_PROCESSES], tat[MAX_PROCESSES];
    int total_wt = 0, total_tat = 0;

    findWaitingTime(processes, n, bt, wt);
    findTurnaroundTime(processes, n, bt, wt, tat);

    printf("Processes   Burst Time   Waiting Time   Turnaround Time\n");

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];

        printf("   %d\t\t%d\t\t%d\t\t%d\n",
               processes[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f",
           (float)total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n",
           (float)total_tat / n);
}

// Main function
int main() {
    int processes[] = {1, 2, 3, 4};
    int n = 4;
    int burst_time[] = {6, 8, 7, 3};

    findAverageTime(processes, n, burst_time);

    return 0;
}
