#include "philo_one.h"

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
    return (0);
}
