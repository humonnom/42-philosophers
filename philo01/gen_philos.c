#include "philo_one.h"

int
	gen_philos(t_philo **head, int number_of_philos)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo*)malloc(sizeof(t_philo) * number_of_philos);
	if (!philos)
		return (1);
	i = -1;
	while (++i < number_of_philos)
	{
		philos[i].philo_id = i + 1;
		philos[i].eat_start = 0;
		philos[i].sleep_start = 0;
		philos[i].eat_count = 0;
		philos[i].time_left = 0;
		philos[i].left_fork = philos[i].philo_id % number_of_philos;
		philos[i].right_fork = (philos[i].philo_id - 1) % number_of_philos;
	}
	*head = philos;
	return (0);

}
