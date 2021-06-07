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
	check_done(t_philo *philo)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(&philo->rule->write_mutex);
	if (philo->rule->status[philo->philo_id] == TYPE_DONE)
		ret = 1;
	//kill this thread;
	printf(ANSI_COLOR_MAGENTA"kill this thread\n"ANSI_COLOR_RESET);
	pthread_mutex_unlock(&philo->rule->write_mutex);
	return (ret);

}
		// if (check_done(philo))
		// 	return (0);
		// if (check_died(philo))
		// 	return (exit_program(philo));
#endif



int
	check_both_side_status(t_philo *philo)
{
	int left;
	int right;
	int ret;

	ret = 0;
	pthread_mutex_lock(&philo->rule->check_fork_mutex);
	left = philo->philo_id + 1;
	if (left > philo->rule->number_of_philos)
		left = 1;
	right = philo->philo_id - 1;
	if (right < 0)
		right = philo->rule->number_of_philos;
	if (philo->rule->status[left] == TYPE_EAT || philo->rule->status[right] == TYPE_EAT)
		ret = 1;
	pthread_mutex_unlock(&philo->rule->check_fork_mutex);
	return (ret);
}

void
	*philo_routine(void *arg)
{
	t_philo 	*philo;

	philo = (t_philo *)arg;
	if (pthread_create(&philo->watcher, NULL, &watch_died_or_done, arg))
		return ((void *)1);
	while (philo->rule->state != TYPE_DIED)
	{
		if (check_both_side_status(philo))
			continue;
		if (grab_forks(philo))
		{
			//printf("grab [%d]state: %d\n", philo->philo_id, philo->rule->status[philo->philo_id]);
			//printf("grab died\n");
			break ;
		}
		if (act_eat(philo))
		{
			//printf("eat [%d]state: %d\n", philo->philo_id, philo->rule->status[philo->philo_id]);
			//printf("eat died\n");
			break ;
		}
		if (philo->hands == TYPE_FORK)
			release_forks(philo);
		if (act_sleep(philo))
		{
			//printf("sleep [%d]state: %d\n", philo->philo_id, philo->rule->status[philo->philo_id]);
			//printf("sleep died\n");
			break ;
		}
		if (act_think(philo))
		{
			//printf("think [%d]state: %d\n", philo->philo_id, philo->rule->status[philo->philo_id]);
			//printf("think died\n");
			break ;
		}
	}
	//printf("exit philo routine[%d]state: %d\n", philo->philo_id, philo->rule->status[philo->philo_id]);
	//pthread_detach(philo->watcher);
	return (0);
}
