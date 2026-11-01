
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    int p1[2], p2[2];
    char filename[100], buffer[200];

    pipe(p1);
    pipe(p2);

    if(fork() == 0)
    {
        // Child process
        close(p1[1]);
        close(p2[0]);

        read(p1[0], filename, sizeof(filename));
        close(p1[0]);

        FILE *fp = fopen(filename, "r");

        if(fp == NULL)
        {
            strcpy(buffer, "File not found!");
        }
        else
        {
            int n = fread(buffer, 1, sizeof(buffer)-1, fp);
            buffer[n] = '\0';
            fclose(fp);
        }

        write(p2[1], buffer, strlen(buffer)+1);
        close(p2[1]);

        exit(0);
    }
    else
    {
        // Parent process
        close(p1[0]);
        close(p2[1]);

        printf("Enter filename: ");
        scanf("%99s", filename);

        write(p1[1], filename, strlen(filename)+1);
        close(p1[1]);

        wait(NULL);

        read(p2[0], buffer, sizeof(buffer));
        close(p2[0]);

        printf("\nContents of file:\n%s\n", buffer);
    }

    return 0;
}
