#include "philo_one.h"

int
    set_rule_info(
                    t_rule *rule,
                    char **info_str,
                    int arg_num)
{
    rule->number_of_philo = ft_atoi(info_str[0]);
    rule->time_to_die = ft_atoi(info_str[1]);
    rule->time_to_eat = ft_atoi(info_str[2]);
    rule->time_to_sleep = ft_atoi(info_str[3]);
    if (arg_num == DECICED_EAT_NUM)
        rule->number_of_eat = ft_atoi(info_str[4]);
    else
        rule->number_of_eat = UNDECIDED;
    return (0);
}