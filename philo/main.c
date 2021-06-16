#include "philo.h"

int
	main(int argc, char **argv)
{
	t_public	*public;
	int			ret;

	ret = 0;
	public = call_public();
	if (is_invalid_argc(argc))
		ret = INVALID_ARGC;
	if (!ret && set_public(public, &argv[1], argc))
		ret = FAIL_MALLOC;
	if (!ret && is_invalid_rule(public))
		ret = INVALID_RULE;
	if (!ret && gen_philos(public))
		ret = FAIL_MALLOC;
	if (!ret)
		ret = handle_thread(public);
	if (ret)
	{
		public->errcode = ret;
		display_err_message(public->errcode);
	}
	//printf("main stop\n");
	garbage_collector();
	return (ret);
}
