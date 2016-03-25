/*
** my_pwd.c for  in /home/bernar_4/rendu/PSU_2014_minishell1
** 
** Made by Bernardo Dylan
** Login   <bernar_4@epitech.net>
** 
** Started on  Thu Jan 22 21:44:41 2015 Bernardo Dylan
** Last update Thu Jan 22 23:00:35 2015 Bernardo Dylan
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include "my_str.h"
#include "my_error.h"


static char	*my_find_dir(DIR *dir, struct stat *cur)
{
  struct dirent	*dirent;
  struct stat	tmp;
  int		found;
  char		*foundDir;

  found = 0;
  while (!found && (dirent = readdir(dir)) != NULL)
    {
      if (lstat(dirent->d_name, &tmp) != 0)
	my_puterror("error: unable to use lstat in my_pwd.c: l30!\n");
      if ((tmp.st_dev == cur->st_dev) && (tmp.st_ino == cur->st_ino))
	found = 1;
    }
  if ((foundDir = my_strdup(dirent->d_name)) == NULL)
    my_puterror("error: problem with strdup in my_pwd.c: l37!\n");
  if (closedir(dir) == -1)
    my_puterror("error: problem during closedir in my_pwd.c: l39!\n");
  if (!found)
    my_puterror("error: unable to find the current dir in my_pwd: l41!\n");
  return (foundDir);
}

static DIR	*my_init(struct stat *cur, struct stat *parent)
{
  DIR		*dir;

  if (lstat(".", cur) != 0)
    my_puterror("error: problem with lstat in my_pwd.c: l50!\n");
  chdir("..");
  if (lstat(".", parent) != 0)
    my_puterror("error: problem with lstat in my_pwd.c: l53!\n");
  if (!(dir = opendir(".")))
    my_puterror("error: unable to open the cur dir in my_pwd: l55!\n");
  return (dir);
}

static char*my_new_str(char *foundDir, char *curDir)
{
  int	len;
  int	len2;

  len = my_strlen(curDir);
  if (len != 1)
    curDir = my_strcat(curDir, "/");
  if (foundDir)
    {
      len2 = my_strlen(foundDir);
      if ((len + len2 + 1) > 256)
	my_puterror("error: the path's size is too big in my_pwd.c: l71!\n");
      curDir = my_strcat(curDir, foundDir);
      free(foundDir);
    }
  return (curDir);
}

static char		*my_return_pwd()
{
  struct stat		cur;
  struct stat		parent;
  DIR			*dir;
  char			*curDir;
  char			*foundDir;

  dir = my_init(&cur, &parent);
  if ((cur.st_dev == parent.st_dev) && (cur.st_ino == parent.st_ino))
    {
      if ((curDir = malloc(sizeof(char) * 256)) == NULL)
	my_puterror("error: problem to malloc curDir in my_pwd.c: l92!\n");
      curDir[0] = '\0';
      foundDir = NULL;
    }
  else
    {
      foundDir = my_find_dir(dir, &cur);
      curDir = my_return_pwd();
    }
  return (my_new_str(foundDir, curDir));
}

char		*my_pwd()
{
  char		*pwd;

  pwd = my_return_pwd();
  if (chdir(pwd) == -1)
    my_error("unable to find directory in my_pwd.c: l110\n", "error");
  return (pwd);
}
