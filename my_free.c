/*
** my_free.c for  in /home/bernar_4/rendu/PSU_2014_minishell1
** 
** Made by Bernardo Dylan
** Login   <bernar_4@epitech.net>
** 
** Started on  Thu Jan 22 23:01:24 2015 Bernardo Dylan
** Last update Thu Jan 22 23:01:30 2015 Bernardo Dylan
*/

#include <stdlib.h>
#include "my_list.h"

void    my_free_arr(char **arr)
{
  int   i;

  i = -1;
  if (arr != NULL)
    {
      while (arr[++i] != NULL)
        free(arr[i]);
      free(arr);
    }
}

void            my_free_lst(t_list *list)
{
  t_list        *tmp;
  t_list        *next;

  tmp = list->next;
  while (tmp != list)
    {
      next = tmp->next;
      free(tmp->data);
      free(tmp);
      tmp = next;
    }
  free(list);
}
