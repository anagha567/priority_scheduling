#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    int n;

    printf("Enter number of processes:\n");
    scanf("%d", &n);

    char pid[MAX][10];
    int at[MAX], bt[MAX], pr[MAX];
    int rt[MAX];   
    int ct[MAX];   
    int wt[MAX];   
    int tat[MAX];  

    
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d %d", pid[i], &at[i], &bt[i], &pr[i]);
        rt[i] = bt[i];  
    }

    int completed = 0, time = 0;
    float total_wt = 0, total_tat = 0;

    while (completed < n) {
        int highest = -1;
        int highest_priority = -1;

        
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0) {
                if (pr[i] > highest_priority) {
                    highest_priority = pr[i];
                    highest = i;
                }
            }
        }

        if (highest == -1) {
            time++;  
        } else {
            rt[highest]--;  
            time++;

            if (rt[highest] == 0) {
                completed++;
                ct[highest] = time;
                tat[highest] = ct[highest] - at[highest];
                wt[highest] = tat[highest] - bt[highest];

                total_wt += wt[highest];
                total_tat += tat[highest];
            }
        }
    }

    printf("\nWaiting Time:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", pid[i], wt[i]);
    }

    printf("Turnaround Time:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", pid[i], tat[i]);
    }

    printf("Average Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);

    return 0;
}
