
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int a[20], n, i, j, temp;
    pid_t pid;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    pid = fork();

    if(pid == 0)
    {
        // Child process: Ascending order
        printf("\nChild Process\n");

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n - i - 1; j++)
            {
                if(a[j] > a[j + 1])
                {
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }

        printf("Ascending order: ");
        for(i = 0; i < n; i++)
            printf("%d ", a[i]);
    }
    else if(pid > 0)
    {
        // Parent process: Descending order
        wait(NULL);

        printf("\n\nParent Process\n");

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n - i - 1; j++)
            {
                if(a[j] < a[j + 1])
                {
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }

        printf("Descending order: ");
        for(i = 0; i < n; i++)
            printf("%d ", a[i]);
    }
    else
    {
        printf("Fork failed");
    }

    return 0;
}



Save the program and execute:
gcc pr2.c -o pr2
./pr2
