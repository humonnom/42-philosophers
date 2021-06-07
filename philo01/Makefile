NAME		= philo_one

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g
SRCS		=	main.c \
				set_rule_info.c \
				is_invalid.c \
				handle_thread.c \
				gen_philos.c \
				print_philos.c \
				display_err_message.c \
				act_eat.c \
				act_sleep.c \
				act_think.c \
				grab_forks.c \
				release_forks.c \
				get_time.c \
				philo_routine.c \
				display_message.c \
				exit_program.c \
				watch_died_or_done.c \
				# \
				print_forks.c \
				watch_count.c \
				handle_resources.c \


OBJS		= $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

OBJDIR		= ./objs
LIBDIR		= ./libft
LIBFT		= -L./libft -lft

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(MAKE) -C $(LIBDIR) all
			$(CC) $(CFLAGS) -o $(NAME) $(LIBFT) $(OBJS) -lpthread

$(OBJDIR)/%.o:%.c
			@mkdir $(OBJDIR) 2> /dev/null || true
			$(CC) $(CFLAGS) -I./philo_one.h -o $@ -c $<

clean:
			@rm -rf $(OBJDIR) 2> /dev/null || true
			@$(MAKE) -C $(LIBDIR) clean

fclean:		clean
			@rm -rf $(NAME) 2> /dev/null || true
			@$(MAKE) -C $(LIBDIR) fclean

re:			fclean all

test:		re
			@./$(NAME) 4 210 200 200

limit:		re
			@./$(NAME) 4 410 200 200 3

err:		re
			@./$(NAME) 4 200 200 200 -5

.PHONY:		all clean fclean re test err
