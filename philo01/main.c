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
		ret = 1;
	if (!ret && is_invalid_rule(&(info.rule)))
		ret = INVALID_RULE;
	//create
	printf("before create thread\n");
	if (!ret && handle_thread(&info))
		ret = info.errcode;
	//do something

	//detach

	// printf("time to die is %d\ntime to eat is %d\ntime to sleep is %d\n", info.rule.time_to_die, info.rule.time_to_eat, info.rule.time_to_sleep);
	// printf("%d philos has to eat %d times\n", info.rule.number_of_philo, info.rule.number_of_eat);
	if (ret)
		print_err_msg(ret);
	return (ret);
}