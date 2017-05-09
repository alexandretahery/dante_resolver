/*
** main.c for dante in /home/alexandre/rendu/2016/CPE/dante/depth_src
** 
** Made by Alexandre Tahery
** Login   <alexandre1.tahery@epitech.eu>
** 
** Started on  Wed Apr 19 09:35:38 2017 Alexandre Tahery
** Last update Fri Apr 28 12:12:24 2017 Alexandre Tahery
*/

#include <stdlib.h>
#include "breadth_dante.h"

void		put_into_char(t_data_mazes *data_mazes)
{
  t_array_node *tmp;

  tmp = &data_mazes->array_node[data_mazes->pos_end.y]
    [data_mazes->pos_end.x];
  while (tmp != NULL)
    {
      data_mazes->array_char[tmp->pos.y][tmp->pos.x] = 'o';
      tmp = tmp->father;
    }
}

t_array_node		*breadth_condition(int x, int y,
					   t_data_mazes *data_mazes,
					   t_array_node *top)
{
  if (x < data_mazes->x &&
      y < data_mazes->y &&
      x >= 0 &&
      y >= 0 &&
      data_mazes->array_node[y][x].visited == NO_VISITED &&
      data_mazes->array_node[y][x].walk == TRUE)
      top = put_end_of_list(top, &data_mazes->array_node[y][x], top);
  return (top);
}

void		breadth(t_data_mazes *data_mazes, t_array_node *top)
{
  int		x;
  int		y;

  x = top->pos.x;
  y = top->pos.y;
  if (data_mazes->find_path == WAY_NO_FUND &&
      top != NULL)
    {
      top = breadth_condition(x + 1, y, data_mazes, top);
      top = breadth_condition(x - 1, y, data_mazes, top);
      top = breadth_condition(x, y + 1, data_mazes, top);
      top = breadth_condition(x, y - 1, data_mazes, top);
      top = delete_begin_of_list(top);
      if (data_mazes->pos_end.x == x && data_mazes->pos_end.y == y)
	data_mazes->find_path = WAY_FUND;
      breadth(data_mazes, top);
    }
}

int		main(int argc, char **argv)
{
  t_data_mazes	data_mazes;

  if (argc == 1)
    return (FAIL);
  if ((data_mazes.array_char = field_char(argv[1])) == NULL
      || field_node(&data_mazes) == FAIL)
    return (FAIL);
  set_pos(&data_mazes);
  data_mazes.array_node[0][0].visited = VISITED;
  breadth(&data_mazes, &data_mazes.array_node[0][0]);
  put_into_char(&data_mazes);
  display_tab(data_mazes.array_char);
  return (SUCCESS);
}
