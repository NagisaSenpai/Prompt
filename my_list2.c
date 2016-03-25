/*
** my_list2.c for  in /home/bernar_4/rendu/PSU_2014_minishell1
** 
** Made by Bernardo Dylan
** Login   <bernar_4@epitech.net>
** 
** Started on  Thu Jan 22 21:43:14 2015 Bernardo Dylan
** Last update Thu Jan 22 21:43:45 2015 Bernardo Dylan
*/

#include <stdlib.h>
#include "my_list.h"
#include "my_str.h"

char		*my_find_element(t_list *lst, char *value)
{
  t_list	*tmp;

  tmp = lst->next;
  while (tmp != lst && !my_strcmp(tmp->data, value, 1))
    tmp = tmp->next;
  if (tmp == lst)
    return (NULL);
  return (&tmp->data[my_strlen(value) + 1]);
}

void	my_setenv_lst(t_list *lst, char *var, char *value)
{
  my_remove_elt(&lst, var);
  my_add_elt(&lst, value, var);
}
