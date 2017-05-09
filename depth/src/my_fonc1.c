/*
** my_fonc1.c<src> for dante in /home/alexandre/rendu/2016/CPE/dante/depth_src
** 
** Made by Alexandre Tahery
** Login   <alexandre1.tahery@epitech.eu>
** 
** Started on  Wed Apr 19 10:14:25 2017 Alexandre Tahery
** Last update Wed Apr 19 11:15:57 2017 Alexandre Tahery
*/

#include <unistd.h>
#include <stdlib.h>
#include "depth_dante.h"

int		my_strlen(char *str)
{
  int		count;

  count = 0;
  if (str == NULL)
    return (FAIL_N);
  while (str[count] != '\0')
    count += 1;
  return (count);
}

int		my_strlen_tab(char **tab)
{
  int		count;

  count = 0;
  if (tab == NULL)
    return (FAIL_N);
  while(tab[count] != NULL)
    count += 1;
  return (count);
}
