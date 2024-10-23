#include <stdio.h>

void print(int at[], int bt[], int ct[], int tat[], int wt[], float total_tat, float total_wt, int n)
{
    printf("\nPId\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("Average Turnaround Time: %.2f\n", total_tat / n);
    printf("Average Waiting Time: %.2f\n", total_wt / n);
}

int main()
{
    int n = 4, quantum = 2;
    int at[] = {0, 1, 2, 4};
    int bt[] = {5, 4, 2, 1};

    int remaining[n], ct[n], tat[n], wt[n];
    float total_tat = 0, total_wt = 0;

    for (int i = 0; i < n; i++)
    {
        remaining[i] = bt[i]; // Initialize remaining time
    }

    int completedProcesses = 0, currentTime = 0;

    while (completedProcesses < n)
    {
        for (int i = 0; i < n; i++)
        {
            if (at[i] <= currentTime && remaining[i] > 0)
            {
                if (remaining[i] > quantum)
                {
                    currentTime += quantum;
                    remaining[i] -= quantum;
                }
                else
                {
                    currentTime += remaining[i];
                    ct[i] = currentTime;    // Completion time
                    tat[i] = ct[i] - at[i]; // Turnaround time
                    wt[i] = tat[i] - bt[i]; // Waiting time
                    remaining[i] = 0;       // Mark as completed
                    completedProcesses++;
                }
            }
        }
        if (completedProcesses < n)
        {
            currentTime++; // Increment time if no process is ready
        }
    }

    // Calculate total TAT and WT
    for (int i = 0; i < n; i++)
    {
        total_tat += tat[i];
        total_wt += wt[i];
    }

    print(at, bt, ct, tat, wt, total_tat, total_wt, n);

    return 0;
}
