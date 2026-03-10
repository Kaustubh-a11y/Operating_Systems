#include <stdio.h>
#include <limits.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int priority;
    int completion_time;
    int waiting_time;
    int turnaround_time;
};

int main() {
    int n, i, time = 0, completed = 0;
    struct Process p[20];
    float total_waiting = 0, total_turnaround = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input
    for(i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);
        p[i].pid = i + 1;

        printf("Arrival Time: ");
        scanf("%d", &p[i].arrival_time);

        printf("Burst Time: ");
        scanf("%d", &p[i].burst_time);
        p[i].remaining_time = p[i].burst_time;

        printf("Priority (lower number = higher priority): ");
        scanf("%d", &p[i].priority);
    }

    while(completed != n) {
        int highest_priority = INT_MAX;
        int index = -1;

        // Find highest priority process at current time
        for(i = 0; i < n; i++) {
            if(p[i].arrival_time <= time &&
               p[i].remaining_time > 0 &&
               p[i].priority < highest_priority) {

                highest_priority = p[i].priority;
                index = i;
            }
        }

        // If no process is ready
        if(index == -1) {
            time++;
        } else {
            // Execute process for 1 time unit
            p[index].remaining_time--;
            time++;

            // If process completed
            if(p[index].remaining_time == 0) {
                completed++;
                p[index].completion_time = time;

                p[index].turnaround_time =
                    p[index].completion_time - p[index].arrival_time;

                p[index].waiting_time =
                    p[index].turnaround_time - p[index].burst_time;

                total_waiting += p[index].waiting_time;
                total_turnaround += p[index].turnaround_time;
            }
        }
    }

    // Output
    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].arrival_time,
               p[i].burst_time,
               p[i].priority,
               p[i].completion_time,
               p[i].turnaround_time,
               p[i].waiting_time);
    }

    printf("\nAverage Waiting Time: %.2f", total_waiting / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_turnaround / n);

    return 0;
}
