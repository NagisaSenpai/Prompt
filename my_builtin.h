/*
** my_builtin.h for  in /home/bernar_4/rendu/PSU_2014_minishell1
** 
** Made by Bernardo Dylan
** Login   <bernar_4@epitech.net>
** 
** Started on  Thu Jan 22 23:00:02 2015 Bernardo Dylan
** Last update Thu Jan 22 23:00:06 2015 Bernardo Dylan
*/

#ifndef MY_BUILTIN_H_
# define MY_BUILTIN_H_

# include "my_list.h"

char    my_exit(t_list *env, char **arr);
int     my_cd(char **arr);
void    my_setenv(t_list *env, char **arr);
void    my_unsetenv(t_list *env, char **arr);
void    my_env(t_list *env, char **options);

#endif /* !MY_BUILTIN_H_ */
