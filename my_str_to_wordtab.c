/*
** my_str_to_wordtab.c for  in /home/bernar_4/rendu/PSU_2014_minishell1
** 
** Made by Bernardo Dylan
** Login   <bernar_4@epitech.net>
** 
** Started on  Thu Jan 22 22:53:23 2015 Bernardo Dylan
** Last update Thu Jan 22 22:55:29 2015 Bernardo Dylan
*/

#include <stdlib.h>
#include "my_error.h"
#include "my_fun.h"

static int	my_strlen(const char *str, char end, char end1)
{
  int		i;

  i = -1;
  while (str[++i] && str[i] != end && str[i] != end1);
  return (i);
}

static	int	my_nbr_words(const char *str, char end, char end1)
{
  int		i;
  int		count;

  i = 0;
  count = 0;
  while (str[i] != '\0')
    {
      while (str[i] && (str[i] == end || str[i] == end1))
	++i;
      count = (str[i] && str[i] != end && str[i] != end1) ? count + 1 : count;
      while (str[i] && str[i] != end && str[i] != end1)
	++i;
      i = str[i] == '\0' ? i : i + 1;
    }
  return (count);
}

static	int	my_strdup(char *cpy, const char *src, char end, char end1)
{
  int		i;
  int		j;

  i = -1;
  j = 0;
  while (src[j] && (src[j] == end || src[j] == end1))
    ++j;
  while (src[j] && src[j] != end && src[j] != end1)
    {
      cpy[++i] = src[j];
      j++;
    }
  cpy[++i] = '\0';
  return (j);
}

char		**my_str_to_wordtab(char *path, char end, char end1)
{
  char		**array;
  int		size;
  int		i;
  int		j;

  size = my_nbr_words(path, end, end1);
  if (size == 0)
    return (NULL);
  if ((array = malloc(sizeof(char *) * (size + 1))) == NULL)
    my_puterror("error: problem to malloc array in my_str_to_wordtab.c: l91\n");
  i = 0;
  j = -1;
  while (path[i])
    {
      if ((array[++j] = malloc(sizeof(char) * my_strlen(&path[i], end, end1)))
	  == NULL)
	my_puterror("error: problem to malloc in my_str_to_wordtab.c: l98!\n");
      i += my_strdup(array[j], &path[i], end, end1);
      i = (path[i] == '\0') ? i : i + 1;
    }
  array[++j] = NULL;
  return (array);
}
