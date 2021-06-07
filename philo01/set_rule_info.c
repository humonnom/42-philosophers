#include "philo_one.h"

static int
    set_forks_info(t_rule *rule)
{
    int             i;
    rule->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * rule->number_of_philos);
	if (!rule->forks)
		return (1);
    i = -1;
    while (++i < rule->number_of_philos)
        pthread_mutex_init(&rule->forks[i], NULL);
    rule->status = (int *)malloc(sizeof(int) * rule->number_of_philos + 1);
	if (!rule->status)
    {
        free(rule->forks);
		return (1);
    }
    i = 0;
    while (++i < rule->number_of_philos + 1)
        rule->status[i] = TYPE_HUNGRY;
    return (0);
}

void
    init_mutexs(t_rule *rule)
{
    pthread_mutex_init(&rule->write_mutex, NULL);
    pthread_mutex_init(&rule->check_fork_mutex, NULL);
    //pthread_mutex_init(&rule->watch_mutex, NULL);
}


int
    set_rule_info(
                    t_rule *rule,
                    char **info_str,
                    int arg_num)
{
    rule->number_of_philos = ft_atoi(info_str[0]);
    rule->time_to_die = (uint64_t)ft_atoi(info_str[1]);
    rule->time_to_eat = (uint64_t)ft_atoi(info_str[2]);
    rule->time_to_sleep = (uint64_t)ft_atoi(info_str[3]);
    if (arg_num == DECICED_EAT_NUM)
        rule->number_of_eat = ft_atoi(info_str[4]);
    else
        rule->number_of_eat = UNDECIDED;
    rule->start_time = get_time();
    if (set_forks_info(rule))
        return (1);
    init_mutexs(rule);
    rule->state = TYPE_HUNGRY;
    rule->errcode = 0;
    return (0);
}
