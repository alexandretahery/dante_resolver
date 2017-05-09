/*
** main.c for dante in /home/alexandre/rendu/2016/CPE/dante/astar/src_path
** 
** Made by Alexandre Tahery
** Login   <alexandre1.tahery@epitech.eu>
** 
** Started on  Fri Apr 28 12:56:16 2017 Alexandre Tahery
** Last update Fri Apr 28 12:56:16 2017 Alexandre Tahery
*/

#include <stdlib.h>
#include <math.h>
#include "astar.h"

void		put_into_char(t_data_map *data_mazes)
{
  t_array_node *tmp;

  tmp = &data_mazes->array_node[data_mazes->pos_end[Y_POS]]
    [data_mazes->pos_end[X_POS]];
  while (tmp != NULL)
    {
      data_mazes->array_char[tmp->pos.y][tmp->pos.x] = 'o';
      tmp = tmp->father;
    }
}

int			main(int argc, char **argv)
{
  t_data_map		data_map;

  if ((data_map.array_char = field_char(argv[1])) == NULL
      || field_node(&data_map) == FAIL)
    return (FAIL);
  set_pos(&data_map);
  data_map.open_list = NULL;
  data_map.way = NULL;
  data_map.array_node[data_map.pos_begin[Y_POS]]
    [data_map.pos_begin[X_POS]].list = CLOSE_LIST;
  a_star(&data_map);
  put_into_char(&data_map);
  display_tab(data_map.array_char);
  return (SUCCESS);
}
