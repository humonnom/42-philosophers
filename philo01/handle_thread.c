#include "philo_one.h"

static void
	*save_tid_to_rule(void *info)
{
	pthread_mutex_t	mutex;

	info = (t_info *)info;
	pthread_mutex_lock(&mutex);
	printf("eat\n");
	pthread_mutex_unlock(&mutex);
	printf("sleep\n");
	printf("think\n");
	return (0);
}

static int
	create_thread(t_info *info ,int p_num)
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
	//have to confirm if "number of eat" is not defined, how to handle it.
	// my case: in case not defined, "number of eat" is -1.
	if (info->rule.number_of_eat > 0)
	{
		printf("must eat > 0\n");
        //routine_monitor...
	}
	printf("must eat == 0 or -1\n");
	return (0);
}