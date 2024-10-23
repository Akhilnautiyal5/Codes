#include <stdio.h>
void print(int at[], int bt[], int ct[], int tat[], int wt[], float total_tat, float total_wt)
{
    printf("\nPId\tAT\tBT\tCT\tTAT\tWT\n\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%d\t %d\t %d\t %d\t %d\t %d\t \n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("Average turn around time: %f\n", total_tat / 4);
    printf("Average waiting time: %f\n", total_wt / 4);
}

int main()
{
    int at[] = {0, 1, 2, 3};
    int bt[] = {5, 3, 8, 6};
    int ct[4], tat[4], wt[4];
    float total_tat = 0, total_wt = 0;

    // completion time
    int sum = at[0];
    for (int i = 0; i < 4; i++)
    {
        sum = sum + bt[i];
        ct[i] = sum;
    }

    // tat wt
    for (int i = 0; i < 4; i++)
    {
        tat[i] = ct[i] - at[i];
        total_tat += tat[i];
        wt[i] = tat[i] - bt[i];
        total_wt += wt[i];
    }

    // table
    print(at, bt, ct, tat, wt, total_tat, total_wt);

    return 0;
}
