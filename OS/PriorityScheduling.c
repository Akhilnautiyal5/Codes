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
    int n = 3;
    int at[] = {0, 0, 0};
    int bt[] = {10, 5, 8};
    int pt[] = {0, 2, 1}; // lower number = higher priority

    int ct[n], tat[n], wt[n];
    float total_tat = 0, total_wt = 0;

    int completed[n];
    for (int i = 0; i < n; i++)
    {
        completed[i] = 0;
    }

    int currentTime = 0, completedProcesses = 0;

    while (completedProcesses < n)
    {
        int idx = -1;
        int minPriority = 9999;

        // Find the highest priority process that has arrived
        for (int i = 0; i < n; i++)
        {
            if (at[i] <= currentTime && !completed[i] && pt[i] < minPriority)
            {
                minPriority = pt[i];
                idx = i;
            }
        }

        if (idx != -1)
        {
            currentTime += bt[idx];       // Update current time
            ct[idx] = currentTime;        // Set completion time
            tat[idx] = ct[idx] - at[idx]; // Turnaround time
            wt[idx] = tat[idx] - bt[idx]; // Waiting time
            completed[idx] = 1;           // Mark process as completed
            completedProcesses++;
        }
        else
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
