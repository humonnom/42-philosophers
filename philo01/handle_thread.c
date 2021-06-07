#include "philo_one.h"

static int
	create_thread_group(t_info *info, int from)
{
	void	*arg;
	int		ret;
	int		i;

	ret = 0;
	i = from;
	while (!ret && i < info->rule.number_of_philos)
	{
		arg = &(info->philo[i]);
		ret = pthread_create(&info->philo[i].thread, NULL, &philo_routine, arg);
		if (!ret && i == 0)
			usleep(1000);
		i += 2;
	}
	return (ret);
}


int
	handle_thread(t_info *info)
{
	int		i;
	int		ret;
	int		status;

	ret = 0;
	if (create_thread_group(info, 0))
		ret = 1;
	if (!ret && create_thread_group(info, 1))
		ret = 1;
	i = -1;
	while (!ret && ++i < info->rule.number_of_philos)
		ret = pthread_join(info->philo[i].thread, (void **)&status);
	return (ret);
}
