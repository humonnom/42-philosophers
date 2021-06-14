#include "philo.h"


int
	usleep_loop(int ms)
{
	t_rule		*rule;
	u_int64_t	start;
	u_int64_t	end;
	int		ret;

	rule = call_rule();
	start = get_time();
	end = start + ms;
	ret = 0;
	while (!ret)
	{
		if (get_time() >= end)
			break;
		if (rule->state == TYPE_DIED)
			ret = 1;
		usleep(50);
	}
	return (ret);
}
