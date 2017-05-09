/*
** init_node.c for dante in /home/alexandre/rendu/2016/CPE/dante/depth_src
** 
** Made by Alexandre Tahery
** Login   <alexandre1.tahery@epitech.eu>
** 
** Started on  Wed Apr 19 12:28:50 2017 Alexandre Tahery
** Last update Fri Apr 28 12:12:24 2017 Alexandre Tahery
*/

#include <stdlib.h>
#include "breadth_dante.h"

void		init_node(int y, int x, t_data_mazes *data_mazes)
{
  if (data_mazes->array_char[y][x] == CHAR_WALL)
    data_mazes->array_node[y][x].walk = FALSE;
  else
    data_mazes->array_node[y][x].walk = TRUE;
  data_mazes->array_node[y][x].visited = NO_VISITED;
  data_mazes->array_node[y][x].pos.x = x;
  data_mazes->array_node[y][x].pos.y = y;
  data_mazes->array_node[y][x].father = NULL;
  data_mazes->array_node[y][x].next = NULL;
}

int		field_node(t_data_mazes *data_mazes)
{
  int		count_y;
  int		count_x;

  count_y = 0;
  data_mazes->y = my_strlen_tab(data_mazes->array_char);
  data_mazes->x = my_strlen(data_mazes->array_char[0]);
  if ((data_mazes->array_node = malloc(sizeof(t_array_node *) *
				    (data_mazes->y + 1))) == NULL)
    return (FAIL);
  data_mazes->array_node[data_mazes->y] = NULL;
  while (data_mazes->array_char[count_y] != NULL)
    {
      count_x = 0;
      if ((data_mazes->array_node[count_y] =
	   malloc(sizeof(t_array_node) * data_mazes->x)) == NULL)
	return (FAIL);
      while (data_mazes->array_char[count_y][count_x] != '\0')
	{
	  init_node(count_y, count_x, data_mazes);
	  count_x += 1;
	}
      count_y += 1;
    }
  return (SUCCESS);
}

void		set_pos(t_data_mazes *data_mazes)
{
  data_mazes->pos_begin.x = 0;
  data_mazes->pos_begin.y = 0;
  data_mazes->pos_end.x = my_strlen(data_mazes->array_char[0]) - 1;
  data_mazes->pos_end.y = my_strlen_tab(data_mazes->array_char) - 1;
  data_mazes->find_path = WAY_NO_FUND;
}
