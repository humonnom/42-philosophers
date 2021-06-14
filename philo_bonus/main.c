#include "philo_bonus.h"
#define NUM 5

int
    create_exa(pid_t **exa)
{
    *exa = (pid_t *)malloc(sizeof(pid_t) * NUM);
    if (!(*exa))
        return (1);
    return (0);
}

int
    philo_iter(pid_t *exa, int (*f)(pid_t))
{
    int     ret;
    int     i;
    
    ret = 0;
    if (exa == NULL)
        ret = 1;
    i = -1;
    while (++i < NUM && !ret)
        ret = f(exa[i]);
    return (ret);
}

int
    clone_philos(pid_t *exa)
{
    int     i;

    i = -1;
    while (++i < NUM)
    {
        printf("[%d] fork\n", i);
        exa[i] = fork();
        if (exa[i] == 0)
            break;
    }
    return (0);
}

int
    wait_philos(pid_t *exa)
{
    int     status;
    int     i;
    
    status = 0;
    i = -1;
    while (++i < NUM)
    {
        if (exa[i] == 0)
        {
            do_something(i);
            printf("[%d] exit\n", i);
            exit(0);
        }
        else
        {
            waitpid(exa[i], &status, 0);
            if (status)
                return (1);
        }
    }
    return (0);
}

int main()
{
    pid_t   *exa;
    int     ret;

    ret = create_exa(&exa);
    //printf("ret: %d\n", ret);
    if (!ret)
        ret = clone_philos(exa);
    //printf("ret: %d\n", ret);
    if (!ret)
        ret = wait_philos(exa);
    //printf("ret: %d\n", ret);
    printf("bonus\n");
}