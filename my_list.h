/*
** my_list.h for  in /home/bernar_4/rendu/PSU_2014_minishell1
** 
** Made by Bernardo Dylan
** Login   <bernar_4@epitech.net>
** 
** Started on  Thu Jan 22 21:42:07 2015 Bernardo Dylan
** Last update Thu Jan 22 21:42:48 2015 Bernardo Dylan
*/

#ifndef MY_LIST_H_
# define MY_LIST_H_

typedef struct	s_list
{
  char		*data;
  struct s_list	*next;
  struct s_list	*prec;
}		t_list;

void	my_add_elt(t_list **list, char *val, char *start);
t_list  *my_create_list(char **env);
void	my_remove_elt(t_list **lst, char *value);
void	my_display_lst(t_list *lst, char type);

#endif /* !MY_LIST_H_ */
