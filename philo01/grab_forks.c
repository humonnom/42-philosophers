#include "philo_one.h"

int
	grab_forks(t_philo *philo)
{
	if (philo->philo_id % 2)
	{
		pthread_mutex_lock(&philo->rule->forks[philo->right_fork]);
		pthread_mutex_lock(&philo->rule->forks[philo->left_fork]);
	}
	else
	{
		pthread_mutex_lock(&philo->rule->forks[philo->left_fork]);
		pthread_mutex_lock(&philo->rule->forks[philo->right_fork]);
	}
	philo->hands = TYPE_FORK;
	if (display_message(philo, TYPE_FORK))
		return (1);
	if (display_message(philo, TYPE_FORK))
		return (1);
	return (0);
}
