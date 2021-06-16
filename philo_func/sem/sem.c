// exit stdlib.h
// fork stdio.h
// kill signal.h sys/types.h

// semaphore.h
// sem_close
// sem_open
// sem_post
// sem_unlink
// sem_wait
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <semaphore.h>
#include <pthread.h>

int         g_num = 0;
sem_t       *sem;

void
    *routine_print(void *arg)
{
    char *str;

    //wait : lock the semaphore.(until call `post`)
    sem_wait(sem); // get the key.
    str = (char *)arg;
    while (*str)
    {
        printf("[%d]%c\n", g_num, *str);
        str++;
    }
    //post : unlock the semaphore.
    sem_post(sem); // return the key.
    return ((void *)0);
}

void
    *routine_edit(void *arg)
{
    char *str;

    sem_wait(sem);
    str = (char *)arg;
    while (*str)
    {
        g_num++;
        str++;
    }
    sem_post(sem);
    return ((void *)0);
}


int main()
{
    pthread_t   t[2];
   
    char        *str = "ABCDE";

    // init :   create semaphore without name.
    // open :   create semaphore with name.
    //          return semaphore descriptor(sd).(until call `close`)
    sem = sem_open("sem", 0, 0);

    // wait & post(inside the function)
    pthread_create(&t[0], NULL, &routine_print, (void *)str);
    usleep(1000);
    pthread_create(&t[1], NULL, &routine_edit, (void *)str);
   
    pthread_join(t[0], NULL);
    pthread_join(t[1], NULL);

    //unlink :  It is destroyed when all processes unlink the semaphore.
    //close :   destroy semaphore.
    sem_close(sem);
}