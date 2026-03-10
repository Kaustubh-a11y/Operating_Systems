#include <stdio.h>

#define MAX_PROCESSES 10

void findWaitingTime(int p[], int n, int bt[], int wt[], int ct[]) {
    int rem_bt[MAX_PROCESSES];
    for(int i=0;i<n;i++) rem_bt[i]=bt[i];

    int complete=0, time=0, shortest, done;
    while(complete!=n){
        int min=9999; done=0;
        for(int i=0;i<n;i++){
            if(rem_bt[i]>0 && rem_bt[i]<min){
                min=rem_bt[i];
                shortest=i;
                done=1;
            }
        }
        if(!done){ time++; continue; }

        rem_bt[shortest]--;
        if(rem_bt[shortest]==0){
            complete++;
            ct[shortest]=time+1;
            wt[shortest]=ct[shortest]-bt[shortest];
            if(wt[shortest]<0) wt[shortest]=0;
        }
        time++;
    }
}

void findTurnaroundTime(int n, int bt[], int wt[], int tat[]){
    for(int i=0;i<n;i++) tat[i]=bt[i]+wt[i];
}

void findAverageTime(int p[], int n, int bt[]){
    int wt[MAX_PROCESSES], tat[MAX_PROCESSES], ct[MAX_PROCESSES];
    float total_wt=0, total_tat=0, total_ct=0;

    findWaitingTime(p,n,bt,wt,ct);
    findTurnaroundTime(n,bt,wt,tat);

    printf("\n%-8s %-6s %-10s %-7s %-10s\n",
           "Process", "Burst", "Completion", "Waiting", "Turnaround");

    for(int i=0;i<n;i++){
        printf("%-8s %-6d %-10d %-7d %-10d\n",
               (char[3]){ 'P', '0'+p[i], '\0' },
               bt[i], ct[i], wt[i], tat[i]);
        total_wt+=wt[i];
        total_tat+=tat[i];
        total_ct+=ct[i];
    }

    printf("\nAverage Waiting Time = %.2f\n", total_wt/n);
    printf("Average Turnaround Time = %.2f\n", total_tat/n);
    printf("Average Completion Time = %.2f\n", total_ct/n);
}

int main(){
    int p[]={1,2,3,4};
    int bt[]={6,8,7,3};
    int n=4;

    findAverageTime(p,n,bt);
    return 0;
}
