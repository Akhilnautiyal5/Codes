#include <stdio.h>

#define P 5 // Number of processes
#define R 3 // Number of resources

int main()
{
    int max[P][R] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
    int alloc[P][R] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};
    int avail[R] = {10, 5, 7};
    int need[P][R], safeSeq[P], finish[P] = {0};
    int work[R], count = 0;

    // Calculate Need matrix
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Copy available resources to work vector
    for (int i = 0; i < R; i++)
        work[i] = avail[i];

    // Find a safe sequence
    while (count < P)
    {
        int found = 0;
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
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found)
        {
            printf("Request cannot be fulfilled\n");
            return 0;
        }
    }

    for (int k = 0; k < P; k++) {
        for (int i = 0; i < P; i++) {
            if (finish[i] == 0) {
                int flag = 0;
                for (int j = 0; j < R; j++) {
                    if (need[i][j] > avail[i]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0){
                    for (int y = 0; y < R; y++) {
                        avail[i] += alloc[i][y];
                    }
                    safeSeq[count++] = i;
                    finish[i] = 1;
                }
            }
        }
    }

        // Output safe sequence
        printf("Request can be fulfilled\nSafe Sequence: ");
    for (int i = 0; i < P; i++)
        printf("P%d ", safeSeq[i]);
    printf("\n");

    return 0;
}
