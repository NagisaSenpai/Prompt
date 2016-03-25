/*
** my_set_var.h for  in /home/bernar_4/rendu/PSU_2014_minishell1
** 
** Made by Bernardo Dylan
** Login   <bernar_4@epitech.net>
** 
** Started on  Thu Jan 22 21:48:40 2015 Bernardo Dylan
** Last update Thu Jan 22 21:48:50 2015 Bernardo Dylan
*/

#ifndef MY_SET_VAR_H_
# define MY_SET_VAR_H_

# include "my_list.h"

char	*set_my_var(t_list *env, char *code);
char	*set_my_pwd(t_list *env);
void	my_init_env(t_list *lst);

#endif /* !MY_SET_VAR_H_ */
