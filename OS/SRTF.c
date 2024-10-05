#include <stdio.h>
#include <limits.h>  // For INT_MAX

// Function to find the waiting time for all processes
void findWaitingTime(int processes[], int n, int bt[], int at[], int wt[])
{
    int remaining_bt[n];  // Store remaining burst times of processes
    int complete = 0, currentTime = 0, shortest = 0;
    int finish_time;
    int min_burst_time = INT_MAX;  // Start with maximum possible burst time
    int check = 0;

    // Initialize remaining burst times
    for (int i = 0; i < n; i++)
        remaining_bt[i] = bt[i];

    // Loop until all processes get completed
    while (complete != n) 
    {
        // Find process with the smallest remaining burst time that has arrived
        for (int j = 0; j < n; j++) 
        {
            if ((at[j] <= currentTime) && (remaining_bt[j] < min_burst_time) && remaining_bt[j] > 0) 
            {
                min_burst_time = remaining_bt[j];
                shortest = j;
                check = 1;
            }
        }

        if (check == 0) 
        {
            currentTime++;  // No process has arrived yet
            continue;
        }

        // Reduce the remaining burst time of the selected process
        remaining_bt[shortest]--;

        // Update minimum burst time
        min_burst_time = remaining_bt[shortest];
        if (min_burst_time == 0)
            min_burst_time = INT_MAX;

        // If a process gets completed
        if (remaining_bt[shortest] == 0) 
        {
            complete++;
            check = 0;

            // Find the finish time of the current process
            finish_time = currentTime + 1;

            // Calculate waiting time
            wt[shortest] = finish_time - bt[shortest] - at[shortest];

            // If waiting time is negative, set it to 0
            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }

        // Move to the next unit of time
        currentTime++;
    }
}

// Function to calculate turn around time
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];  // Turnaround time = burst time + waiting time
}

// Function to calculate average time and display process info
void findavgTime(int processes[], int n, int bt[], int at[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    // Calculate waiting time for all processes
    findWaitingTime(processes, n, bt, at, wt);

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
    int n;

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

    // Calculate and display average time
    findavgTime(processes, n, burst_time, arrival_time);

    return 0;
}