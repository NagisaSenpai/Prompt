/*
** my_list.c for  in /home/bernar_4/rendu/PSU_2014_minishell1
** 
** Made by Bernardo Dylan
** Login   <bernar_4@epitech.net>
** 
** Started on  Thu Jan 22 21:40:37 2015 Bernardo Dylan
** Last update Sat Jan 24 20:58:01 2015 Bernardo Dylan
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_str.h"
#include "my_list.h"
#include "my_list2.h"
#include "my_error.h"

void		my_add_elt(t_list **list, char *val, char *start)
{
  t_list	*new;
  int		i;
  int		j;
  int		size;

  if ((new = malloc(sizeof(*new))) == NULL)
    my_puterror("error: problem to malloc the t_list in my_list.c: l30!\n");
  size = (start != NULL) ? my_strlen(start) : 0;
  if ((new->data = malloc(sizeof(char) * (size + my_strlen(val) + 2))) == NULL)
    my_puterror("error: problem to malloc in my_list.c: l33!\n");
  j = -1;
  i = -1;
  while (start != NULL && start[++i])
    new->data[++j] = start[i];
  i = -1;
  if (j != -1)
    new->data[++j] = '=';
  while (val[++i])
    new->data[++j] = val[i];
  new->data[++j] = '\0';
  new->prec = (*list)->prec;
  new->next = (*list);
  (*list)->prec->next = new;
  (*list)->prec = new;
}


t_list		*my_create_list(char **env)
{
  t_list	*root;
  int		i;

  if ((root = malloc(sizeof(*root))) == NULL)
    my_puterror("error: problem to malloc the t_list in my_list.c: l60!\n");
  root->next = root;
  root->prec = root;
  i = -1;
  while (env[++i])
    my_add_elt(&root, env[i], NULL);
  return (root);
}

void		my_remove_elt(t_list **lst, char *value)
{
  t_list	*tmp;

  tmp = (*lst)->next;
  while (tmp != (*lst) && !my_strcmp(tmp->data, value, 1))
    tmp = tmp->next;
  if (tmp != (*lst))
    {
      tmp->prec->next = tmp->next;
      tmp->next->prec = tmp->prec;
      free(tmp);
    }
}

void		my_display_lst(t_list *lst, char type)
{
  t_list	*tmp;

  tmp = lst->next;
  while (tmp != lst)
    {
      (void)write(1, tmp->data, my_strlen(tmp->data));
      if ((type != 1 && tmp->next != lst) || type == 0)
	(void)write(1, "\n", 1);
      tmp = tmp->next;
    }
}

