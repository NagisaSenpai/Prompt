/*
** my_set_var.c for  in /home/bernar_4/rendu/PSU_2014_minishell1
** 
** Made by Bernardo Dylan
** Login   <bernar_4@epitech.net>
** 
** Started on  Thu Jan 22 21:47:48 2015 Bernardo Dylan
** Last update Thu Jan 22 21:48:19 2015 Bernardo Dylan
*/

#include <stdlib.h>
#include "minishell1.h"
#include "my_fun.h"
#include "my_str.h"
#include "my_error.h"
#include "my_list.h"
#include "my_pwd.h"
#include "my_list2.h"

char	*set_my_var(t_list *env, char *code)
{
  char	*var;

  var = my_find_element(env, code);
  return (var);
}

char	*set_my_pwd(t_list *env)
{
  char	*pwd;

  pwd = my_pwd();
  my_setenv_lst(env, "PWD", pwd);
  return (pwd);
}

void	my_init_env(t_list *lst)
{
  char	*path;

  my_setenv_lst(lst, "_", ENV);
  path = set_my_var(lst, "PATH");
  if (path == NULL)
    {
      my_setenv_lst(lst, "PATH", PATH);
      path = PATH;
    }
}
