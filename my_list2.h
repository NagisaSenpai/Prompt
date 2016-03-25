/*
** my_list2.h for  in /home/bernar_4/rendu/PSU_2014_minishell1
** 
** Made by Bernardo Dylan
** Login   <bernar_4@epitech.net>
** 
** Started on  Thu Jan 22 21:44:05 2015 Bernardo Dylan
** Last update Thu Jan 22 21:44:14 2015 Bernardo Dylan
*/

#ifndef MY_LIST2_H_
# define MY_LIST2_H_

# include "my_list.h"

char	*my_find_element(t_list *lst, char *value);
void	my_setenv_lst(t_list *lst, char *var, char *value);

#endif /* !MY_LIST2_H_ */
