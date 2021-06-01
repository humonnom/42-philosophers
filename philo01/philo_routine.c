#include "philo_one.h"
#if 0
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

	if (pthread_create(&tid, NULL, &watch_philos_life, (void *)philo))
		return (0);
	pthread_detach(tid);
	return (1);
}
#endif

int
	check_both_side_status(t_philo *philo)
{
	int left;
	int right;


	left = philo->philo_id + 1;
	if (left > philo->rule->number_of_philos)
		left = 1;
	right = philo->philo_id - 1;
	if (right < 0)
		right = philo->rule->number_of_philos;
	if (philo->rule->status[left] == TYPE_EAT)
		return (1);
	if (philo->rule->status[right] == TYPE_EAT)
		return (1);
	return (0);
}

void
	*philo_routine(void *arg)
{
	t_philo 	*philo;

	philo = (t_philo *)arg;
	// if (!check_if_philo_died(philo))
	// 	return ((void *)1);
	while (1)
	{
		if (check_both_side_status(philo))
		{
			//printf("check\n");
			continue;
		}
		grab_forks(philo);
		act_eat(philo);
		dump_forks(philo);
		//act_sleep(philo);
		//act_think(philo);
		break;
	}
	return (0);
}
