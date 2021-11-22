#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t mutex;
int g_number;

void print_index_loop(char *str, int max) {
    int i;

    i = 0;
    pthread_mutex_lock(&mutex);
    while (i < max) {
        g_number++;
        printf("[%s] %d\n", str, g_number);
        usleep(1000 * 100);
        ++i;
    }
    pthread_mutex_unlock(&mutex);
}

void *thread_routine(void *arg) {
    print_index_loop((char *)arg, 5);
    return (NULL);
}

int main() {
    pthread_t tid;
    void *t_res;
    int state;
    int create_res;
    int join_res;

    //pthread_mutex_init -- create a mutex
    //		args:	1. mutex()
    //				2. attr(속성) if it's NULL --> default attributes are used.
    //				success: 0, fail: errno

    g_number = 0;
    state = pthread_mutex_init(&mutex, NULL);
    if (state) {
        printf("fail to init mutex\n");
        exit(1);
    }
    create_res = pthread_create(&tid, NULL, thread_routine, (void *)"thread");
    if (create_res != 0)
        return (1);
    thread_routine((void *)"main");
    join_res = pthread_join(tid, NULL);
    printf("join result: %d\n", join_res);
}
