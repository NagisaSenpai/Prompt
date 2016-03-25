/*
** my_error.h for  in /home/bernar_4/rendu/PSU_2014_minishell1
** 
** Made by Bernardo Dylan
** Login   <bernar_4@epitech.net>
** 
** Started on  Thu Jan 22 21:28:45 2015 Bernardo Dylan
** Last update Thu Jan 22 21:28:59 2015 Bernardo Dylan
*/


#ifndef MY_ERROR_H_
# define MY_ERROR_H_

void	my_puterror(const char *error);
void	my_error(const char *error, const char *var);
char	my_env_error(char *env, char type, int pos);
char	my_cnf(char *cmd);

#endif /* !MY_ERROR_H_ */
