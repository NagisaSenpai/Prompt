/*
** my_error.c for  in /home/bernar_4/rendu/PSU_2014_minishell1
** 
** Made by Bernardo Dylan
** Login   <bernar_4@epitech.net>
** 
** Started on  Thu Jan 22 21:27:36 2015 Bernardo Dylan
** Last update Thu Jan 22 21:28:25 2015 Bernardo Dylan
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_str.h"


void	my_puterror(const char *error)
{
  (void)write(2, error, my_strlen(error));
  exit(EXIT_FAILURE);
}

void	my_error(const char *error, const char *var)
{
  (void)write(2, var, my_strlen(var));
  (void)write(2, ": ", 3);
  (void)write(2, error, my_strlen(error));
}

char	my_env_error(char *env, char type, int pos)
{
  if (type == 0)
    {
      (void)write(2, "env: invalid option --'", 23);
      (void)write(2, env, my_strlen(env));
      (void)write(2, "'", 1);
    }
  else if (type == 1)
    {
      (void)write(2, "env: invalid option --'", 23);
      (void)write(2, &env[pos], 1);
      (void)write(2, "'", 1);
    }
  else if (type == 2)
    (void)write(2, "env: option requires an argument -- 'u'\n", 40);
  else
    (void)write(2, "env: cannot unset '': Invalid argument\n", 39);
  if (type != 3)
    (void)write(2, "\nTry 'env --help' for more information.\n", 41);
  return (-1);
}

char	my_cnf(char *cmd)
{
  (void)write(2, "If '", 4);
  (void)write(2, cmd, my_strlen(cmd));
  (void)write(2, "' is not a typo you can use command-not-found to lookup", 55);
  (void)write(2, " the package that contains it, like this:\n\tcnf ", 47);
  (void)write(2, cmd, my_strlen(cmd));
  (void)write(2, "\n", 1);
  return (-1);
}
