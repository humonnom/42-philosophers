#include "philo_one.h"

int
	main(int argc, char **argv)
{
	t_info	info;
	int		ret;

	ret = 0;
	if (is_invalid_arg_num(argc))
		ret = INVALID_ARGC;
	if (!ret && set_rule_info(&(info.rule), &argv[1], argc))
		ret = FAIL_MALLOC;
	if (!ret && is_invalid_rule(&(info.rule)))
		ret = INVALID_RULE;
	if (!ret && gen_philos(&(info.philo), &(info.rule)))
		ret = FAIL_MALLOC;
	if (!ret)
		ret = handle_thread(&info);
	// test
	// if (!ret)
	// 	print_philos(info.philo, info.rule.number_of_philos);

	//detach
	// printf("time to die is %d\ntime to eat is %d\ntime to sleep is %d\n", info.rule.time_to_die, info.rule.time_to_eat, info.rule.time_to_sleep);
	// printf("%d philos has to eat %d times\n", info.rule.number_of_philos, info.rule.number_of_eat);

	// if (ret != FAIL_MALLOC)
	// 	handle_resources(info.philo);
	if (ret)
	{
		info.rule.errcode = ret;
		exit_program(info.philo);
	}
	// while(1)
	// 	;
	return (ret);
}
