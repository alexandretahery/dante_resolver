/*
** my_fonc1.c for dante in /home/alexandre/rendu/2016/CPE/dante/astar/src_my
** 
** Made by Alexandre Tahery
** Login   <alexandre1.tahery@epitech.eu>
** 
** Started on  Fri Apr 28 12:55:15 2017 Alexandre Tahery
** Last update Fri Apr 28 12:55:15 2017 Alexandre Tahery
*/

#include <stdlib.h>
#include <unistd.h>
#include "astar.h"

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

int		my_strlen_tab(int **tab)
{
  int		count;

  count = 0;
  while(tab[count] != NULL)
    count += 1;
  return (count);
}
