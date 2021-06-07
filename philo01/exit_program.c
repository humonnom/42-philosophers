#include "philo_one.h"

int
	exit_program(t_philo *philo)
{
	//printf("PROGRAM OVER :from %d\n", philo->philo_id);
	if (philo->rule->errcode)
		display_err_message(philo->rule->errcode);
	if (philo->rule->state == TYPE_DIED)
		pthread_mutex_unlock(&philo->rule->write_mutex);
	return (1);
}
