/*
** f_little.c for dante in /home/alexandre/rendu/2016/CPE/dante/astar/src_path
** 
** Made by Alexandre Tahery
** Login   <alexandre1.tahery@epitech.eu>
** 
** Started on  Fri Apr 28 12:55:57 2017 Alexandre Tahery
** Last update Fri Apr 28 12:55:57 2017 Alexandre Tahery
*/

#include <math.h>
#include <stdlib.h>
#include "astar.h"

static int			init_f_little(t_data_map *data_map)
{
  t_array_node			*tmp;
   int				f_little;

   tmp = data_map->open_list;
   f_little = -1;
   while (tmp != NULL)
     {
       if (tmp->list == OPEN_LIST)
	 {
	   f_little = tmp->f;
	   return (f_little) ;
	}
      tmp = tmp->list_p;
    }
   return (-1);
}

int			find_little_f(t_data_map *data_map)
{
   t_array_node		*tmp;
   int			f_little;

   tmp = data_map->open_list;
   f_little = init_f_little(data_map);
   while (tmp != NULL)
     {
       if (tmp->list == OPEN_LIST)
	 {
	   if (f_little > tmp->f)
	     f_little = tmp->f;
	}
      tmp = tmp->list_p;
    }
   if (f_little == -1)
     return (FAIL);
   else
     return (f_little);
}
