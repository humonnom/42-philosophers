#include "philo.h"

t_rule
	*call_rule(void)
{
	static t_rule	instance;
	return (&instance);
}