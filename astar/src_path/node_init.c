/*
** node_init.c for dante in /home/alexandre/rendu/2016/CPE/dante/astar/src_path
** 
** Made by Alexandre Tahery
** Login   <alexandre1.tahery@epitech.eu>
** 
** Started on  Fri Apr 28 12:56:27 2017 Alexandre Tahery
** Last update Fri Apr 28 12:56:28 2017 Alexandre Tahery
*/

#include <stdlib.h>
#include "astar.h"

void		init_node(int y, int x, t_data_map *data_map)
{
  if (data_map->array_char[y][x] == CHAR_WALL)
    data_map->array_node[y][x].walk = FALSE;
  else
    data_map->array_node[y][x].walk = TRUE;
  data_map->array_node[y][x].list = NONE_LIST;
  data_map->array_node[y][x].g = 0;
  data_map->array_node[y][x].h = 0;
  data_map->array_node[y][x].f = 0;
  data_map->array_node[y][x].father = NULL;
  data_map->array_node[y][x].list_p = NULL;
  data_map->array_node[y][x].pos.x = x;
  data_map->array_node[y][x].pos.y = y;
}

int		field_node(t_data_map *data_map)
{
  int		count_y;
  int		count_x;

  count_y = 0;
  data_map->y = my_strlen_tab((int **)data_map->array_char);
  data_map->x = my_strlen(data_map->array_char[0]);
  if ((data_map->array_node = malloc(sizeof(t_array_node *) *
				    (data_map->y + 1))) == NULL)
    return (FAIL);
  data_map->array_node[data_map->y] = NULL;
  while (data_map->array_char[count_y] != NULL)
    {
      count_x = 0;
      if ((data_map->array_node[count_y] =
	   malloc(sizeof(t_array_node) * data_map->x)) == NULL)
	return (FAIL);
      while (data_map->array_char[count_y][count_x] != '\0')
	{
	  init_node(count_y, count_x, data_map);
	  count_x += 1;
	}
      count_y += 1;
    }
  return (SUCCESS);
}
