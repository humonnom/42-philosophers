#include "philo_one.h"

void
	grab_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->forks[philo->left_fork]);
	display_message(philo, TYPE_FORK);
	pthread_mutex_lock(&philo->forks[philo->right_fork]);
	display_message(philo, TYPE_FORK);
	return ;
}
