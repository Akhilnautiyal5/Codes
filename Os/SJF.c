#include<stdio.h>

// Function to swap two values
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort processes by burst time
void sortProcessesByBurstTime(int processes[], int bt[], int at[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // Sort by burst time, but make sure processes have already arrived
            if (bt[i] > bt[j] && at[j] <= at[i]) {
                swap(&bt[i], &bt[j]);
                swap(&at[i], &at[j]);
                swap(&processes[i], &processes[j]);
            }
        }
    }
}

// Function to find the waiting time for all processes
void findWaitingTime(int processes[], int n, int bt[], int at[], int wt[]) 
{
    sortProcessesByBurstTime(processes, bt, at, n);  // Sort processes by burst time

    int service_time[n];
    service_time[0] = at[0];  // Service time for the first process is its arrival time
    wt[0] = 0;  // Waiting time for the first process is 0

    // Calculating waiting time for subsequent processes
    for (int i = 1; i < n; i++) 
    {
        // Add burst time of previous processes
        service_time[i] = service_time[i-1] + bt[i-1];

        // Waiting time = service_time - arrival_time
        wt[i] = service_time[i] - at[i];

        // If waiting time is negative, set it to 0 (meaning the process hasn't waited)
        if (wt[i] < 0)
            wt[i] = 0;
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

    // Calculate waiting time of all processes
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
