/*
** my_check.c for  in /home/bernar_4/rendu/PSU_2014_minishell1
** 
** Made by Bernardo Dylan
** Login   <bernar_4@epitech.net>
** 
** Started on  Thu Jan 22 21:21:10 2015 Bernardo Dylan
** Last update Thu Jan 22 21:22:35 2015 Bernardo Dylan
*/


#include <unistd.h>
#include <stdlib.h>
#include "my_error.h"
#include "minishell1.h"
#include "my_fun.h"
#include "my_builtin.h"
#include "my_set_var.h"
#include "my_str.h"
#include "my_list.h"
#include "my_list2.h"
#include "my_pwd.h"
#include "my_str_to_wordtab.h"
#include "my_exec.h"
#include "my_free.h"

static int	my_builtin_fun(char **arr, t_list *env)
{
  char		*pwd;

  if (my_strcmp(arr[0], "exit", 0))
    return (my_exit(env, arr));
  else if (my_strcmp(arr[0], "env", 0))
    my_env(env, arr);
  else if (my_strcmp(arr[0], "cd", 0))
    return (my_cd(arr) + 1);
  else if (my_strcmp(arr[0], "pwd", 0))
    {
      pwd = my_find_element(env, "PWD");
      write(1, pwd, my_strlen(pwd));
      write(1, "\n", 1);
      return (1);
    }
  else if (my_strcmp(arr[0], "setenv", 0))
    my_setenv(env, arr);
  else if (my_strcmp(arr[0], "unsetenv", 0))
    my_unsetenv(env, arr);
  else
    return (0);
  return (1);
}

int	my_check_fun(char *str, t_list *env)
{
  char	**arr;
  char	res;

  arr = my_str_to_wordtab(str, ' ', '\t');
  if (arr == NULL || arr[0] == NULL)
    return (0);
  if ((res = my_builtin_fun(arr, env)) != 0)
    {
      if (res != 43)
	my_free_arr(arr);
      return (res - 1);
    }
  else
    (void)my_exec(env, arr, my_find_element(env, "PATH"));
  my_free_arr(arr);
  return (0);
}
