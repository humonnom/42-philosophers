#include "philo_one.h"

int
	handle_thread(t_info *info)
{
	int			ret;
	int			status;

	//have to confirm if "number of eat" is not defined, how to handle it.
	// my case: in case not defined, "number of eat" is -1.

	// Check if all philos have eaten as much as they shoul...
	// if (info->rule.number_of_eat > 0)
	// {
	// 	printf("must eat > 0\n");
    //     //routine_monitor...
	// }
	void		*arg;
	int			i;

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
		//usleep(1000);
	}
	i = -1;
	while (++i < info->rule.number_of_philos)
	{
		ret = pthread_join(info->philo[i].thread, (void **)&status);
		printf("i: %d,\tret: %d\tstatus: %d\n", i, ret, status);
	}
	return (0);
}
