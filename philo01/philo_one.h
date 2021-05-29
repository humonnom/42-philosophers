#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include "libft/libft.h"

//structure
typedef struct			s_philo
{
	pthread_t			thread;
	pthread_mutex_t		mutex;
	int					philo_id;
	int					eat_start;
	int					sleep_start;
	int					eat_count;
	int					time_left;
	int					right_fork;
	int					left_fork;
}						t_philo;

typedef struct			s_rule
{
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_philos;
	int					number_of_eat;
}						t_rule;

typedef struct			s_info
{
	t_rule				rule;
	t_philo				*philo;
	int					errcode;
}						t_info;

//macro

# define INVALID_ARGC 1
# define FAIL_MALLOC 2
# define INVALID_RULE 3
# define INVALID_PHILOS_NUM 200
# define INVALID_TIME_SET 60
# define INVALID_EAT_NUM -1

# define UNDECIDED_EAT_NUM 5
# define DECICED_EAT_NUM 6

# define UNDECIDED 0

//functions
void
	print_err_msg(int err_number);

int
	is_invalid_arg_num(int argc);

int
	set_rule_info(
				t_rule *rule,
				char **info_str,
				int arg_num);

int
	handle_thread(t_info *info);

int
	is_invalid_rule(t_rule *rule);

int
	gen_philos(
				t_philo **philos_head,
				int number_of_philos);

int
	handle_resources(t_philo *philos);

void
	print_philos(
				t_philo *philos,
				int number_of_philos);


void
	eat(int time);

#endif
