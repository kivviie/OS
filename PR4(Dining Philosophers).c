
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5

sem_t fork[N];
sem_t room;

void* philosopher(void* arg)
{
    int id = *(int*)arg;

    printf("Philosopher %d is thinking\n", id);

    sem_wait(&room);

    sem_wait(&fork[id]);
    sem_wait(&fork[(id + 1) % N]);

    printf("Philosopher %d is eating\n", id);
    sleep(1);

    sem_post(&fork[id]);
    sem_post(&fork[(id + 1) % N]);

    sem_post(&room);

    printf("Philosopher %d finished eating\n", id);

    return NULL;
}

int main()
{
    pthread_t t[N];
    int id[N];

    sem_init(&room, 0, N - 1);

    for(int i = 0; i < N; i++)
        sem_init(&fork[i], 0, 1);

    for(int i = 0; i < N; i++)
    {
        id[i] = i;
        pthread_create(&t[i], NULL, philosopher, &id[i]);
    }

    for(int i = 0; i < N; i++)
        pthread_join(t[i], NULL);

    for(int i = 0; i < N; i++)
        sem_destroy(&fork[i]);

    sem_destroy(&room);

    return 0;
}




2. Compile:
gcc pr4.c -o pr4 -pthread


3. Run:
./pr4
