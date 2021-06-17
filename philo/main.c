#include "philo.h"

int
	main(int argc, char **argv)
{
	t_public	*public;
	int			ret;

	public = call_public();
	ret = is_invalid_argc(argc);
	if (!ret)
		ret = set_public(public, &argv[1], argc);
	if (!ret && gen_philos(public))
		ret = FAIL_MALLOC;
	if (!ret)
		ret = handle_thread(public);
	if (ret)
		display_err_message(ret);
	garbage_collector();
	return (ret);
}
