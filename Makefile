##
## Makefile for  in /home/bernar_4/rendu/PSU_2014_minishell1
## 
## Made by Bernardo Dylan
## Login   <bernar_4@epitech.net>
## 
## Started on  Thu Jan 22 22:56:27 2015 Bernardo Dylan
## Last update Sat Jan 24 17:00:51 2015 Bernardo Dylan
##


CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror -g

LDFLAGS	= -I.

NAME	= mysh

SRCS	= main.c\
	  my_error.c\
	  my_exec.c\
	  my_set_var.c\
	  my_list.c\
	  my_list2.c\
	  my_str.c\
	  my_env.c\
	  my_check.c\
	  my_fun.c\
	  my_pwd.c\
	  my_free.c\
	  my_builtin.c\
	  my_str_to_wordtab.c

OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
