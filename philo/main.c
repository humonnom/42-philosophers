#include "philo.h"

int
	main(int argc, char **argv)
{
	t_rule	*rule;
	int		ret;

	ret = 0;
	rule = call_rule();
	if (is_invalid_arg_num(argc))
		ret = INVALID_ARGC;
	if (!ret && set_rule(rule, &argv[1], argc))
		ret = FAIL_MALLOC;
	if (!ret && is_invalid_rule(rule))
		ret = INVALID_RULE;
	if (!ret && gen_philos(rule))
		ret = FAIL_MALLOC;
	if (!ret)
		ret = handle_thread(rule);
	if (ret)
	{
		rule->errcode = ret;
		printf("philo->rule->errcode:%d\n", rule->errcode);
		exit_program();
	}
	return (ret);
}
