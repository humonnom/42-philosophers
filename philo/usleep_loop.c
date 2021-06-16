#include "philo.h"


int
	usleep_loop(int ms)
{
	t_public	*public;
	u_int64_t	start;
	u_int64_t	end;
	int		ret;

	public = call_public();
	start = get_time();
	end = start + ms;
	ret = 0;
	while (!ret)
	{
		if (get_time() >= end)
			break;
		//pthread_mutex_lock(&public->state_mutex);
		if (public->state == TYPE_DIED)
			ret = 1;
		//pthread_mutex_unlock(&public->state_mutex);
		usleep(50);
	}
	return (ret);
}
