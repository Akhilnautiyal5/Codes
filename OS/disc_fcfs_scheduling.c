#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("enter total requests: \n");
    // scanf("%d", &n);
    int n = 8;
    printf("enter requests sequences: \n");
    // for (int i=0; i<n; i++)
    // scanf("%d", &Rq[i]);
    int Rq[8] = {98, 183, 37, 122, 14, 124, 65, 67};
    
    printf("enter initial head: \n");
    int initial = 53;
    
    int total_head_movement = 0;
    for (int i=0; i<n; i++) {
      total_head_movement += abs(Rq[i] - initial);
      initial = Rq[i];
    }
    
    printf("total head movement: %d", total_head_movement);
}
