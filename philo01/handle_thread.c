#include "philo_one.h"

void
	*philo_routine(void *arg)
{
	int 	time;
	t_philo *philo;
	philo = (t_philo *)arg;
	//printf("[%d]\n", philo->philo_id);
	time = 3;
	// get((philo_id) % philo->, (philo_id + 1) )
	// mutex on
	pthread_mutex_lock(&philo->mutex);
	eat(time);
	// mutex off
	pthread_mutex_unlock(&philo->mutex);
	// throwaway(philo_id, philo_id + 1)

	return (NULL);
}

static void
	*save_tid_to_rule(void *info)
{
	pthread_mutex_t	mutex;

	info = (t_info *)info;
	//pthread_mutex_lock(&mutex);
	printf("eat\n");
	//pthread_mutex_unlock(&mutex);
	printf("sleep\n");
	printf("think\n");
	return (0);
}

static int
	gen_thread(t_info *info ,int p_num)
{
	pthread_t		tid;
	int				ret;

	ret = 0;
	p_num++;
	//middle of process
	while(--p_num && !ret)
	{
		printf("p_num is %d\n", p_num);
		if (pthread_create(&tid, NULL, save_tid_to_rule, (void *)info) != 0)
			return (1);
		//pthread_join(tid, NULL);
	}
	//free head
	return (ret);
}

int
	handle_thread(t_info *info)
{
	pthread_t	tid;
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
		//usleep(100);
		ret = pthread_join(info->philo[i].thread, (void *)&status);
		printf("%d join result: %d\n", i, ret);
	}
	// i = -1;
	// while (++i < info->rule.number_of_philos)
	// {

	// }
	return (0);
}
