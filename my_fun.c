/*
** my_fun.c for  in /home/bernar_4/rendu/PSU_2014_minishell1
** 
** Made by Bernardo Dylan
** Login   <bernar_4@epitech.net>
** 
** Started on  Thu Jan 22 21:39:07 2015 Bernardo Dylan
** Last update Thu Jan 22 21:39:22 2015 Bernardo Dylan
*/


#include <unistd.h>
#include "my_error.h"
#include "minishell1.h"
#include "my_str.h"

void	my_write(const char *str, const char *color)
{
  (void)write(0, color, my_strlen(color));
  (void)write(0, str, my_strlen(str));
  (void)write(0, "\033[0m", my_strlen("\033[0m"));
}


void	my_w(const char *str)
{
  (void)write(0, str, my_strlen(str));
}
