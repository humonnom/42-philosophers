#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

int g_num = 0;

void p() {
    while (g_num <= 0)
    {
        usleep(1000 * 1000);
        if (g_num > 0)
            break;
        printf("busy waiting[%d]...\n", g_num);
    }
    g_num--;
    printf("p made g_num `%d`\n", g_num);
 }

void v() {
    g_num++;
    printf("v made g_num `%d`\n", g_num);
 }

void
    *routine_1(void *arg)
{
    p(); // get the key. key: 0
    return ((void *)0);
}

void
    *routine_2(void *arg)
{
    v(); // return the key. key: 1
    return ((void *)0);
}

int main()
{
    pthread_t   t[2];
    
    pthread_create(&t[0], NULL, &routine_1, NULL);
    usleep(1000 * 1000 * 5);
    pthread_create(&t[1], NULL, &routine_2, NULL);
   
    pthread_join(t[0], NULL);
    pthread_join(t[1], NULL);

}