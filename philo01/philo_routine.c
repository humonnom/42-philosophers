#include "philo_one.h"

static void
	*watch_philos_life(void *arg)
{
	uint64_t	now;
	t_philo		*philo;

	philo = (t_philo *)arg;
	now = get_time();
	philo->time_left = now + philo->rule->time_to_die;
	while (1)
	{
		pthread_mutex_lock(&philo->mutex);
		if (philo->status != TYPE_EAT && now > philo->time_left)
		{
			display_message(philo, TYPE_DIED);
			pthread_mutex_unlock(&philo->mutex);
			return ((void *)NULL);
		}
		pthread_mutex_unlock(&philo->mutex);
		usleep(1000);
	}
}


static int
	check_if_philo_died(t_philo *philo)
{
	pthread_t	tid;
	int			status;
	int			ret;

	if (pthread_create(&tid, NULL, &watch_philos_life, (void *)philo))
		return (0);
	pthread_detach(tid);
	return (1);
}

void
	*philo_routine(void *arg)
{
	t_philo 	*philo;

	philo = (t_philo *)arg;
	if (!check_if_philo_died(philo))
		return ((void *)1);
	while (1)
	{
		//printf("[%d]\n", philo->philo_id);
		grab_forks(philo);
		//printf("[grabed]\n");
		//print_forks_status(philo, 4);
		pthread_mutex_lock(&philo->mutex);
		act_eat(philo);
		//printf("[dumped]\n");
		//print_forks_status(philo, 4);
		act_sleep(philo);
		// printf("sleep\n");
		dump_forks(philo);
		pthread_mutex_unlock(&philo->mutex);
		act_think(philo);
		// printf("think\n");
	}
	return (0);
}
