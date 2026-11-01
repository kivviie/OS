#include <stdio.h>
#include <stdlib.h>

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


    for(i = 0; i < n - 1; i++)
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

    printf("\nSeek Sequence: %d", head);

    
    for(i = 0; i < n; i++)
    {
        if(a[i] >= head)
        {
            total += abs(a[i] - head);
            head = a[i];
            printf(" -> %d", head);
        }
    }

    
    total += abs(199 - head);
    head = 199;
    printf(" -> %d", head);

    for(i = n - 1; i >= 0; i--)
    {
        if(a[i] < head)
        {
            total += abs(a[i] - head);
            head = a[i];
            printf(" -> %d", head);
        }
    }

    printf("\nTotal Head Movement = %d cylinders", total);

    return 0;
}
