/*
** main.c for  in /home/bernar_4/rendu/PSU_2014_minishell1
** 
** Made by Bernardo Dylan
** Login   <bernar_4@epitech.net>
** 
** Started on  Thu Jan 22 21:11:38 2015 Bernardo Dylan
** Last update Sat Jan 24 17:11:52 2015 Bernardo Dylan
*/

#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "minishell1.h"
#include "my_error.h"
#include "my_check.h"
#include "my_fun.h"
#include "my_str_to_wordtab.h"
#include "my_set_var.h"
#include "my_pwd.h"
#include "my_list.h"
#include "my_list2.h"
#include "my_str.h"

static void	my_init(char *str)
{
  int		i;

  i = -1;
  while (++i <= BUFF)
    str[i] = '\0';
}

static void	my_prompt(t_list *env, char change)
{
  char		*pwd;
  char		*user;

  user = set_my_var(env, "USER");
  if (change)
    pwd = set_my_pwd(env);
  else
    pwd = set_my_var(env, "PWD");
  if (user != NULL)
    {
      my_write(user, CYAN);
      my_write("@", BLUE);
    }
  my_write(pwd, GREEN);
  (void)write(0, "\n", 1);
  my_write("$>", RED);
}

static void	my_print(int t)
{
  (void)	t;
  my_write("\n$>", RED);
}

static char	my_signal()
{
  if (signal(SIGINT, my_print) == SIG_ERR)
    my_puterror("error with signal in main.c: l74\n");
  return (0);
}

int		main(int argc, char **argv, char **env)
{
  char		buff[BUFF + 1];
  t_list	*lst;
  int		len;
  int		ret;

  (void)argc;
  (void)argv;
  lst = my_create_list(env);
  my_init_env(lst);
  my_prompt(lst, 1);
  my_init(&buff[0]);
  ret = my_signal();
  while ((len = read(0, buff, BUFF)) > 0)
    {
      if (len == BUFF)
	my_puterror("error: the command is too big!\n");
      buff[len != 0 ? len - 1 : len] = '\0';
      ret = my_check_fun(buff, lst);
      if (ret == 42)
	return (EXIT_SUCCESS);
      my_prompt(lst, ret);
      (void)my_signal();
      my_init(&buff[0]);
    }
  return (len == -1 ? EXIT_FAILURE : EXIT_SUCCESS);
}
