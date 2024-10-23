#include <stdio.h>

void print(int at[], int bt[], int ct[], int tat[], int wt[], float total_tat, float total_wt)
{
    printf("\nPId\tAT\tBT\tCT\tTAT\tWT\n\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t %d\t %d\t %d\t %d\t %d\t\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("Average Turnaround Time: %.2f\n", total_tat / 5); // Average TAT
    printf("Average Waiting Time: %.2f\n", total_wt / 5);     // Average WT
}

int main()
{
    // int at[] = {2, 5, 1, 0, 4}; // Arrival times for P1, P2, P3, P4, P5
    // int bt[] = {6, 2, 8, 3, 4}; // Burst times for P1, P2, P3, P4, P5
    int at[] = {0, 1, 2, 3, 4};
    int bt[] = {2, 3, 1, 4, 5};

    int remainingTime[5];     // Remaining times for each process
    int ct[5], tat[5], wt[5]; // Completion time, Turnaround time, Waiting time
    float total_tat = 0, total_wt = 0;

    // Initialize remaining times
    for (int i = 0; i < 5; i++)
    {
        remainingTime[i] = bt[i];
    }

    int currentTime = 0, completedProcesses = 0;

    // SRTF algorithm
    while (completedProcesses < 5)
    {
        int minIndex = -1;
        int minRemainingTime = 9999;

        // Find the process with the shortest remaining time
        for (int i = 0; i < 5; i++)
        {
            if (at[i] <= currentTime && remainingTime[i] > 0 && remainingTime[i] < minRemainingTime)
            {
                minRemainingTime = remainingTime[i];
                minIndex = i;
            }
        }

        if (minIndex != -1)
        {
            // Execute the selected process for one unit of time
            remainingTime[minIndex]--;
            currentTime++;

            // If the process is finished, update completion time
            if (remainingTime[minIndex] == 0)
            {
                ct[minIndex] = currentTime; // Set completion time
                completedProcesses++;
            }
        }
        else
        {
            // If no process is ready, increment current time
            currentTime++;
        }
    }

    // Calculate turnaround time (TAT) and waiting time (WT)
    for (int i = 0; i < 5; i++)
    {
        tat[i] = ct[i] - at[i]; // TAT = CT - AT
        wt[i] = tat[i] - bt[i]; // WT = TAT - BT
        total_tat += tat[i];
        total_wt += wt[i];
    }

    // Print the results
    print(at, bt, ct, tat, wt, total_tat, total_wt);

    return 0;
}
