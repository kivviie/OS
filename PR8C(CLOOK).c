
#include <stdio.h>

int main()
{
    int n, head, i, j, total = 0;
    int a[20], temp;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

  
    for(i = 0; i < n; i++)
    {
        if(a[i] >= head)
            break;
    }

    printf("\nSeek Sequence: %d", head);

   
    for(j = i; j < n; j++)
    {
        total += abs(a[j] - head);
        head = a[j];
        printf(" -> %d", head);
    }

    if(i > 0)
    {
        total += abs(head - a[0]);
        head = a[0];
        printf(" -> %d", head);

        for(j = 1; j < i; j++)
        {
            total += abs(a[j] - head);
            head = a[j];
            printf(" -> %d", head);
        }
    }

    printf("\nTotal head movement = %d\n", total);

    return 0;
}
