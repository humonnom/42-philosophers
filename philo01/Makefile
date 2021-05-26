NAME		= philo_one

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
SRCS		= main.c print_err_msg.c set_rule_info.c is_invalid.c handle_thread.c
OBJS		= $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

OBJDIR		= ./objs
LIBDIR		= ./libft
LIBFT		= -L./libft -lft

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(MAKE) -C $(LIBDIR) all
			@$(CC) $(CFLAGS) -o $(NAME) $(LIBFT) $(OBJS) -lpthread

$(OBJDIR)/%.o:%.c
			@mkdir $(OBJDIR) 2> /dev/null || true
			@$(CC) -I./philo_one.h -o $@ -c $<

clean:
			@rm -rf $(OBJDIR) 2> /dev/null || true
			@$(MAKE) -C $(LIBDIR) clean

fclean:		clean
			@rm -rf $(NAME) 2> /dev/null || true
			@$(MAKE) -C $(LIBDIR) fclean

re:			fclean all

test:		re
			@./$(NAME) 4 200 200 200

err:		re
			@./$(NAME) 4 200 200 200 -5

.PHONY:		all clean fclean re test err