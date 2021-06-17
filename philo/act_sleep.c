#include "philo.h"

int
	act_sleep(t_philo *philo)
{
	t_public	*public;
	int			ret;

	public = call_public();
	ret = display_message(philo, TYPE_SLEEP);
	if (!ret)
		ret = usleep_loop(public->time_to_sleep);
	return (ret);
}
