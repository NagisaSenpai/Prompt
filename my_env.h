/*
** my_env.h for  in /home/bernar_4/rendu/PSU_2014_minishell1
** 
** Made by Bernardo Dylan
** Login   <bernar_4@epitech.net>
** 
** Started on  Thu Jan 22 21:26:32 2015 Bernardo Dylan
** Last update Thu Jan 22 21:27:06 2015 Bernardo Dylan
*/

#ifndef MY_ENV_H_
# define MY_ENV_H_

# define ID_IGNORE	0
# define ID_NULL	1
# define ID_UN		2
# define ID_HELP	3
# define ID_VER		4

# include "my_list.h"

# define UNSET(c)(c != '\0' && c != '\'')

char	my_env_opt(t_list *env, char **var);

#endif /* !MY_ENV_H_ */
