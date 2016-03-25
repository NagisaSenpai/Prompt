/*
** my_builtin.c for  in /home/bernar_4/rendu/PSU_2014_minishell1
** 
** Made by Bernardo Dylan
** Login   <bernar_4@epitech.net>
** 
** Started on  Thu Jan 22 23:02:37 2015 Bernardo Dylan
** Last update Thu Jan 22 23:03:12 2015 Bernardo Dylan
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_env.h"
#include "my_error.h"
#include "my_str.h"
#include "my_list.h"
#include "my_list2.h"
#include "my_str_to_wordtab.h"
#include "my_free.h"


char    my_exit(t_list *env, char **arr)
{
  my_free_arr(arr);
  my_free_lst(env);
  return (43);
}

int     my_cd(const char **arr)
{
  if (arr[1] != NULL)
    {
      if (access(arr[1], F_OK) == -1)
        {
          my_error("no such file or directory: ", "cd");
          (void)write(2, arr[1], my_strlen(arr[1]));
          (void)write(2, "\n", 1);
          return (0);
        }
      if (access(arr[1], R_OK) == -1)
        {
          my_error("permission denied: ", "cd");
          (void)write(2, arr[1], my_strlen(arr[1]));
          (void)write(2, "\n", 1);
          return (0);
        }
      if (chdir(arr[1]) == -1)
        {
          my_error("you cannot access to this directory\n", "cd");
          return (0);
        }
      return (1);
    }
  my_error("usage: cd directory\n", "cd");
  return (0);
}

void    my_setenv(t_list *env, char **arr)
{
  if (arr[1] != NULL && arr[2] != NULL)
    my_setenv_lst(env, arr[1], arr[2]);
  else
    my_error("usage: setenv VARIABLE VALUE\n", "setenv");
}

void    my_unsetenv(t_list *lst, char **arr)
{
  if (arr[1] != NULL)
    my_remove_elt(&lst, arr[1]);
  else
    my_error("usage: unsetenv VARIABLE\n", "unsetenv");
}

void    my_env(t_list *env, char **options)
{
  my_env_opt(env, options);
}
