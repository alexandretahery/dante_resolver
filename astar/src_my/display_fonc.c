/*
** display_fonc.c for dante in /home/alexandre/rendu/2016/CPE/dante/astar/src_my
** 
** Made by Alexandre Tahery
** Login   <alexandre1.tahery@epitech.eu>
** 
** Started on  Fri Apr 28 12:55:03 2017 Alexandre Tahery
** Last update Fri Apr 28 13:23:50 2017 Alexandre Tahery
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "astar.h"

void		display_tab(char **map)
{
  int		count;

  count = 0;
  while (map[count] != NULL)
    {
      write(1, map[count], my_strlen(map[count]));
      write(1, "\n", 1);
      count += 1;
    }
}
