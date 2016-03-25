/*
** my_exec.c for  in /home/bernar_4/rendu/PSU_2014_minishell1
** 
** Made by Bernardo Dylan
** Login   <bernar_4@epitech.net>
** 
** Started on  Thu Jan 22 21:29:38 2015 Bernardo Dylan
** Last update Thu Jan 22 22:59:15 2015 Bernardo Dylan
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my_str_to_wordtab.h"
#include "my_list.h"
#include "my_str.h"
#include "my_error.h"
#include "my_free.h"


static char	**my_conv_lst(t_list *env)
{
  t_list	*tmp;
  char		**arr;
  int		i;
  int		count;

  count = 0;
  if (env == NULL)
    return (NULL);
  tmp = env->next;
  while (tmp != env)
    {
      ++count;
      tmp = tmp->next;
    }
  if ((arr = malloc(sizeof(char *) * (count + 1))) == NULL)
    my_puterror("error: problem to malloc in my_exec.c: l30\n");
  i = -1;
  tmp = env->next;
  while (tmp != env)
    {
      arr[++i] = my_strdup(tmp->data);
      tmp = tmp->next;
    }
  arr[++i] = NULL;
  return (arr);
}

static char	*my_pathfile(char *path, char *exec)
{
  char		*res;
  int		len;
  int		size;

  len = my_strlen(path);
  size = (path[len - 1] == '/') ? len : len + 1;
  if ((res = malloc(sizeof(char) * (size + my_strlen(exec) + 1))) == NULL)
    my_puterror("error: problem to malloc in my_exec.c: l56\n");
  res[0] = '\0';
  res = my_strcat(res, path);
  if (len != size)
    res[len] = '/';
  res[size] = '\0';
  res = my_strcat(res, exec);
  return (res);
}

static char	my_goodpath(char *str)
{
  int		i;
  char		path_bin;

  i = -1;
  path_bin = 0;
  while (str[++i] && path_bin == 0)
    if (str[i] == '/')
      path_bin = 1;
  return (path_bin);
}

static char	*my_access(char *str, char *path)
{
  char		**arr;
  int		i;
  char		*exec;

  if (my_goodpath(str))
    return ((access(str, F_OK | X_OK) == -1) ? NULL : str);
  arr = my_str_to_wordtab(path, ':', ':');
  i = -1;
  while (arr[++i] != NULL)
    {
      exec = my_pathfile(arr[i], str);
      if (access(exec, F_OK | X_OK) != -1)
	{
	  my_free_arr(arr);
	  return (exec);
	}
      free(exec);
    }
  return (NULL);
}

char	my_exec(t_list *env, char **exec_opt, char *path)
{
  pid_t	pid;
  int	statut;
  char	**my_env;
  char	*exec;

  my_env = my_conv_lst(env);
  pid = fork();
  if (pid == -1)
    {
      my_error("impossible to find the son for fork!\n", "fork");
      return (1);
    }
  else if (pid == 0)
    {
      if ((exec = my_access(exec_opt[0], path)) == NULL ||
	  execve(exec, exec_opt, my_env) == -1)
	{
	  my_free_arr(my_env);
	  return (my_cnf((exec == NULL) ? exec_opt[0] : exec));
	}
    }
  else
    wait(&statut);
  my_free_arr(my_env);
  return (0);
}
