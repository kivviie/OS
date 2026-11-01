
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/wait.h>

int main()
{
    int p1[2], p2[2];
    char str[100], result[200];
    int i, chars = 0, words = 0, lines = 0;
    int inword = 0;

    pipe(p1);
    pipe(p2);

    if(fork() == 0)
    {
   
        close(p1[1]);
        close(p2[0]);

        read(p1[0], str, sizeof(str));
        close(p1[0]);

        for(i = 0; str[i] != '\0'; i++)
        {
            if(str[i] != '\n')
                chars++;

            if(str[i] == '\n')
                lines++;

            if(isspace(str[i]))
                inword = 0;
            else if(inword == 0)
            {
                words++;
                inword = 1;
            }
        }

        if(chars > 0 && lines == 0)
            lines = 1;

        FILE *fp = fopen("output.txt", "w");

        fprintf(fp, "Characters: %d\n", chars);
        fprintf(fp, "Words: %d\n", words);
        fprintf(fp, "Lines: %d\n", lines);

        fclose(fp);

        fp = fopen("output.txt", "r");

        while(fgets(result, sizeof(result), fp) != NULL)
            write(p2[1], result, strlen(result));

        fclose(fp);
        close(p2[1]);

        exit(0);
    }
    else
    {

      
        close(p1[0]);
        close(p2[1]);

        printf("Enter a sentence: ");
        fgets(str, sizeof(str), stdin);

        write(p1[1], str, strlen(str) + 1);
        close(p1[1]);

        wait(NULL);

        printf("\nResult received from child process:\n");

        int n;
        while((n = read(p2[0], result, sizeof(result))) > 0)
        {
            write(1, result, n);
        }

        close(p2[0]);
    }

    return 0;
}
