#include "philo_one.h"

int
	handle_thread(t_info *info)
{
	int			ret;
	int			status;
	void		*arg;
	int			i;

	ret = 0;
	i = -1;
	watch_died_or_done(info);
	while (!ret && ++i < info->rule.number_of_philos)
	{
		arg = &(info->philo[i]);
		ret = pthread_create(&info->philo[i].thread, NULL, &philo_routine, arg);
		if (!ret && i == 0)
			usleep(1000);
	}
	i = -1;
	while (!ret && ++i < info->rule.number_of_philos)
		ret = pthread_join(info->philo[i].thread, (void **)&status);
	return (ret);
}
