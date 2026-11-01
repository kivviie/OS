#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, head, i, j, total = 0;
    int a[20], visited[20] = {0};

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    for(i = 0; i < n; i++)
    {
        int min = 9999, pos = -1;

        for(j = 0; j < n; j++)
        {
            if(!visited[j] && abs(head - a[j]) < min)
            {
                min = abs(head - a[j]);
                pos = j;
            }
        }

        visited[pos] = 1;
        total += min;
        head = a[pos];

        printf("%d ", head);
    }

    printf("\nTotal Head Movement = %d", total);

    return 0;
}
