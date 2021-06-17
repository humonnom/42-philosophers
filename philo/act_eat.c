#include "philo.h"

static int
	grab_forks(t_public *public, t_philo *philo)
{
	pthread_mutex_lock(&public->forks[philo->left_fork]);
	pthread_mutex_lock(&public->forks[philo->right_fork]);
	philo->hands = HANDS_TYPE_FULL;
	if (display_message(philo, TYPE_GRAB))
		return (1);
	if (display_message(philo, TYPE_GRAB))
		return (1);
	return (0);
}

static void
	release_forks(t_public *public, t_philo *philo)
{
	pthread_mutex_unlock(&public->forks[philo->left_fork]);
	pthread_mutex_unlock(&public->forks[philo->right_fork]);
	philo->hands = HANDS_TYPE_EMPTY;
}

int
	act_eat(t_philo *philo)
{
	t_public	*public;
	int			ret;

	public = call_public();
	ret = grab_forks(public, philo);
	if (!ret)
	{
		philo->eat_left--;
		philo->eat_start = get_time();
	}
	if (!ret)
		ret = pthread_create(&philo->watcher, NULL, &watch_died, (void *)philo);
	if (!ret)
		ret = pthread_detach(philo->watcher);
	if (!ret)
		ret = display_message(philo, TYPE_EAT);
	if (!ret)
		ret = usleep_loop(public->time_to_eat);
	if (philo->hands == HANDS_TYPE_FULL)
		release_forks(public, philo);
	return (!!ret);
}
