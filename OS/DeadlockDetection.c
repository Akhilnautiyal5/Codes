#include <stdio.h>

#define P 3 // Number of processes
#define R 3 // Number of resources

int main()
{
    int max[P][R] = {{3, 2, 2}, {9, 0, 2}, {2, 2, 2}};
    int alloc[P][R] = {{2, 0, 0}, {3, 0, 2}, {2, 1, 1}};
    int avail[R] = {0, 0, 0};
    int need[P][R], finish[P] = {0};
    int work[R], found;

    // Calculate Need matrix
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Copy available resources to work vector
    for (int i = 0; i < R; i++)
        work[i] = avail[i];

    // Check if deadlock occurs
    while (1)
    {
        found = 0;
        for (int i = 0; i < P; i++)
        {
            if (finish[i] == 0)
            {
                int j;
                for (j = 0; j < R; j++)
                    if (need[i][j] > work[j])
                        break;

                if (j == R)
                { // If needs can be met
                    for (int k = 0; k < R; k++)
                        work[k] += alloc[i][k];
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found)
            break;
    }

    // Check if any process is unfinished, indicating deadlock
    for (int i = 0; i < P; i++)
    {
        if (finish[i] == 0)
        {
            printf("Deadlock detected\n");
            return 0;
        }
    }

    printf("No deadlock detected\n");

    return 0;
}
