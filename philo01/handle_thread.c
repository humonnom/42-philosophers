#include "philo_one.h"

int
	handle_thread(t_info *info)
{
	pthread_t	tid;
	int			ret;
	int			status;
	void		*arg;
	int			i;

	info->rule.start_time = get_time();
	//printf("%d\n", info->rule.number_of_eat);
    //routine_watch...
	if (info->rule.number_of_eat > 0)
	{
		if (pthread_create(&tid, NULL, &watch_count, (void *)&(info->rule)))
			return (1);
	}
	ret = 0;
	i = -1;
	while (++i < info->rule.number_of_philos)
	{
		arg = &(info->philo[i]);
		ret = pthread_create(&info->philo[i].thread, NULL, &philo_routine, arg);
		if (ret)
		{
			info->errcode = ret;
			return (1);
		}
		//ret = pthread_join(info->philo[i].thread, (void *)&status);
		//printf("%d join result: %d\n", i, ret);
	}
	i = -1;
	while (++i < info->rule.number_of_philos)
		ret = pthread_join(info->philo[i].thread, (void *)&status);
	return (0);
}
