#include <stdio.h>

// Function to find waiting time for all processes
void findWaitingTime(int processes[], int n, int bt[], int at[], int wt[], int quantum)
{
    int remaining_bt[n];  // Store remaining burst times of processes
    int currentTime = 0;  // Keep track of the current time

    // Initialize remaining burst times
    for (int i = 0; i < n; i++)
        remaining_bt[i] = bt[i];

    while (1) 
    {
        int done = 1;  // To check if all processes are done

        for (int i = 0; i < n; i++) 
        {
            // Check if a process has remaining burst time and has arrived
            if (remaining_bt[i] > 0 && at[i] <= currentTime) 
            {
                done = 0;  // There is a pending process

                // If burst time is greater than the time quantum
                if (remaining_bt[i] > quantum) 
                {
                    // Increase the current time by the quantum
                    currentTime += quantum;

                    // Decrease the remaining burst time
                    remaining_bt[i] -= quantum;
                } 
                else 
                {
                    // If burst time is less than or equal to the quantum
                    // Increase the current time by the remaining burst time
                    currentTime += remaining_bt[i];

                    // Calculate waiting time
                    wt[i] = currentTime - bt[i] - at[i];

                    // Set remaining burst time to 0
                    remaining_bt[i] = 0;
                }
            }
        }

        // If all processes are done, exit the loop
        if (done == 1)
            break;
    }
}

// Function to calculate turn around time
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];  // Turnaround time = burst time + waiting time
}

// Function to calculate average time and display process info
void findavgTime(int processes[], int n, int bt[], int at[], int quantum)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    // Calculate waiting time of all processes
    findWaitingTime(processes, n, bt, at, wt, quantum);

    // Calculate turnaround time for all processes
    findTurnAroundTime(processes, n, bt, wt, tat);

    // Display processes along with all details
    printf("\nProcesses   Arrival time   Burst time   Waiting time   Turn around time\n");

    for (int i = 0; i < n; i++) 
    {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("   %d ", processes[i]);
        printf("          %d ", at[i]);
        printf("          %d ", bt[i]);
        printf("          %d ", wt[i]);
        printf("          %d\n", tat[i]);
    }

    float avg_wt = (float)total_wt / (float)n;
    float avg_tat = (float)total_tat / (float)n;
    printf("Average waiting time = %f\n", avg_wt);
    printf("Average turn around time = %f\n", avg_tat);
}

// Driver code
int main()
{
    int n, quantum;

    // Ask user for number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], burst_time[n], arrival_time[n];

    // Input burst time and arrival time for each process
    for (int i = 0; i < n; i++) 
    {
        processes[i] = i + 1;  // Process ID is assigned sequentially

        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &arrival_time[i]);

        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    // Input the time quantum
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    // Calculate and display average time
    findavgTime(processes, n, burst_time, arrival_time, quantum);

    return 0;
}