
#include <stdio.h>
#include <stdlib.h>
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
        // Child process
        printf("\nChild Process\n");

        for(i = 0; i < n-1; i++)
        {
            for(j = 0; j < n-i-1; j++)
            {
                if(a[j] > a[j+1])
                {
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
            }
        }

        printf("Sorted elements: ");
        for(i = 0; i < n; i++)
            printf("%d ", a[i]);

        printf("\nChild process ID: %d\n", getpid());
        exit(0);
    }
    else if(pid > 0)
    {
        // Parent process
        printf("\nParent Process\n");
        printf("Parent process ID: %d\n", getpid());

        wait(NULL);

        printf("Child process completed.\n");
    }
    else
    {
        printf("Fork failed!\n");
        return 1;
    }

    return 0;
}


Save the program and execute:
gcc pr2.c -o pr2
./pr2
