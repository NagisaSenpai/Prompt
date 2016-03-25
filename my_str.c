/*
** my_str.c for  in /home/bernar_4/rendu/PSU_2014_minishell1
** 
** Made by Bernardo Dylan
** Login   <bernar_4@epitech.net>
** 
** Started on  Thu Jan 22 21:49:14 2015 Bernardo Dylan
** Last update Sat Jan 24 17:10:47 2015 Bernardo Dylan
*/

#include <stdlib.h>
#include "my_error.h"
#include "my_str.h"

char	my_strcmp(const char *s1, const char *s2, char equal)
{
  int	i;

  i = -1;
  while (s1[++i] && s2[i] && s1[i] == s2[i]);
  if (equal)
    return (s1[i] == '=' && s2[i] == '\0');
  return ((s1[i] == s2[i] || s1[i] == ' ' || s1[i] == '\t') && s2[i] == '\0');
}

int	my_strlen(const char *str)
{
  int	i;

  i = -1;
  if (str == NULL)
    return (0);
  while (str[++i]);
  return (i);
}

char    *my_strdup(const char *str)
{
  int   i;
  char  *cpy;

  if ((cpy = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
    my_puterror("error: problem to malloc in my_str.c: l60!\n");
  i = 0;
  while (str[i])
    {
      cpy[i] = str[i];
      ++i;
    }
  cpy[i] = '\0';
  return (cpy);
}

char	*my_strcat(char *dest, const char *src)
{
  int	i;
  int	j;

  i = my_strlen(dest);
  j = -1;
  while (src[++j])
    {
      dest[i] = src[j];
      ++i;
    }
  dest[i] = '\0';
  return (dest);
}
