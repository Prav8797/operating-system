#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int i, j, n, head, sum=0;
    int queue[20];

    printf("Enter the number of requests: ");
    scanf("%d",&n);

    printf("Enter the requests: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&queue[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d",&head);

    sum = abs(head - queue[0]);
    for(i=0;i<n-1;i++)
    {
        sum += abs(queue[i] - queue[i+1]);
    }

    printf("\nTotal head movement = %d\n", sum);

    printf("\nAverage head movement = %.2f\n", (float)sum/n);

    return 0;
}
