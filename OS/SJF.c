#include <stdio.h>

void print(int at[], int bt[], int ct[], int tat[], int wt[], float total_tat, float total_wt)
{
    printf("\nPId\tAT\tBT\tCT\tTAT\tWT\n\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%d\t %d\t %d\t %d\t %d\t %d\t \n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("Average Turnaround Time: %.2f\n", total_tat / 4); // Average TAT
    printf("Average Waiting Time: %.2f\n", total_wt / 4);     // Average WT
}

int main()
{
    // int at[] = {0, 0, 0}; // Arrival times
    // int bt[] = {4, 2, 4}; // Burst times
    //output: avg_tat -> 5.33, avg_wt -> 2.33

    int at[] = {0, 1, 2, 3};
    int bt[] = {5, 3, 8, 6};
    //output: avg_tat -> 10.75, avg_wt -> 5.25

    int ct[4], tat[4], wt[4]; // Completion time, Turnaround time, Waiting time
    float total_tat = 0, total_wt = 0;

    int completed[4] = {0}; // Track completed processes
    int currentTime = 0, completedProcesses = 0;

    // Calculate completion times
    while (completedProcesses < 4)
    {
        int minIndex = -1;
        int minBurst = 9999;

        // Find the next process to execute (with the shortest burst time)
        for (int i = 0; i < 4; i++)
        {
            if (at[i] <= currentTime && !completed[i] && bt[i] < minBurst)
            {
                minBurst = bt[i];
                minIndex = i;
            }
        }

        if (minIndex != -1)
        {
            // Process found
            currentTime += bt[minIndex]; // Update current time
            ct[minIndex] = currentTime;  // Set completion time
            completed[minIndex] = 1;     // Mark process as completed
            completedProcesses++;
        }
        else
        {
            // No process is ready, increment current time
            currentTime++;
        }
    }

    // Calculate turnaround time (TAT) and waiting time (WT)
    for (int i = 0; i < 4; i++)
    {
        tat[i] = ct[i] - at[i]; // TAT = CT - AT
        wt[i] = tat[i] - bt[i]; // WT = TAT - BT
        total_tat += tat[i];
        total_wt += wt[i];
    }

    // Print the table
    print(at, bt, ct, tat, wt, total_tat, total_wt);

    return 0;
}
