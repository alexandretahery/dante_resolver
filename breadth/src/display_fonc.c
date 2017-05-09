/*
** display_fonc.c<src> for dante in /home/alexandre/rendu/2016/CPE/dante/depth_src
** 
** Made by Alexandre Tahery
** Login   <alexandre1.tahery@epitech.eu>
** 
** Started on  Wed Apr 19 12:03:46 2017 Alexandre Tahery
** Last update Fri Apr 28 13:18:18 2017 Alexandre Tahery
*/

#include <stdlib.h>
#include <unistd.h>
#include "breadth_dante.h"

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
