#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
#include <sys/time.h>
# include "libft/libft.h"

//structure
typedef struct			s_rule
{
	uint64_t			time_to_die;
	uint64_t			time_to_eat;
	uint64_t			time_to_sleep;
	int					number_of_philos;
	int					number_of_eat;
	uint64_t			start_time;
}						t_rule;

typedef struct			s_philo
{
	pthread_t			thread;
	pthread_mutex_t		mutex;
	pthread_mutex_t		eat_mutex;
	pthread_mutex_t		*forks;
	int					status;
	int					philo_id;
	uint64_t			eat_start;
	uint64_t			sleep_start;
	int					eat_left;
	int					time_left;
	int					right_fork;
	int					left_fork;
	t_rule				*rule;
}						t_philo;

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

# define TYPE_EAT 0
# define TYPE_SLEEP 1
# define TYPE_THINK 2
# define TYPE_FORK 3
# define TYPE_DIED 4
# define TYPE_NONE 10

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
				t_rule *rule);
int
	handle_resources(t_philo *philos,
					int number_of_philos);


void
	grab_forks(t_philo *philo);

void
	dump_forks(t_philo *philo);

void
	act_eat(t_philo *philo);


void
	act_sleep(t_philo *philo);


void
	act_think(t_philo *philo);

uint64_t
	get_time(void);

void
	*philo_routine(void *arg);

void
	*watch_count(void *arg);

void
	display_message(t_philo *philo, int type);

////////////////////

void
	print_philos(
				t_philo *philos,
				int number_of_philos);
void
    print_forks_status(t_philo *philo, int number_of_philos);

#endif
