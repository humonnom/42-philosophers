#include "philo.h"

t_public
	*call_public(void)
{
	static t_public	instance;
	return (&instance);
}
