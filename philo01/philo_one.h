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
	pthread_mutex_t		write_mutex;
	pthread_mutex_t		check_fork_mutex;
	pthread_mutex_t		*forks;
	uint64_t			time_to_die;
	uint64_t			time_to_eat;
	uint64_t			time_to_sleep;
	uint64_t			start_time;
	int					number_of_philos;
	int					number_of_eat;
	int					*status;
	int					state;
	int					errcode;
}						t_rule;

typedef struct			s_philo
{
	pthread_mutex_t		mutex;
	pthread_mutex_t		eat_mutex;
	pthread_t			thread;
	uint64_t			eat_start;
	uint64_t			time_left;
	int					eat_left;
	int					philo_id;
	int					right_fork;
	int					left_fork;
	int					hands;
	t_rule				*rule;
}						t_philo;

typedef struct			s_info
{
	t_rule				rule;
	t_philo				*philo;
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
# define TYPE_HUNGRY 1
# define TYPE_SLEEP 2
# define TYPE_THINK 3
# define TYPE_FORK 4
# define TYPE_DIED 5
# define TYPE_DONE 6
# define TYPE_NONE 10

# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_BLUE    "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN    "\x1b[36m"
# define ANSI_COLOR_RESET   "\x1b[0m"
//functions
void
	display_err_message(int err_number);

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
	grab_forks(t_philo *philo);

void
	release_forks(t_philo *philo);

int
	act_eat(t_philo *philo);


int
	act_sleep(t_philo *philo);


int
	act_think(t_philo *philo);

uint64_t
	get_time(void);

void
	*philo_routine(void *arg);


int
	display_message(t_philo *philo, int type);

int
	exit_program(t_philo *philo);


void
	*watch_died_or_done(void *arg);

////////////////////

void
	print_philos(
				t_philo *philos,
				int number_of_philos);
void
    print_forks_status(t_philo *philo, int number_of_philos);

#endif
// [trash]
// void
// 	*watch_count(void *arg);

// int
// 	handle_resources(t_philo *philos);

// void
// 	print_forks(t_philo *philo);
