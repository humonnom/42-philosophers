#include "philo_one.h"

int
	gen_philos(t_philo **head, t_rule *rule)
{
	t_philo			*philos;
	int				i;

	philos = (t_philo*)malloc(sizeof(t_philo) * rule->number_of_philos);
	if (!philos)
		return (1);
	i = -1;
	while (++i < rule->number_of_philos)
	{
		philos[i].rule = rule;
		philos[i].philo_id = i + 1;
		philos[i].eat_start = (uint64_t)rule->start_time;
		philos[i].eat_left = rule->time_to_eat;
		philos[i].time_left = rule->time_to_die;
		philos[i].left_fork = philos[i].philo_id % rule->number_of_philos;
		philos[i].right_fork = (philos[i].philo_id - 1) % rule->number_of_philos;
		philos[i].hands = TYPE_NONE;
	}
	*head = philos;
	return (0);
}
