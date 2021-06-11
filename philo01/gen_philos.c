#include "philo_one.h"

int
	gen_philos(t_rule *rule)
{
	int				i;

	rule = call_rule();
	rule->philo = (t_philo*)malloc(sizeof(t_philo) * rule->number_of_philos);
	if (!rule->philo)
		return (1);
	i = -1;
	while (++i < rule->number_of_philos)
	{
		rule->philo[i].id = i + 1;
		rule->philo[i].eat_start = (uint64_t)rule->start_time;
		rule->philo[i].eat_left = rule->number_of_eat;
		rule->philo[i].time_left = rule->time_to_die;
		rule->philo[i].left_fork = rule->philo[i].id % rule->number_of_philos;
		rule->philo[i].right_fork = (rule->philo[i].id - 1) % rule->number_of_philos;
		rule->philo[i].hands = TYPE_NONE;
		rule->philo[i].eat_start = rule->start_time;
	}
	return (0);
}
